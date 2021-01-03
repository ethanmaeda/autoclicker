#include <windows.h>
#include <iostream>
#include <random>
#include <fstream>
#include <cassert>
#include "autoclick.h"

using namespace std;

// Global variables
UINT holdkey{ 0x47 };
unsigned int avgdelay{70};

int main() {
	cout << "\nEthan's Personal Randomized AutoClicker\n";
	cout << "---------------------------------------------------------------------\n\n";

	sync_options();

	cout << "Hold key: ";
	printkeyname(holdkey);
	cout << "\n";
	cout << "Average delay between clicks: " << avgdelay << " milliseconds\n\n";
	cout << "---------------------------------------------------------------------\n\n";
	cout << "The program is now running\n";
	cout << "Exit console to terminate the program\n";
	cout << "---------------------------------------------------------------------\n\n";

	unsigned int delay{ avgdelay };
	unsigned int counter{};

	while (1) {
		if (counter == 20) {
			delay = randomdelay(avgdelay);
			counter = 0;
		}
		if (GetAsyncKeyState(holdkey) < 0) {
			click();
			Sleep(delay);
			counter += 1;
		}
	}
	return 0;
}

void click() {
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

unsigned int randomdelay(unsigned int avgdelay) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<unsigned int> dist(avgdelay-10, avgdelay+10);
	return dist(mt);
}

void sync_options() {
	ifstream file;
	file.open("options.txt");

	if (file.is_open()) {
		cout << "Options file loaded \n";
		cout << "---------------------------------------------------------------------\n\n";
		file >> hex >> holdkey >> dec >> avgdelay;
		file.close();
	}
	else {
		cout << "Options file not loaded \n";
		cout << "Using default settings \n";
		cout << "---------------------------------------------------------------------\n\n";
	}

	assert(holdkey != 0);
	assert(avgdelay > 10);
}

void printkeyname(UINT keycode) {
	CHAR keyname[1024];
	UINT scanCode = MapVirtualKeyA(keycode, MAPVK_VK_TO_VSC);
	LONG lParamValue = (scanCode << 16);
	int result = GetKeyNameTextA(lParamValue, keyname, 1024);
	if (result > 0)
	{
		cout << keyname;
	}
}