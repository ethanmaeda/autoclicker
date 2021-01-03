Ethan's Randomized AutoClicker
- Autoclicker with randomized delays to simulate human clicking
- (cps = clicks per second)

*****IMPORTANT*****
- The max cps is limited to 50 cps due to the nature of inaccuracies beyond 50 cps (it's not like you'll need it anyway) 
  Inputting any values higher than 50 will abort the program, also making the min cps higher than the max will also abort the program

- The autoclicker will rarely reach the min and max cps, but will almost always be within the range

- Refer to https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes if you want to rebind the hold and ON/OFF keys
  YOU MUST USE THE HEX VALUES e.g If you want to bind the control key, in options.txt you must put 0x11, not VK_CONTROL

- By default, the ON/OFF key is O and the hold key is G

- MOST keys should work when binding
 
*****INSTRUCTIONS*****
If you want to modify values/keybinds, the values in the options.txt are as follows:

1st line: ON/OFF key
- Key to turn the autoclicker on and off

2nd line: Hold key 
- Key to hold to click real fast

3rd line: Fluctuation factor 
-Affects the cps fluctuation frequency
	0-no fluctuation (NO RANDOM)
	1-10 (1=very frequent, 10=not as frequent) **(factor of 10 seems the most human-like to me)

4th line: Minimum cps	|
			|-- Self explanatory	
5th line: Maximum cps	|
