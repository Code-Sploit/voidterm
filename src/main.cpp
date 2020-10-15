#include <QTabWidget>
#include <QApplication>
#include <QKeySequence>
#include <QMainWindow>
#include <QtDebug>
#include <QProcess>
#include <QShortcut>
#include <QMenu>
#include <QAction>
#include <QDesktopServices>
#include <QMenuBar>
#include <QIcon>

#include <iostream>
#include <fstream>
#include <string>

#include "qtermwidget.h"

#include "configP.h"
#include "menus.h"

#include "../include/logger.h"

using namespace std;
using namespace menus;

void setShell(string shellname) {
        const char *converted_shellname = shellname.c_str();
        setenv("SHELL", converted_shellname, 2);
}

void setTerm(string termvalue) {
        const char *converted_termvalue = termvalue.c_str();
        setenv("TERM", converted_termvalue, 2);
}

void setEditor(string editorvalue) {
        const char *converted_editorvalue = editorvalue.c_str();
        setenv("EDITOR", converted_editorvalue, 3);
}

main(int argc, char *argv[]) {

        // Create objects to Classes
        Logger log;

        // Define configfile path
        string configfile = getenv("HOME");
        configfile.append("/.config/voidterm/voidterm.conf");

        // Define mainWindow
        QApplication app(argc, argv);
        QMainWindow *mainWindow = new QMainWindow();

        // Define some extra strings
        const QString fonttype = QString::fromStdString(getFontTypeValue(configfile));

        // Set ENV variables
        setTerm(getTermValue(configfile));
        setShell(getDefaultShellValue(configfile));
        setEditor(getDefaultEditorValue(configfile));

        log.log("Setted ENV variables.", 0);

        // Define console
        QTermWidget *console = new QTermWidget();

        // Set font
        QFont font = QApplication::font();

        font.setFamily(fonttype);
        font.setPointSize(getFontSizeValue(configfile));
        font.setBold(getBoldFontValue(configfile));
        font.setItalic(getItalicFontValue(configfile));

        log.log("Setted font.", 0);

        // Set Configured settings
        console->setColorScheme(getColorSchemeValue(configfile));
        console->setTerminalFont(font);
        console->setScrollBarPosition(QTermWidget::ScrollBarRight);
        console->setTerminalOpacity(getOpacityValue(configfile));

        log.log("Setted console settings", 0);


        // Resize to resonable window size
        mainWindow->resize(1000, 1000);

        log.log("Resized terminal to: 1000, 1000", 0);

        // Menu bar
        QMenuBar *menuBar = new QMenuBar(mainWindow);
        QMenu *actionsMenu = new QMenu("Actions", menuBar);

        if (checkForActionMenu(configfile) == 1) {
                menuBar->addMenu(actionsMenu);
                actionsMenu->addAction("Find..", console, SLOT(toggleShowSearchBar()), QKeySequence(Qt::CTRL, Qt::SHIFT, Qt::Key_F));
                mainWindow->setMenuBar(menuBar);

                log.log("Added action menu", 0);
        }
        else
        {
                // Do something in the else statement
                string randomStringValue = "value";
        }

        // Launch the terminal && define keybindings
        QObject::connect(console, &QTermWidget::termKeyPressed, mainWindow,
                        [=](const QKeyEvent *key) -> void {
                        if (key->matches(QKeySequence::Copy)) {
                                console->copyClipboard();
                                log.log("User used copy shortcut (Ctrl-C).", 0);
                        }
                        else if (key->matches(QKeySequence::Paste)) {
                                console->pasteClipboard();
                                log.log("User used paste shortcut (Ctrl-V).", 0);
                        }
                        else if (key->matches(QKeySequence::Quit)) {
                                log.log("Voidterm exited.", 0);
                                exit(0);
                        }});
        QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));

        mainWindow->setCentralWidget(console);

        mainWindow->show();
        return app.exec();
}
