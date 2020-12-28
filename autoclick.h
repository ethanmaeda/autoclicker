#ifndef AUTOCLICK_H
#define AUTOCLICK_H

#include <windows.h>

int main();
void click();
unsigned int randomdelay(unsigned int mincps, unsigned int maxcps);
void sync_options();
void printkeyname(UINT keycode);

#endif
