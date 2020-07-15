#include <iostream>
#include <cstdint>
#include <forward_list>
#include "LED.h"

int main()
{
<<<<<<< HEAD:prog.cpp
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
     my_set_color.push_front(red_b);
=======
    r2led::LED leds;
>>>>>>> 37ccc3af24df0c30f9bbd98c4ae093c9b5c5e0e9:temp.cpp
    
    std::uint8_t red[3] = {255, 0, 0};
    std::uint8_t green[3] = { 0, 255, 0};
    std::uint8_t blue[3] = {0, 0, 255};
    std::uint8_t blue_g[3] = {0, 255, 255};
    std::uint8_t red_b[3] = {255, 0, 255};
    
<<<<<<< HEAD:prog.cpp
    my_leds.SetColors.push_front((*iter_s));
    my_color_adress.push_front(my_leds.SetColors.front());
    iter_s++;

    iter_ad = my_color_adress.begin();
    while (iter_s != my_set_color.end())
	{
        my_color_adress.insert_after(iter_ad, my_leds.WriteColor((*iter_s)));
		iter_s++;
	}

    my_leds.TransList();

    iter_ad = my_color_adress.begin();
    while (iter_ad != my_color_adress.end())
=======
    std::forward_list<std::uint8_t*> color_adresses;
    std::forward_list<std::uint8_t*> colors{green, red, green, blue};
    
    auto iter_s = colors.begin();
    
    leds.temp_colors.push_front((*iter_s));
    color_adresses.push_front(leds.temp_colors.front());
    iter_s++;

    auto iter_ad = color_adresses.begin();
    while (iter_s != colors.end())
    {
    	color_adresses.insert_after(iter_ad, leds.write_color((*iter_s)));
	iter_s++;
    }
    
    leds.trans_list();
   
    iter_ad = color_adresses.begin();
    while (iter_ad != color_adresses.end())
>>>>>>> 37ccc3af24df0c30f9bbd98c4ae093c9b5c5e0e9:temp.cpp
    {
        std::cout << ((void*)*iter_ad) << std::endl;
        iter_ad++;
    }
<<<<<<< HEAD:prog.cpp
    cout << endl;

    forward_list<uint8_t*>::iterator iter = my_leds.SetColors.begin();   
    while (iter != my_leds.SetColors.end())
=======
    std::cout << std::endl; 

    auto iter = leds.temp_colors.begin();   
    while (iter != leds.temp_colors.end())
    {
	for(int i = 0; i < 9; i++)
>>>>>>> 37ccc3af24df0c30f9bbd98c4ae093c9b5c5e0e9:temp.cpp
	{
	    std::cout << static_cast<unsigned>((*iter)[i]) << " ";
	}
        std::cout << std::endl;
	iter++;
    }
    std::cout << std::endl;   
}
