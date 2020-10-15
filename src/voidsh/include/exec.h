#include <iostream>

using namespace std;

class exec {
        public:
                void RunCommand(string command) {
                        system(command.c_str());
                }
};
