#include <iostream>
#include <cstdint>
#include <forward_list>
#include <iterator>
#include "MY_LED.h"

using namespace std;

int main()
{
    MY_LED my_leds;
    forward_list<uint8_t*> my_set_color;
    forward_list<uint8_t*> my_color_adress;

    uint8_t red[3] = {255, 0, 0};
    uint8_t green[3] = { 0, 255, 0};
    uint8_t blue[3] = {0, 0, 255};
    uint8_t blue_g[3] = {0, 255, 255};
    uint8_t red_b[3] = {255, 0, 255};

    my_set_color.push_front(blue);
    my_set_color.push_front(green);
    my_set_color.push_front(red);
    my_set_color.push_front(green);
    
    forward_list<uint8_t*>::iterator iter_s;
    forward_list<uint8_t*>::iterator iter_ad;

    iter_s = my_set_color.begin();
    
    my_leds.temp_colors.push_front((*iter_s));
    my_color_adress.push_front(my_leds.temp_colors.front());
    iter_s++;

    iter_ad = my_color_adress.begin();
    while (iter_s != my_set_color.end())
	{
        my_color_adress.insert_after(iter_ad, my_leds.write_color((*iter_s)));
		iter_s++;
	}

    my_leds.trans_list();

    iter_ad = my_color_adress.begin();
    while (iter_ad != my_color_adress.end())
    {
        cout << ((void*)*iter_ad) << endl;
        iter_ad++;
    }
    cout << endl; 

    forward_list<uint8_t*>::iterator iter = my_leds.temp_colors.begin();   
    while (iter != my_leds.temp_colors.end())
	{
		for(int i = 0; i < 9; i++)
		{
			cout << static_cast<unsigned>((*iter)[i]) << "  ";
		}
        cout << endl;
		iter++;
	}
    cout << endl;
    
}