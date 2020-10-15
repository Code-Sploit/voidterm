#include <iostream>
#include <QApplication>

using namespace std;

extern bool checkOpacity(string filename);
extern float getOpacityValue(string filename);
extern bool checkColorScheme(string filename);
extern QString getColorSchemeValue(string filename);
extern bool checkFontSize(string filename);
extern int getFontSizeValue(string filename);
extern bool checkFontType(string filename);
extern string getFontTypeValue(string filename);
extern bool checkDefaultShell(string filename);
extern string getDefaultShellValue(string filename);
extern bool checkBoldFont(string filename);
extern bool getBoldFontValue(string filename);
extern bool checkTerm(string filename);
extern string getTermValue(string filename);
extern bool checkEditor(string filename);
extern string getDefaultEditorValue(string filename);
extern bool checkItalicFont(string filename);
extern bool getItalicFontValue(string filename);
