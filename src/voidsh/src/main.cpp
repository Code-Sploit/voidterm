#include "../include/configP.h"
#include "../include/getInput.h"
#include "../include/exec.h"

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
        // CREATE OBJECTS
        input gInput;
        exec Exec;
        parser ParseHandler;

        // DEFINE VARIABLES
        const char *home_path = getenv("HOME");
        string home_path_string = string(home_path);

        home_path_string.append("/.config/voidterm/shell.conf");

        string configFile = home_path_string;
        string command_prompt = ParseHandler.GetPromptValue(configFile);
        string autostart = ParseHandler.GetAutoStartValue(configFile);

        if (autostart == "NA") {
                // Do something to pass if-else
                string randomStringValue = "value";
        }
        else
        {
                system(autostart.c_str());
        }

        // LEX INPUT
        while (1) {
                string command = gInput.Prompt(command_prompt);
                if (command.find("void") == 0) {
                        exit(EXIT_SUCCESS);
                }
                else if(command.find("cd") == 0) {
                        string params = command.substr(command.find(" ") + 1);
                        chdir(params.c_str());
                }
                else
                {
                        Exec.RunCommand(command);
                }
        }

        return 0;
}
