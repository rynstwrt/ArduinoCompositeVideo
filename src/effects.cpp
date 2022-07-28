// #include <Arduino.h>
// #include <../lib/TVout-master/TVout.h>
// #include <../lib/TVoutfonts/fontALL.h>
// #include <string.h>
// #include <musicnotes.h>
// #include <bitmaps/furrypic.h>


// #define SCREEN_RESOLUTION_HORIZ 128
// #define SCREEN_RESOLUTION_VERT 96


// const static unsigned char* FONT = font4x6;
// const static unsigned char* HEADER_FONT = font8x8;

// static int xCenter;
// static int yCenter;


// TVout tv;


// void setup()
// {
// 	tv.begin(NTSC, SCREEN_RESOLUTION_HORIZ, SCREEN_RESOLUTION_VERT);
// 	tv.select_font(FONT);

// 	xCenter = (tv.hres() - 1) / 2;
// 	yCenter = (tv.vres() - 1) / 2;
// }


// void drawBorder()
// {
// 	tv.clear_screen();

// 	tv.draw_row(0, 0, tv.hres() - 1, 1);
// 	tv.draw_row(tv.vres() - 1, 0, tv.hres() - 1, 1);
// 	tv.draw_column(0, 0, tv.vres() - 1, 1);
// 	tv.draw_column(tv.hres() - 1, 0, tv.vres() - 1, 1);

// 	tv.delay(1000);
// }


// void alternateCircleRectangle()
// {
// 	tv.clear_screen();
// 	drawBorder();
// 	tv.delay(100);

// 	tv.clear_screen();
// 	tv.draw_circle((tv.hres() - 1) / 2, (tv.vres() - 1) / 2, 10, 1);
// 	tv.delay(100);
// }


// void displayCenterText(String text)
// {
// 	tv.clear_screen();

// 	int textLen = text.length();
// 	int textWidth;
// 	int textHeight;

// 	if (FONT == font4x6)
// 	{
// 		textWidth = textLen * 4;
// 		textHeight = 6;
// 	}
	
// 	tv.println((tv.hres() - 1) / 2 - textWidth / 2, (tv.vres() - 1) / 2 - textHeight / 2, text.c_str());

// 	tv.delay(1000);
// }


// void pixelByPixel()
// {
// 	tv.clear_screen();

// 	for(int x = 0; x < tv.hres(); x++)
// 	{
// 		for(int y = 0; y < tv.vres(); y++)
// 		{
// 			tv.set_pixel(x, y, 1);
// 			tv.delay(1);
// 		}
// 	}

// 	tv.delay(1000);
// }


// void randomLines()
// {
// 	tv.clear_screen();

// 	int startX = random(0, tv.hres());
// 	int startY = random(0, tv.vres());

// 	int endX = random(0, tv.hres());
// 	int endY = random(0, tv.vres());

// 	tv.draw_line(startX, startY, endX, endY, 1);

// 	tv.delay(100);
// }


// bool borderShown = false;
// void randomLinesAndBlinkBorder()
// {
// 	tv.clear_screen();

// 	if (borderShown == false)
// 	{
// 		tv.draw_row(0, 0, tv.hres() - 1, 1);
// 		tv.draw_row(tv.vres() - 1, 0, tv.hres() - 1, 1);
// 		tv.draw_column(0, 0, tv.vres() - 1, 1);
// 		tv.draw_column(tv.hres() - 1, 0, tv.vres() - 1, 1);
// 		borderShown = true;
// 	}
// 	else
// 	{
// 		borderShown = false;
// 	}

// 	int startX = random(0, tv.hres());
// 	int startY = random(0, tv.vres());

// 	int endX = random(0, tv.hres());
// 	int endY = random(0, tv.vres());

// 	tv.draw_line(startX, startY, endX, endY, 1);

// 	tv.delay(100);
// }


// void randomCircleSizes()
// {
// 	tv.clear_screen();

// 	tv.draw_circle(xCenter, yCenter, (int) (random(0, tv.vres() / 2)), 1);

// 	int startX = random(0, tv.hres());
// 	int startY = random(0, tv.vres());

// 	int endX = random(0, tv.hres());
// 	int endY = random(0, tv.vres());

// 	tv.draw_line(startX, startY, endX, endY, 1);

