#include <iostream>
#include <cstdint>
#include <forward_list>
#include "LED.h"

int main()
{
    r2led::LED leds;
    
    std::uint8_t red[3] = {255, 0, 0};
    std::uint8_t green[3] = { 0, 255, 0};
    std::uint8_t blue[3] = {0, 0, 255};
    std::uint8_t blue_g[3] = {0, 255, 255};
    std::uint8_t red_b[3] = {255, 0, 255};
    
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
    {
        std::cout << ((void*)*iter_ad) << std::endl;
        iter_ad++;
    }
    std::cout << std::endl; 

    auto iter = leds.temp_colors.begin();   
    while (iter != leds.temp_colors.end())
    {
	for(int i = 0; i < 9; i++)
	{
	    std::cout << static_cast<unsigned>((*iter)[i]) << " ";
	}
        std::cout << std::endl;
	iter++;
    }
    std::cout << std::endl;   
}
