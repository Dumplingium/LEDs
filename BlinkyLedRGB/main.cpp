#include "mbed.h"
#include "SET_LEDS.h"  

// #include "MY_LED_RGB.h" 

int main() 
{ 
    // MY_LED_RGB my_led(1);

    // my_led.light_led(255, 0, 255);
    
    SET_LEDS my_set_leds(1);
    // NewList<uint8_t> my_set_color1;
    NewList<uint8_t> my_set_color;

    uint8_t *red = new uint8_t[9]{255, 0, 0};
    uint8_t *blue_g = new uint8_t[9]{0, 255, 255};
    uint8_t *green = new uint8_t[9]{ 0, 255, 0};
    uint8_t *blue = new uint8_t[9]{0, 0, 255};
    uint8_t *red_b = new uint8_t[9]{255, 0, 255};

    
    my_set_color.Add(red_b);
    my_set_color.Add(green);
    my_set_color.Add(red);
    my_set_color.Add(blue_g);
    my_set_color.Add(blue);
    my_set_color.Add(green);

    // my_set_color1.Add(red);
    // my_set_color1.Add(blue_g);
    // my_set_color1.Add(red_b);
    // my_set_color1.Add(blue);

    my_set_leds.AddNewLed(&my_set_color);
    // my_set_leds.AddNewLed(&my_set_color1);

    
    my_set_leds.TransList(&my_set_leds.SetAllColors);

    for(int i = 0; i < 6; i++)
    {   
        my_set_leds.One();
        wait_us(2000000);
    } 


    // my_led.light_led( 0, 0, 0xFF);
}