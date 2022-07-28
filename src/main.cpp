#include <Arduino.h>
#include <../lib/TVout-master/TVout.h>
#include <../lib/TVoutfonts/fontALL.h>
#include <string.h>


#define SCREEN_RESOLUTION_HORIZ 128
#define SCREEN_RESOLUTION_VERT 96


const static unsigned char* FONT = font4x6;
const static unsigned char* HEADER_FONT = font8x8;

static int xCenter;
static int yCenter;


TVout tv;


void setup()
{
	Serial.begin(500000);

	tv.begin(NTSC, SCREEN_RESOLUTION_HORIZ, SCREEN_RESOLUTION_VERT);
	tv.select_font(FONT);

	xCenter = (tv.hres() - 1) / 2;
	yCenter = (tv.vres() - 1) / 2;
}



/*
UP =0
DOWN =1
LEFT =2
RIGHT =3
*/

void loop()
{
	tv.clear_screen();

	tv.draw_row(0, 0, tv.hres(), 1);
	tv.draw_row(tv.vres() - 1, 0, tv.hres(), 1);
	tv.draw_column(0, 0, tv.vres(), 1);
	tv.draw_column(tv.hres() - 1, 0, tv.vres(), 1);

	for (int i = 0; i < tv.hres(); ++i)
	{
		int y = yCenter + sin(i / 10) * 5;
		tv.set_pixel(i, y, 1);
	}

	tv.delay(1000);
	//tv.shift(100, 0);
}