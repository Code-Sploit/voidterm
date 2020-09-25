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
#include "../include/menus.h"

using namespace std;

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
	// Define configfile path
	string configfile = getenv("HOME");
	configfile.append("/.config/leafterm/leafterm.conf");

	// Define mainWindows
	QApplication app(argc, argv);
	QMainWindow *mainWindow = new QMainWindow();
 	
	// Define some extra strings
	const QString fonttype = QString::fromStdString(getFontTypeValue(configfile));
	
	// Set ENV variables
	setTerm(getTermValue(configfile));
	setShell(getDefaultShellValue(configfile));
	setEditor(getDefaultEditorValue(configfile));
	
	// Define console
	QTermWidget *console = new QTermWidget();
	
	// Set font
	QFont font = QApplication::font();
	
	font.setFamily(fonttype);
	font.setPointSize(getFontSizeValue(configfile));
	font.setBold(getBoldFontValue(configfile));
	font.setItalic(getItalicFontValue(configfile));
	
	// Set Configured settings
	console->setColorScheme(getColorSchemeValue(configfile));
	console->setTerminalFont(font);
	console->setScrollBarPosition(QTermWidget::ScrollBarRight);
	console->setTerminalOpacity(getOpacityValue(configfile));
	
	// Menu bar
	QMenuBar *menuBar = new QMenuBar(mainWindow);
	QMenu *actionsMenu = new QMenu("Actions", menuBar);
	
	if (checkForActionMenu(configfile) == 1) {
		menuBar->addMenu(actionsMenu);
		actionsMenu->addAction("Find..", console, SLOT(toggleShowSearchBar()), QKeySequence(Qt::CTRL, Qt::SHIFT, Qt::Key_F));
		mainWindow->setMenuBar(menuBar);
	}
	else
	{
		// Do something in the else statement
		string randomStringValue = "test";
	}
	
	
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
