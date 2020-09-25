#include <iostream>
#include <fstream>

#include "menufallbacks.h"

using namespace std;

bool checkActionMenu(string filename) {
	fstream cfile;
	cfile.open(filename, ios::in);
	
	if (cfile.is_open()) {
		string line;
		while (getline(cfile, line)) {
			if (line.find("actions_menu") == 0) {
				return true;
			}
			else
			{
				continue;
			}
		}
		return ::actionsmenu;
	}
	return ::actionsmenu;
}

bool checkForActionMenu(string filename) {
	if (checkActionMenu(filename) == 1) {
		fstream cfile;
		cfile.open(filename, ios::in);
		
		if (cfile.is_open()) {
			string line;
			while (getline(cfile, line)) {
				if (line.find("actions_menu") == 0) {
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
		}
		else
		{
			return ::actionsmenu;
		}
	}
	else
	{
		return ::actionsmenu;
	}
}
