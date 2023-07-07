
#define NUM_LEDS 768
#define DATA_PIN 2
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

#define snake false
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


void matrixSetup() {
	FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

	Serial.begin(9600);


}

void TurnPixel(pixel that_pixel, CHSV color)
{
	Serial.println(that_pixel.led_num());
	leds[that_pixel.led_num()] = color;;
	//leds[that_pixel.led_num()] = CRGB::Purple;
}

void matrixLoop() {
#if !snake
	for (byte j = 1; j < 17; j++)
	for (byte i = 1; i < 17; i++)
	{
		pixel pixel1 = pixel(i, j);
		if ((i + j) % 2 == 0) {
			TurnPixel(pixel1, CHSV(255,0,0));
		}
		else {
			TurnPixel(pixel1, CHSV(0, 0, 255));
		}
		
	}
	
	/*pixel pixel2 = pixel(16, 0);
	TurnPixel(pixel2);*/
	FastLED.show();
	delay(400);
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


