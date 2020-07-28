#include <iostream>
#include <cstdint>
#include "list_v3.h"

using namespace std;

class MY_LED
{
    protected:
        uint32_t AdaptationColor(uint8_t color);
        uint8_t* TransColor(uint8_t r, uint8_t g, uint8_t b);
    public:	
		MY_LED();	
		~MY_LED();
        NewList<uint8_t*> SetColors;
		NewList<uint8_t*> SetAddress;
        uint8_t * WriteColor(uint8_t* color, NewList<uint8_t*> *set_colors, uint8_t num = 3);
		void TransList(void);
		NewList<uint8_t*>* NewLed(NewList<uint8_t *> *set_color, NewList<uint8_t*> *set_colors);
    
};

MY_LED::MY_LED()
{
		
}

MY_LED::~MY_LED()
{
	
}

uint32_t MY_LED::AdaptationColor(uint8_t color)
{
	uint32_t color_f = 0;
/* можно улучшить */
	for(int i = 0; i < 8; i++)
	{
		if (color & 1) color_f = color_f | (6 << (i*3));
		else color_f = color_f | (4 << (i*3));
		color >>= 1;
	} 
	return color_f;
}

uint8_t* MY_LED::TransColor(uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t r_f = 0, g_f = 0, b_f = 0;
	uint8_t *buff = new uint8_t[9];
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
	return buff;
}

uint8_t * MY_LED::WriteColor(uint8_t * color, NewList<uint8_t*> *set_colors, uint8_t num)
{
    bool flag_color;
	Node<uint8_t*> *iter = set_colors->back()->Next;
	do
    {
		flag_color = false;
		for (int i = 0; i < num ; i++)
		{
			if(color[i] != iter->content[i])
				flag_color = true;
		}
		if (flag_color == false) 
			return iter->content;

		iter = iter->Next;
	}while(iter != set_colors->back()->Next);
	set_colors->Add(color);
	return set_colors->back()->content;
}

void MY_LED::TransList(void)
{
	Node<uint8_t*> *iter = SetColors.back();

	do
    {
		iter->content = TransColor(iter->content[0], iter->content[1], iter->content[2]);
		iter = iter->Next;
	}while(iter != SetColors.back());
}

NewList<uint8_t*>* MY_LED::NewLed(NewList<uint8_t*> *set_color, NewList<uint8_t*> *set_colors)
{
	Node<uint8_t*> *iter_s = set_color->back()->Next;
    
    set_colors->Add(iter_s->content);
    SetAddress.Add(set_colors->back()->content);
    iter_s = iter_s->Next;

    Node<uint8_t*> *iter_ad = SetAddress.back();
    while (iter_s != set_color->back()->Next)
	{
        SetAddress.Add(WriteColor(iter_s->content, set_colors));
		iter_s = iter_s->Next;
	}
	return &SetAddress;
    // TransList();
	
////*** вывод массива адресов ***/////
    /*iter_ad = SetAddress.back()->Next;
    do
    {
        cout << ((void*)iter_ad->content) << endl;
        iter_ad = iter_ad->Next;
    }while (iter_ad != SetAddress.back()->Next);
    cout << endl;*/

////*** вывод массива цветов ***/////

    /*Node<uint8_t*> *iter = SetColors.back()->Next;
    do
	{
		for(int i = 0; i < 9; i++)
		{
			cout << static_cast<unsigned>(iter->content[i]) << "  ";
		}
        cout << endl;
        iter = iter->Next;
	}while (iter != SetColors.back()->Next);
    cout << endl;*/
}