#include <sstream>
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include "../include/fallbacks.h"
#include "configP.h"

using namespace std;
using namespace fallbacks;

bool checkOpacity(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool opacity = false;
                string line;
                while (getline(cfile, line)) {
                        if (line.find("opacity") == 0) {
                                return true;
                        }
                        else{
                                continue;
                        }
                }
                if (opacity == false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}

float getOpacityValue(string filename) {
        if (checkOpacity(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        float opacityV = 0.0;
                        string line;
                        while (getline(cfile, line)) {
                                if (line.find("opacity") == 0){
                                        string output2 = line.substr(line.find("=") + 1);
                                        float output3 = stof(output2);
                                        return output3;
                                }
                                else{
                                        continue;
                                }
                        }
                        return ::opacity;
                }
                else
                {
                        return ::opacity;
                }
        }
        else
        {
                return ::opacity;
        }
        return ::opacity;
}

bool checkColorScheme(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool opacity = false;
                string line;
                while (getline(cfile, line)) {
                        if (line.find("color_scheme") == 0) {
                                return true;
                        }
                        else{
                                continue;
                        }
                }
                if (opacity == false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}

QString getColorSchemeValue(string filename) {
        if (checkColorScheme(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        string line;
                        while (getline(cfile, line)) {
                                if (line.find("color_scheme") == 0){
                                        string output2 = line.substr(line.find("=") + 1);;
                                        QString output3 = QString::fromStdString(output2);
                                        return output3;
                                }
                                else{
                                        continue;
                                }
                        }
                        return ::colorScheme;
                }
                else
                {
                        return ::colorScheme;
                }
        }
        else
        {
                return ::colorScheme;
        }
}

bool checkFontSize(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool fontsize = false;
                string line;
                while (getline(cfile, line)) {
                        if (line.find("font_size") == 0) {
                                return true;
                        }
                        else
                        {
                                continue;
                        }
                }
                if (fontsize == false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}


int getFontSizeValue(string filename) {
        if (checkFontSize(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        string line;
                        while (getline(cfile, line)) {
                                if (line.find("font_size") == 0){
                                        int output2 = stoi(line.substr(line.find("=") + 1));
                                        return output2;
                                }
                                else{
                                        continue;
                                }
                        return ::fontsize;
                        }
                }
                else
                {
                        return ::fontsize;
                }
        }
        else
        {
                return ::fontsize;
        }
        return ::fontsize;
}

bool checkFontType(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool fonttype = false;
                string line;
                while (getline(cfile, line)) {
                        if (line.find("font_type") == 0) {
                                return true;
                        }
                        else
                        {
                                continue;
                        }
                }
                if (fonttype == false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}

string getFontTypeValue(string filename) {
        if (checkFontType(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        string line;
                        while (getline(cfile, line)) {
                                if (line.find("font_type") == 0){
                                        string output2 = line.substr(line.find("=") + 1);;
                                        return output2;
                                }
                                else{
                                        continue;
                                }
                        }
                        return ::fonttype;
                }
                else
                {
                        return ::fonttype;
                }
        }
        else
        {
                return ::fonttype;
        }
}

bool checkDefaultShell(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool defaultshell = false;
                string line;
                while (getline(cfile, line)) {
                        if (line.find("default_shell") == 0) {
                                return true;
                        }
                        else
                        {
                                continue;
                        }
                }
                if (defaultshell == false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}

string getDefaultShellValue(string filename) {
        if (checkDefaultShell(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        string line;
                        while (getline(cfile, line)) {
                                if (line.find("default_shell") == 0) {
                                        string output2 = line.substr(line.find("=") + 1);
                                        return output2;
                                }
                                else
                                {
                                        continue;
                                }
                        }
                        return ::defaultshell;
                }
                else
                {
                        return ::defaultshell;
                }
        }
        else
        {
                return ::defaultshell;
        }
}

bool checkBoldFont(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool boldfont = false;
                string line;
                while (getline(cfile, line)) {
                        if (line.find("bold_font") == 0) {
                                return true;
                        }
                        else
                        {
                                continue;
                        }
                }
                if (boldfont = false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}

bool getBoldFontValue(string filename) {
        if (checkBoldFont(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        bool boldfont = false;
                        string line;
                        while (getline(cfile, line)) {
                                if (line.find("bold_font") == 0) {
                                        string output2 = line.substr(line.find("=") + 1);
                                        if (output2 == "true") {
                                                return true;
                                        }
                                        else
                                        {
                                                return false;
                                        }
                                }
                                else
                                {
                                        continue;
                                }
                        }
                        return boldfont;
                }
                else
                {
                        return ::boldfont;
                }
        }
        else
        {
                return ::boldfont;
        }
        return false;
}

bool checkTerm(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool term = false;
                string line;
                while (getline(cfile, line)) {
                        if (line.find("termenv") == 0) {
                                return true;
                        }
                        else
                        {
                                continue;
                        }
                }
                if (term == false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}

string getTermValue(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                string line;
                while (getline(cfile, line)) {
                        if (line.find("termenv") == 0) {
                                string output2 = line.substr(line.find("=") + 1);
                                return output2;
                        }
                        else
                        {
                                continue;
                        }
                }
                return ::term;
        }
        else
        {
                return ::term;
        }
}

bool checkEditor(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool term = false;
                string line;
                while (getline(cfile, line)) {
                        if (line.find("editor") == 0) {
                                return true;
                        }
                        else
                        {
                                continue;
                        }
                }
                if (term == false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}

string getDefaultEditorValue(string filename) {
        if (checkEditor(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        string line;
                        while (getline(cfile, line)) {
                                if (line.find("editor") == 0) {
                                        string output2 = line.substr(line.find("=") + 1);
                                        return output2;
                                }
                                else
                                {
                                        continue;
                                }
                        }
                        return ::editor;
                }
                else
                {
                        return ::editor;
                }
        }
        else
        {
                return ::editor;
        }
}

bool checkItalicFont(string filename) {
        fstream cfile;
        cfile.open(filename, ios::in);

        if (cfile.is_open()) {
                bool italicfont = false;
                string line;
                while(getline(cfile, line)) {
                        if (line.find("italic_font") == 0) {
                                return true;
                        }
                        else
                        {
                                continue;
                        }
                }
                if (italicfont == false) {
                        return false;
                }
        }
        else
        {
                return false;
        }
        return false;
}

bool getItalicFontValue(string filename) {
        if (checkItalicFont(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        string line;
                        while(getline(cfile, line)) {
                                if (line.find("italic_font") == 0) {
                                        string output2 = line.substr(line.find("=") + 1);
                                        if (output2 == "true") {
                                                return true;
                                        }
                                        else
                                        {
                                                return false;
                                        }
                                }
                                else
                                {
                                        continue;
                                }
                        }
                        return ::italicfont;
                }
                else
                {
                        return ::italicfont;
                }
        }
        else
        {
                return ::italicfont;
        }
}
