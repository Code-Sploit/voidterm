#include <iostream>

using namespace std;

class input {
        public:
                string Prompt(string prompt) {
                        string var;

                        cout << prompt;
                        getline(cin, var);

                        return var;
                }
};
