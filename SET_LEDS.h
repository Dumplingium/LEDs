#include <iostream>
#include <cstdint>
#include "LED.h"

class SET_LEDS
{
private:
    
public:
    NewList<MY_LED> SetLeds;
    NewList<uint8_t> SetAllColors;
    SET_LEDS();
    ~SET_LEDS();
    void AddNewLed(NewList<uint8_t> *colors_led);
};

SET_LEDS::SET_LEDS()
{
}

SET_LEDS::~SET_LEDS()
{
}

void SET_LEDS::AddNewLed(NewList<uint8_t> *colors_led)
{
    MY_LED *new_led = new MY_LED;
    new_led->NewLed(colors_led, &SetAllColors);
    SetLeds.Add(new_led);

    uint8_t* begin_col = SetAllColors.next();
    uint8_t* iter = SetAllColors.back();
    do
	{
		for(int i = 0; i < 9; i++)
		{
			std::cout << static_cast<unsigned>(iter[i]) << "  ";
		}
        std::cout << std::endl;
        iter = SetAllColors.next();
	}while (iter != begin_col);
    std::cout << std::endl;
}