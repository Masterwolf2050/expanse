//----------------------------------------------//
//      This is the Expanse Game Project        //
//                      2017                    //
//              Maintainer/s: Dale Kipple       //
//----------------------------------------------//

//Includes
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <menu.h>


//Declerations


//Functions


// Clean up escape key codes so that they work correctly.
char kb_cleanup(char);
// Place menu options correctly on the screen and don't
// display options that go beyond the vertical edges
// Options may be no more than 30 characters long
// Must be counted 1..10
// Must contin a shortcut remembering that it may only require two keys
// Shortcuts go in instructions & help files not on the main interface
// This will be removed if the menu library does it's job
void CenterLeftJustify(int sHeight, int sWidth, int totalOptions, char *option[]);

int curses_main()
{
	int kb_press = 0;
	//int m_location[2][2];
	struct winsize crs_winSz;
	// This will get the dimensions of the screen, should be handled by
	// A function for continuous update or display will be incorrect if
	// window is resized. Only needs to be done once if in terminal.
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &crs_winSz);

	initscr();
	raw();
	timeout(0);
	//keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	noecho();

	clear();

	while(kb_press != 27)
	{
		//Remember mvprintw and other mv functions in curses are always written (columns, rows) or (y,x)
		mvprintw((crs_winSz.ws_row-2),2, "Press escape to leave!");
		//mvprintw(1,1,"%c",kb_press);
		refresh();
		kb_press = kb_cleanup(getch());
//		signal(SIGINT, signalHandler);

	}
	endwin();
	return 0;
}

char kb_cleanup(char key)
{
	int kbhit = 0;
	if(key == 27)
		{
			if(getch() == -1) return 27;
			return kbhit;
		}
		
	return 0;
}

void CenterLeftJustify(int sHeight, int sWidth, int totalOptions, char *option[])
{
	
}
