#include <iostream>
#include <cstdint>
#include "list_v3.h"

class MY_LED
{
    protected:
        // uint32_t AdaptationColor(uint8_t color);
        // void TransColor(uint8_t *buff);
		NewList<uint8_t> SetAddress;
    public:	
		MY_LED();	
		~MY_LED();
        NewList<uint8_t> SetColors;
		MY_LED * operator=(MY_LED *new_led);
        uint8_t * WriteColor(uint8_t* color, NewList<uint8_t> *set_colors, uint8_t num = 3);
		// void TransList(NewList<uint8_t> *set_colors);
		void NewLed(NewList<uint8_t> *set_color, NewList<uint8_t> *set_colors);
		uint8_t * NextAddress();
		uint8_t * BackAddress();
};

MY_LED::MY_LED()
{
		
}

MY_LED::~MY_LED()
{
	
}

MY_LED * MY_LED::operator=(MY_LED *new_led)
{
	this->SetAddress = new_led->SetAddress;
	return this;
}

/* uint32_t MY_LED::AdaptationColor(uint8_t color)
{
	uint32_t color_f = 0;
///
	for(int i = 0; i < 8; i++)
	{
		if (color & 1) color_f = color_f | (6 << (i*3));
		else color_f = color_f | (4 << (i*3));
		color >>= 1;
	} 
	return color_f;
}*/

/*void MY_LED::TransColor(uint8_t *buff)
{
	uint8_t r = buff[0];
	uint8_t g = buff[1];
	uint8_t b = buff[2];

	uint32_t r_f = 0, g_f = 0, b_f = 0;
	r_f = AdaptationColor(r);
	g_f = AdaptationColor(g);
	b_f = AdaptationColor(b);

	for (int i = 0; i < 3; i++)
	{
		buff[i] = (g_f & 0xFF0000) >> 16;
		g_f <<= 8;

		buff[i+3] = (r_f & 0xFF0000) >> 16;
		r_f <<= 8;
	
		buff[i+6] = (b_f & 0xFF0000) >> 16;
		b_f <<= 8;
	}
}*/

/*void MY_LED::TransList(NewList<uint8_t> *set_colors)
{
	
	uint8_t *iter = set_colors->back();
	TransColor(iter);
	uint8_t *begin_s = set_colors->back();
	iter = set_colors->next();
	
	do
    {
		TransColor(iter);
		iter = set_colors->next();
	}while(iter != begin_s);
}*/

uint8_t * MY_LED::WriteColor(uint8_t * color, NewList<uint8_t> *set_colors, uint8_t num)
{
    bool flag_color;
	uint8_t *begin_s = set_colors->next();
	uint8_t *iter = set_colors->back();
	do
    {
		flag_color = false;
		for (int i = 0; i < num ; i++)
		{
			if(color[i] != iter[i])
				flag_color = true;
		}
		if (flag_color == false) 
			return iter;

		iter = set_colors->next();
	}while(iter != begin_s);
	set_colors->Add(color);
	return set_colors->back();
}

void MY_LED::NewLed(NewList<uint8_t> *set_color, NewList<uint8_t> *set_colors)
{
	uint8_t* begin_set = set_color->next();
	uint8_t* temp = set_color->back();


    if(set_colors->back() == NULL)
	{
		set_colors->Add(begin_set);
		SetAddress.Add(set_colors->back());
		temp = set_color->next();
	}

    do
	{
        SetAddress.Add(WriteColor(temp, set_colors));
		temp = set_color->next();
	}while (temp != begin_set);

    // TransList(set_colors);
	
////*** вывод массива адресов ***/////
    /*uint8_t* begin_ad = SetAddress.next();
    uint8_t* iter_ad = SetAddress.back();
    do
    {
        std::cout << (void*)iter_ad << std::endl;
        iter_ad = SetAddress.next();
    }while (iter_ad != begin_ad);
    std::cout << std::endl;*/

////*** вывод массива цветов ***/////
	/*uint8_t* begin_col = set_colors->next();
    uint8_t* iter = set_colors->back();
    do
	{
		for(int i = 0; i < 9; i++)
		{
			std::cout << static_cast<unsigned>(iter[i]) << "  ";
		}
        std::cout << std::endl;
        iter = set_colors->next();
	}while (iter != begin_col);
    std::cout << std::endl;*/
}

uint8_t *MY_LED::NextAddress()
{
	return SetAddress.next();
}

uint8_t *MY_LED::BackAddress()
{
	return SetAddress.back();
}