// 	tv.delay(10);
// }


// double* polarToCartesian(double radius, double theta, double *arr)
// {
// 	arr[0] = radius * cos(theta); // x
// 	arr[1] = radius * sin(theta); // y

// 	return arr;
// }


// int radarDegree = 0;
// void radar(int radius)
// {
// 	tv.delay(100);

// 	tv.clear_screen();

// 	double arr[2];
// 	double* xAndY = polarToCartesian(radius, radarDegree, arr);
// 	int x = xAndY[0];
// 	int y = xAndY[1];

// 	tv.draw_circle(xCenter, yCenter, radius, 1);
// 	tv.draw_line(xCenter, yCenter, xCenter + x, yCenter + y, 1);

// 	++radarDegree;

// 	if (radarDegree >= 360)
// 		radarDegree = 0;
// }


// int toneFreq;
// void toneScale(int startFreq, int maxFreq, int duration)
// {
// 	if (!toneFreq)
// 		toneFreq = startFreq;

// 	tv.tone(toneFreq, duration);
// 	tv.delay(duration);
	
// 	++toneFreq;

// 	if (toneFreq >= maxFreq)
// 		toneFreq = startFreq;
// }


// bool shouldShowCursor = true;
// void centeredTypeCursorText(String text, const unsigned char* font)
// {
// 	tv.clear_screen();

// 	int textLen = text.length();
// 	int fontWidth;
// 	int fontHeight;
// 	int textWidth;

// 	if (font == font4x6)
// 	{
// 		fontWidth = 4;
// 		fontHeight = 6;
// 	}
// 	else if (font == font8x8)
// 	{
// 		fontWidth = 8;
// 		fontHeight = 8;
// 	}

// 	textWidth = textLen * fontWidth;

// 	tv.println(xCenter - textWidth / 2, yCenter - fontHeight / 2, text.c_str());
	
// 	if (shouldShowCursor)
// 		tv.draw_rect(xCenter + textWidth / 2, yCenter - fontHeight / 2, fontWidth, fontHeight, 1, 1);

// 	shouldShowCursor = !shouldShowCursor;
// 	tv.delay(750);
// }


// void nightSky(int numStars, int delay, const unsigned char* font)
// {
// 	tv.clear_screen();
// 	tv.select_font(font);

// 	for (int i = 0; i < numStars; ++i)
// 	{
// 		int x = random(0, tv.hres());
// 		int y = random(0, tv.vres() - 20);
// 		unsigned char text = '*';
// 		tv.print_char(x, y, text);
// 	}

// 	tv.draw_circle(tv.hres() - 20, 20, 15, 1, 1);
// 	tv.draw_rect(0, tv.vres() - 20, tv.hres(), 20, 1, 1);

// 	tv.delay(delay);
// }


// void jingle(int duration)
// {
// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(C4, duration * 4);
// 	tv.delay(duration * 4);


// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(B3, duration * 4);
// 	tv.delay(duration * 4);


// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(A3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(C4, duration * 4);
// 	tv.delay(duration * 4);


// 	tv.tone(B3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(B3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(B3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(B3, duration * .75);
// 	tv.delay(duration);

// 	tv.tone(E4, duration * 4);
// 	tv.delay(duration * 4);
// }


// void typeText(String text, const unsigned char* font, int delay)
// {
// 	tv.clear_screen();
// 	tv.select_font(font);
// 	tv.set_cursor(xCenter - text.length() * 8, yCenter - 8);

// 	text = " " + text;

// 	for (int i = 0; i < text.length(); ++i)
// 	{
// 		tv.print(text[i]);
// 		tv.delay(delay);
// 	}
// }


// void loop() 
// {
// 	//drawBorder();

// 	//alternateCircleRectangle();

// 	//displayCenterText("This is a sample string.");

// 	//pixelByPixel();
	
// 	//randomLinesAndBlinkBorder();

// 	//randomCircleSizes();

// 	//radar(20);

// 	//toneScale(200, 300, 100);

// 	//nightSky(10, 250, FONT);

// 	//jingle(250);

// 	//typeText(">PROPAGANDA", HEADER_FONT, 100);

// 	// tv.bitmap(0, 0, furryPic);
// 	// tv.delay(1000);
// }