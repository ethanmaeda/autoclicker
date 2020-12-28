#include <windows.h>
#include <iostream>
#include <random>
#include <fstream>
#include <cassert>
#include "autoclick.h"

using namespace std;

// Global variables
UINT onoffkey{ 0x4F };
UINT holdkey{ 0x47 };
unsigned int flucfactor{10};
unsigned int mincps{10};
unsigned int maxcps{20};
bool ON{ false };

int main() {
	cout << "\nEthan's Randomized AutoClicker\n";
	cout << "---------------------------------------------------------------------\n\n";

	sync_options();

	cout << "ON/OFF key: ";
	printkeyname(onoffkey);
	cout << "\n";
	cout << "Hold key: ";
	printkeyname(holdkey);
	cout << "\n";
	cout << "Fluctuation factor (1-10): " << dec << flucfactor << "\n";
	cout << "CPS range: " << mincps << "-" << maxcps << "\n\n";
	cout << "---------------------------------------------------------------------\n\n";
	cout << "Press your ON/OFF key to turn the autoclicker on and off\n";
	cout << "Exit console to terminate the program\n";
	cout << "---------------------------------------------------------------------\n\n";

	unsigned int delay{ randomdelay(mincps, maxcps) };
	unsigned int counter{};

	while (true) {
		if (GetAsyncKeyState(onoffkey) < 0) {
			ON = true;
			cout << "\rAutoClicker is ON ";
			Sleep(200);
		}

		while (ON) {
			if (counter == flucfactor) {
				delay = randomdelay(mincps, maxcps);
				counter = 0;
			}
			if (GetAsyncKeyState(holdkey) < 0) {
				click();
				Sleep(delay);
			}
			if (GetAsyncKeyState(onoffkey) < 0) {
				ON = false;
				cout << "\rAutoClicker is OFF";
				Sleep(200);
			}
			counter += 1;
		}
	}
	return 0;
}

void click() {
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

unsigned int randomdelay(unsigned int mincps, unsigned int maxcps) {
	return 1000/(rand() % (maxcps-mincps+1)+mincps);
}

void sync_options() {
	ifstream file;
	file.open("options.txt");

	if (file.is_open()) {
		cout << "Options file loaded \n";
		cout << "---------------------------------------------------------------------\n\n";
		file >> hex >> onoffkey >> holdkey >> dec >> flucfactor >> mincps >> maxcps;
		file.close();
	}
	else {
		cout << "Options file not loaded \n";
		cout << "Using default settings \n";
		cout << "---------------------------------------------------------------------\n\n";
	}

	assert(onoffkey != 0);
	assert(holdkey != 0);
	assert(flucfactor >= 0 && flucfactor <= 10);
	assert(mincps > 0 && mincps < 50 && mincps<=maxcps);
	assert(maxcps < 50 && maxcps > 0 && maxcps>=mincps);
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