#include <iostream>
#include <cstdint>
#include "LED.h"

using namespace std;

int main()
{
    MY_LED my_leds;
    NewList<uint8_t*> my_set_color;
    NewList<uint8_t*> my_color_address;

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

    my_leds.NewLed(&my_set_color, &my_leds.SetColors);

    // Node<uint8_t*> *iter_s = my_set_color.back()->Next;
    
    // my_leds.SetColors.Add(iter_s->content);
    // my_color_address.Add(my_leds.SetColors.back()->content);
    // iter_s = iter_s->Next;

    // Node<uint8_t*> *iter_ad = my_color_address.back();
    // while (iter_s != my_set_color.back()->Next)
	// {
    //     my_color_address.Add(my_leds.WriteColor(iter_s->content, &my_leds.SetColors));
	// 	iter_s = iter_s->Next;
	// }

    // my_leds.TransList();

////*** вывод изначального массива цветов ***/////
    Node<uint8_t*> *iter_s = my_set_color.back()->Next;
    do
    {
        for(int i = 0; i < 3; i++)
		{
			cout << static_cast<unsigned>(iter_s->content[i]) << "  ";
		}
        cout << endl;
        iter_s = iter_s->Next;
    }while (iter_s != my_set_color.back()->Next);
    cout << endl;

////*** вывод массива адресов ***/////
    // iter_ad = my_color_address.back()->Next;
    // do
    // {
    //     cout << ((void*)iter_ad->content) << endl;
    //     iter_ad = iter_ad->Next;
    // }while (iter_ad != my_color_address.back()->Next);
    // cout << endl;

////*** вывод массива цветов ***/////

    // Node<uint8_t*> *iter = my_leds.SetColors.back()->Next;
    // do
	// {
	// 	for(int i = 0; i < 3; i++)
	// 	{
	// 		cout << static_cast<unsigned>(iter->content[i]) << "  ";
	// 	}
    //     cout << endl;
    //     iter = iter->Next;
	// }while (iter != my_leds.SetColors.back()->Next);
    // cout << endl;
        
}