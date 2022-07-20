#Simple, fast positional clicker
***
##What?
A very simple script to left or right click predefined coordinates
---
##Why?
Why not?
---
##How to use this:
###Compiling:
As this is C++ we must first compile this to a .exe. This article, [Compiling a Native C++ Program on the Command Line]( https://docs.microsoft.com/en-us/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-170 “Walkthrough: Compiling a Native C++ Program on the Command Line”), will show you how to compile C++. You will need to include the library in the compiler command, as the below example shows:
```Powershell
C:\SimpleClicker > cl /EHsc PositionApp.cpp User32.lib
```
Once compiled, run this from a terminal.

###Arguments:
The script takes 3 arguments: position x (int), position y (int) and mouse action (int). Specifying x and y coordinates will tell the program where to place the cursor; the ‘mouse action’ can be either a Left Click (1) or a Right Click (2).
For example the below will place the cursor in the top right corner and Left click:
```Powershell
C:\SimpleClicker > PositionApp 30 30 1
```
If no arguments are supplied, we expect that this is the first run and you won’t know what coordinates to use; when run with no arguments, a text file is generated with the current position of the cursor. This file is saved in the same directory as the .exe.
**You must either provide all 3 arguments or no arguments**
_idc, fight me_
