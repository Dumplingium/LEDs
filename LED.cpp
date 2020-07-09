#include "LED.h"

namespace r2led {

LED::~LED()
{
    for (auto iter = temp_colors.begin(); iter != temp_colors.end(); iter++)
    {
    	delete[] (*iter);
    }
}

std::uint32_t LED::trans(std::uint8_t color)
{
    std::uint32_t color_f = 0;
    std::uint8_t temp = 0;
    
    for(int i = 0; i < 8; i++)
    {
    	temp = color & 1;
    	if (temp) 
    	    color_f = color_f | (6 << (i * 3));
	else 
	    color_f = color_f | (4 << (i * 3));
	color >>= 1;
	temp = 0;
    } 
    return color_f;
}

std::uint8_t* LED::trans_color(std::uint8_t r, std::uint8_t g, std::uint8_t b)
{
    std::uint8_t *buff = new std::uint8_t[9];
    
    std::uint32_t r_f = trans(r);
    std::uint32_t g_f = trans(g);
    std::uint32_t b_f = trans(b);
    
    for (int i = 0; i < 3; i++)
    {
    	buff[i] = (g_f & 0xFF0000) >> 16;
    	g_f <<= 8;
    }
    
    for (int i = 3; i < 6; i++)
    {
	buff[i] = (r_f & 0xFF0000) >> 16;
	r_f <<= 8;
    }
    
    for (int i = 6; i < 9; i++)
    {
    	buff[i] = (b_f & 0xFF0000) >> 16;
    	b_f <<= 8;
    }
    return buff;
}

std::uint8_t* LED::write_color(std::uint8_t* color)
{
    bool flag_color;
    auto iter = temp_colors.begin();
    while(iter != temp_colors.end())
    {
    	flag_color = false;
	for (int i = 0; i < 3; i++)
	    if(color[i] != (*iter)[i])
		flag_color = true;

	if (flag_color == false) 
	    return (*iter);

	iter++;
    }
    temp_colors.push_front(color);
    return temp_colors.front();
}

void LED::trans_list()
{
    auto iter = temp_colors.begin();
    while(iter != temp_colors.end())
    {
	*iter = trans_color((*iter)[0], (*iter)[1], (*iter)[2]);
	iter++;
    }
}

/*uint8_t *LED::procissing_colors(forward_list<uint8_t *> set_colors)
{
	forward_list<uint8_t*> color_adress;

	forward_list<uint8_t*>::iterator iter_s;
    forward_list<uint8_t*>::iterator iter_ad;

	iter_s = set_color.begin();
    
    temp_colors.push_front((*iter_s));
    color_adress.push_front(temp_colors.front());
    iter_s++;

    iter_ad = color_adress.begin();
    while (iter_s != set_color.end())
	{
        color_adress.insert_after(iter_ad, write_color((*iter_s)));
		iter_s++;
	}

    trans_list();
	return 
}*/

};  // namespace r2led
