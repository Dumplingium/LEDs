#include <iostream>
#include <cstdint>
// #include "LED.h"
#include "SET_LEDS.h"
// #include "list_v3.h"

using namespace std;

int main()
{
    SET_LEDS my_set_leds;
    MY_LED my_leds;
    NewList<uint8_t> my_set_color;
    NewList<uint8_t> my_color_address;

    uint8_t red[3] = {255, 0, 0};
    uint8_t blue_g[3] = {0, 255, 255};
    uint8_t green[3] = { 0, 255, 0};
    uint8_t blue[3] = {0, 0, 255};
    uint8_t red_b[3] = {255, 0, 255};

    
    my_set_color.Add(red_b);
    my_set_color.Add(red);
    my_set_color.Add(green);
    my_set_color.Add(blue);
    my_set_color.Add(green);

    my_set_leds.AddNewLed(&my_set_color);
    // my_leds.NewLed(&my_set_color, &my_leds.SetColors);

    // uint8_t* begin_set = my_set_color.next();
    
    // my_leds.SetColors.Add(begin_set);
    // my_color_address.Add(my_leds.SetColors.back());

    // uint8_t* temp = my_set_color.next();

    // while (temp != begin_set)
	// {
    //     my_color_address.Add(my_leds.WriteColor(temp, &my_leds.SetColors));
    //     // uint8_t* tmp = my_leds.WriteColor(temp, &my_leds.SetColors);
    //     // cout << *tmp << endl;
	// 	temp = my_set_color.next();
	// }

    // my_leds.TransList();

////*** вывод изначального массива цветов ***/////
    /*uint8_t* my_begin = my_set_color.next();
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
    cout << endl;*/

////*** вывод массива адресов ***/////
    // uint8_t* begin_ad = my_color_address.next();
    // uint8_t* iter_ad = my_color_address.back();
    // do
    // {
    //     cout << (void*)iter_ad << endl;
    //     // for(int i = 0; i < 3; i++)
	// 	// {
	// 	// 	cout << static_cast<unsigned>(iter_ad[i]) << "  ";
	// 	// }
    //     // cout << endl;
    //     iter_ad = my_color_address.next();
    // }while (iter_ad != begin_ad);
    // cout << endl;

////*** вывод массива цветов ***/////
    // uint8_t* begin_col = my_leds.SetColors.next();
    // uint8_t* iter = my_leds.SetColors.back();
    // do
	// {
	// 	for(int i = 0; i < 9; i++)
	// 	{
	// 		cout << static_cast<unsigned>(iter[i]) << "  ";
	// 	}
    //     cout << endl;
    //     iter = my_leds.SetColors.next();
	// }while (iter != begin_col);
    // cout << endl;
        
}