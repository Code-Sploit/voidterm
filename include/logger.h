#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class Logger {
        private:
                string logPath = "/tmp/voidterm-log";

                string mainAction = "[MAIN]";

                bool checkLogDir() {
                        fstream ofile;
                        ofile.open("/tmp/voidterm-log/testing.txt", ios::out);

                        if (ofile.is_open()) {
                                return true;
                        }
                        else
                        {
                                return false;
                        }
                        return false;
                        ofile.close();
                        system("rm -rf /tmp/voidterm-log/testing.txt");
                }

        protected:
                string GetTimeDate() {
                        time_t now = time(0);
                        char *dt = ctime(&now);
                        string time = string(dt);

                        time.erase(remove(time.begin(), time.end(), '\n'),
                                           time.end());

                        time.append(" :");

                        return time;
                }

        public:
                void log(string message, int log_type) {
                        bool ld_exists = false;

                        fstream cfile;
                        cfile.open(logPath + "/voidterm.log", ios::app);

                        if (checkLogDir()) {
                                ld_exists = true;
                        }
                        else
                        {
                                ld_exists = false;
                                system("mkdir /tmp/voidterm-log");
                        }

                        if (log_type == 0) {
                                cfile << GetTimeDate() << mainAction << " !INFO! " << message << endl;
                        }
                        else if (log_type == 1) {
                                cfile << GetTimeDate()  << mainAction << " !WARNING! " << message << endl;
                        }
                        else if (log_type == 2) {
                                cfile << GetTimeDate()  << mainAction << " !ERROR! " << message << endl;
                        }
                        else if (log_type == 3) {
                                cfile << GetTimeDate()  << mainAction << " !FATAL! " << message << endl;
                        }
                }
}
