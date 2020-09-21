#include <sstream>
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

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
                        return opacityV;
                }
        }
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
}

QString getColorSchemeValue(string filename) {
        if (checkColorScheme(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        QString colorScheme = "Aco";
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
                        return colorScheme;
                }
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

}


int getFontSizeValue(string filename) {
        if (checkFontSize(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        int fontsize = 13;
                        string line;
                        while (getline(cfile, line)) {
                                if (line.find("font_size") == 0){
                                        int output2 = stoi(line.substr(line.find("=") + 1));;
                                        return output2;
                                }
                                else{
                                        continue;
                                }
                        return fontsize;
                        }
                }
        }
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
}

string getFontTypeValue(string filename) {
        if (checkFontType(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        string fonttype = "Monospace";
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
                        return fonttype;
                }
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
}

string getDefaultShellValue(string filename) {
        if (checkDefaultShell(filename) == 1) {
                fstream cfile;
                cfile.open(filename, ios::in);

                if (cfile.is_open()) {
                        string defaultshell = "/bin/bash";
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
                        return defaultshell;
                }
                else
                {
                        string defaultshell = "/bin/bash";
                        return defaultshell;
                }
        }
        else
        {
                string defaultshell = "/bin/bash";
                return defaultshell;
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
}

bool getBoldFontValue(string filename) {
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
                bool boldfont = false;
                return boldfont;
        }
}
