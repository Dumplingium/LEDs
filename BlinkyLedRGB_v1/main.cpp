#include "mbed.h"
#include "SET_LEDS.h" 
#include <cstdlib>  

int main() 
{     
    SET_LEDS my_set_leds(1);

    // uint8_t *red = new uint8_t[9]{255, 0, 0};
    // uint8_t *blue = new uint8_t[9]{0, 0, 255};
    // uint8_t *green = new uint8_t[9]{0, 255, 0};
    // uint8_t *red_b = new uint8_t[9]{132, 0, 132};

//     my_set_leds.AddNewLed();
//     my_set_leds.AddColorBackLed(blue);
//     my_set_leds.AddColorBackLed(red_b);
//     my_set_leds.AddColorBackLed(red);
//     my_set_leds.AddColorBackLed(red_b);

//    ;
//     my_set_leds.AddColorBackLed(blue);
//     my_set_leds.AddColorBackLed(green);

    for(int i=0; i < 144; i++)
    {
        my_set_leds.AddNewLed();
        uint8_t *col1 = new uint8_t[9]{128, 0, 127};
        my_set_leds.AddColorBackLed(col1);
    }
    
    my_set_leds.BlinkyNOne(1, 2000000);
    /*int n = 21;
    // uint8_t *buff = new uint8_t[n]
    // {1, 255,0,255, 0,0,255, 1, 0,255,0, 255,0,0, 0,0,255,
    //  1, 255,255,255, 0,255,0, 255,255,0, 1, 0,0,0, 255,0,0};

    uint8_t *buff = new uint8_t[n]{1, 0,0,0, 0,255,0, 1, 255,255,255, 0,0,255, 1, 255,0,0, 0,255,255};

    int i = 0;
    while(i < n)
    {
        NewList<uint8_t> my_set_color;
        i++;
        while(buff[i] != 1 && i < n)
        {
            uint8_t *color = new uint8_t[9]{buff[i], buff[i+1], buff[i+2]};
            my_set_color.Add(color);
            i = i + 3;
        }
        
        my_set_leds.AddNewLed(&my_set_color);

        uint8_t* my_begin = my_set_color.back();
        uint8_t* temp = my_set_color.back();
        do
        {
            for(int i = 0; i < 3; i++)
            {
                cout << static_cast<unsigned>(temp[i]) << "  ";
            }
            cout << endl;
            temp = my_set_color.next();
        }while (temp != my_begin);
        cout << endl;
    }

    my_set_leds.BlinkyNOne(3, 2);
*/
}