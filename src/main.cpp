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

#include <iostream>
#include <fstream>
#include <string>

#include "qtermwidget.h"
#include "../include/configP.h"

using namespace std;

void setShell(string shellname) {
        const char *converted_shellname = shellname.c_str();
        setenv("SHELL", converted_shellname, 2);
}

main(int argc, char *argv[]) {
        QApplication app(argc, argv);
        QMainWindow *mainWindow = new QMainWindow();
        const QString fonttype = QString::fromStdString(getFontTypeValue("/home/skyfight/.config/leafterm/leafterm.conf"));
        setenv("TERM", "konsole-256color", 1);
        setShell(getDefaultShellValue("/home/skyfight/.config/leafterm/leafterm.conf"));
        QTermWidget *console = new QTermWidget();

        QFont font = QApplication::font();
        font.setFamily(fonttype);
        font.setPointSize(getFontSizeValue("/home/skyfight/.config/leafterm/leafterm.conf"));

        // Set Configured settings
        console->setColorScheme(getColorSchemeValue("/home/skyfight/.config/leafterm/leafterm.conf"));
        console->setTerminalOpacity(getOpacityValue("/home/skyfight/.config/leafterm/leafterm.conf"));
        console->setScrollBarPosition(QTermWidget::ScrollBarRight);

        // Launch the terminal && define keybindings
        QObject::connect(console, &QTermWidget::termKeyPressed, mainWindow,
                        [=](const QKeyEvent *key) -> void {
                        if (key->matches(QKeySequence::Copy)) {
                                console->copyClipboard();
                        }
                        else if (key->matches(QKeySequence::Paste)) {
                                console->pasteClipboard();
                        }
                        else if (key->matches(QKeySequence::Quit)) {
                                exit(0);
                        }});
        QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));

        mainWindow->setCentralWidget(console);

        mainWindow->show();
        return app.exec();
}
