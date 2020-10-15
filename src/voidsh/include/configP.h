#include <fstream>
#include <iostream>

using namespace std;

class parser {
        private:
                typedef string file;

                const char *username = getenv("LOGNAME");

                const string autostart = "NA";
                const string default_prompt = string(username) + " >>> ";

        protected:
                bool checkPrompt(file filename) {
                        fstream cfile;
                        cfile.open(filename, ios::in);

                        if (cfile.is_open()) {
                                return true;
                        }
                        else
                        {
                                return false;
                        }
                }

                bool checkAutostart(file filename) {
                        fstream cfile;
                        cfile.open(filename, ios::in);

                        if (cfile.is_open()) {
                                return true;
                        }
                        else
                        {
                                return false;
                        }
                }

        public:
                string GetPromptValue(file filename) {
                        if (checkPrompt(filename) == 1) {
                                fstream cfile;
                                cfile.open(filename, ios::in);

                                string line;
                                while(getline(cfile, line)) {
                                        if (line.find("d_prompt") == 0) {
                                                string value = line.substr(line.find(":") + 1);
                                                return value;
                                        }
                                        else
                                        {
                                                continue;
                                        }
                                }
                                return default_prompt;
                        }
                        else
                        {
                                return default_prompt;
                        }
                }

                string GetAutoStartValue(file filename) {
                        if (checkPrompt(filename) == 1) {
                                fstream cfile;
                                cfile.open(filename, ios::in);

                                string line;
                                while(getline(cfile, line)) {
                                        if (line.find("autostart") == 0) {
                                                string value = line.substr(line.find(":") + 1);
                                                return value;
                                        }
                                        else
                                        {
                                                continue;
                                        }
                                }
                                return autostart;
                        }
                        else
                        {
                                return autostart;
                        }
                }
};
