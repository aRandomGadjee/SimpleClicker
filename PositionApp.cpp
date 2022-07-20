#include <iostream>
#include "windows.h"
// basic file operations
#include <fstream>
using namespace std;
// arg:0 exe, arg:1 pos x, arg:2 pos y, arg:3 mouseclick
// if no args are specified, get current mouse position and return it
int main(int argc, char** argv)
{
    //testing
	cout << "You have entered " << argc
		<< " arguments:" << "\n";
    
    //Code
    short x;
    short y;
    short mouseEvent;
    if (argv[1]==NULL) //no args specified, set position and inform
    {
        POINT point;
	    if (GetCursorPos(&point)) {
            x=point.x;
            y=point.y;
        }
        ofstream myfile;
        myfile.open ("CursorPosition.txt");
        myfile << "PossitionApp.exe [x] [y] [1=Left click / 2=Right click]" << "\n" << "x=" << x << "\n" << "y=" << y;
        myfile.close();
        return 99; //return something
    }

    if (argv[1]!=NULL && argv[2]!=NULL && argv[3]!=NULL)
    {    
        try //try to convert
        {
            // doesnt look great... but it works
            // we're using strtoul( const char *str, char **str_end, int base )
            // passing in "1234" and converting it to a uShort(long) grim
            x = (unsigned short) strtoul(argv[1], NULL, 0);
            y = (unsigned short) strtoul(argv[2], NULL, 0);
            mouseEvent= (unsigned short) strtoul(argv[3], NULL, 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

	COORD pos = { x, y };
	SetCursorPos(pos.X, pos.Y);

    switch (mouseEvent)
    {
    case 1:
        	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        break;
    case 2:
        	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        break;
    default:
        break;
    }
    return 0;
}