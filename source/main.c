// Include libraries
#include <stdbool.h>
#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(int argc, char* argv[])
{
using namespace std;
freopen( "output.txt", "w", stdout );
freopen( "error.txt", "w", stderr );

cout << "Output message" << endl;
cerr << "Error message" << endl;
}
//This include a header containing definitions of our image
#include "ImageTest_bin.h"
int random, math, Over_9000, Over_9000_count
;int main(int argc, char **argv)
{
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	//We don't need double buffering in this example. In this way we can draw our image only once on screen.
	gfxSetDoubleBuffering(GFX_BOTTOM, false);

	//Get the bottom screen's frame buffer
	u8* fb = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
	
	//Copy our image in the bottom screen's frame buffer
	memcpy(fb, ImageTest_bin, ImageTest_bin_size);
	//gfxSet3D(true); //Uncomment if using stereoscopic 3D
	
	
	Over_9000_count = 0
	;math = 12/2*20-10
	// Main loop
	;while (aptMainLoop())
	{
		
	
		
		

		//Your code goes here
		Over_9000 = rand() % 9002;
		random = rand() % 1001;
		;u32 kDown = hidKeysDown();
		//Clear the screen
		if (kDown & KEY_A + KEY_B + KEY_X + KEY_Y + KEY_START + KEY_L + KEY_R + KEY_ZL + KEY_ZR + KEY_DOWN + KEY_UP + KEY_LEFT)
			consoleClear();
		//Text triggered by a button
		;if (kDown & KEY_A)
			printf("Hello There")
		;if (kDown & KEY_B)
			printf("You look fabulous")
		;if (kDown & KEY_X)	
			printf("Do you want coffee")
		;if (kDown & KEY_Y)
			printf("My body is Reggie")
		//Test variables
		;if (kDown & KEY_UP)
			printf("Your lucky number is:")
		;if (kDown & KEY_UP)
			printf("%d\n", random);
		;if (kDown & KEY_DOWN)
			printf("This is math test. 12/2*20-10=")
		;if (kDown & KEY_DOWN)
			printf("%d\n", math)
		;if (kDown & KEY_LEFT)
			printf("%d\n", Over_9000);
		;if (kDown & KEY_ZL + KEY_ZR)
			printf("Bravo! You found the secret text")
		;if (kDown & KEY_L)
		{//Print current time
		;while (aptMainLoop())
		{time_t unixTime = time(NULL);
		hidScanInput();
		;u32 kDown = hidKeysDown();
		
		struct tm* timeStruct = gmtime((const time_t *)&unixTime);

		int hours = timeStruct->tm_hour;
		int minutes = timeStruct->tm_min;
		int seconds = timeStruct->tm_sec;
		int day = timeStruct->tm_mday;
		int month = timeStruct->tm_mon;
		int year = timeStruct->tm_year +1900;

		printf("\x1b[0;0H%02i:%02i:%02i", hours, minutes, seconds);
		printf("\x1b[1;0H%02i/%02i/%04i", day, month, year);
		
		}}
		
		;if (kDown & KEY_START + KEY_R)	
			printf("Goodbye")
		;if (kDown & KEY_START + KEY_R)	
			break;
		
		;gfxFlushBuffers();
		;gfxSwapBuffers();
		//Wait for VBlank
		gspWaitForVBlank();
	}
	;gfxExit();
	return 0 ;
	
}