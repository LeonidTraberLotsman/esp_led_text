#include "web.h"

#define NUM_LEDS 768
#define DATA_PIN 2
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

#define snake false
 

String A_letter =
(String)""+
"  +  " +
" + + " +
"+   +" +
"+   +" +
"+++++" +
"+   +" +
"+   +" +
"     ";

#include "alphabet.h"

class Letter {

};


class pixel
{
public:
	int x = 0;
	int y = 0;

	pixel(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int led_num() {
		
		

		int result = -1;

		int o_y = 16 - y;
		result += o_y * 16;
		if (o_y % 2 == 0) {
			result += x;
		}
		else {
			result += (17-x);
		}
		
		return result;
	}
};

void pr(String text) {
	Serial.print(text);
}

void matrixSetup() {
	FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

	Serial.begin(9600);
	pr("started");

	Connect_to_network();

}

void TurnPixel(pixel that_pixel, CHSV color);

void ShowLetter(String symbol,pixel start) 
{
	for (int i = 0; i < 40; i++)
	{
		int line = i / 5;
		int row = i - line * 5;
		pixel that_pixel = pixel(row+ start.x, line+ start.y);
		if(symbol[i]==' ')
		TurnPixel(that_pixel, CHSV(0, 0, 0));
		else TurnPixel(that_pixel, CHSV(95, 255, 255));

		/*Serial.print("line: ");
		Serial.print(line);
		Serial.print(", row: ");
		Serial.print(row);
		Serial.print(", letter:");
		Serial.println(symbol[i]);*/
		

	}
	FastLED.show();
	delay(4);
}

void TurnPixel(pixel that_pixel, CHSV color)
{
	//Serial.println(that_pixel.led_num());
	leds[that_pixel.led_num()] = color;;
	//leds[that_pixel.led_num()] = CRGB::Purple;
}

void ChessBoard() {
	for (byte j = 1; j < 17; j++)
		for (byte i = 1; i < 17; i++)
		{
			pixel pixel1 = pixel(i, j);
			if ((i + j) % 2 == 0) {
				TurnPixel(pixel1, CHSV(255, 255, 255));
			}
			else {
				TurnPixel(pixel1, CHSV(95, 255, 255));
			}

		}

	/*pixel pixel2 = pixel(1, 1);
	TurnPixel(pixel2, CHSV(0, 255, 0));*/
	FastLED.show();
	delay(4);
}
void diagonal() {
	for (byte i = 1; i < 17; i++)
	{
		pixel pixel1 = pixel(i, i);
		
			TurnPixel(pixel1, CHSV(255, 255, 255));
		
			
		

	}
	FastLED.show();
	delay(4);
}

void ShowLetterAtPosition(int line,int  row,String letter) {
	int x = 1;
	if (line == 2)x = 8;
	int y = 1 + 8 * (row-1);
	ShowLetter(letter, pixel(x, y));//first place
}

void test_text() {
	//ShowLetter(A_letter, pixel(1, 1));//first place
	//ShowLetter(A_letter, pixel(8, 1));//same line, a bit righter
	//ShowLetter(A_letter, pixel(1, 9));//bit lower
	for (int i= 'a'; i < 'z'+1; i++)
	{
		//ShowLetterAtPosition((1+i-'a')%7, 1, lett(i));
		ShowLetterAtPosition(3, 1, lett(i));
		delay(1000);
	}
	
	

}
void matrixLoop() {
#if !snake
	test_text();
#endif

#if snake
	for (int i = 0; i < NUM_LEDS; i++) {
		// Turn the LED on, then pause
		leds[i] = CRGB::White;
		FastLED.show();
		delay(5);
	}
	for (int i = 0; i < NUM_LEDS; i++) {
		// Turn the LED on, then pause
		leds[i] = CRGB::Black;
		FastLED.show();
		delay(5);
	}
#endif
}


