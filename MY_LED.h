#include <iostream>
#include <cstdint>
#include <forward_list>
#include <iterator>
#include <map>

using namespace std;

class MY_LED
{
    private:
		uint8_t *buff;
        uint32_t trans(uint8_t color);
		map<uint8_t*, uint8_t*> temp_colors;
    public:	
		MY_LED();	
		~MY_LED();
        // forward_list<uint8_t*> temp_colors;
        uint8_t* trans_color(uint8_t r, uint8_t g, uint8_t b);
        uint8_t * write_color(unsigned char* color);
		void trans_list(void);
    
};

MY_LED::MY_LED()
{
	buff = new uint8_t[9];
	
}

MY_LED::~MY_LED()
{
	delete[] buff;
}

uint32_t MY_LED::trans(uint8_t color)
{
	uint32_t color_f = 0;
	uint8_t temp = 0;

	for(int i = 0; i < 8; i++)
	{
		temp = color & 1;
		if (temp) color_f = color_f | (6 << (i*3));
		else color_f = color_f | (4 << (i*3));
		color >>= 1;
		temp = 0;
	} 
	return color_f;
}

uint8_t* MY_LED::trans_color(uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t r_f = 0, g_f = 0, b_f = 0;
	// static uint8_t buff[9];
	r_f = trans(r);
	g_f = trans(g);
	b_f = trans(b);

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

uint8_t * MY_LED::write_color(unsigned char * color)
{
    bool flag_color;
    map<uint8_t*, uint8_t*>::iterator iter;

	iter = temp_colors.find(color);
	if (iter != temp_colors.end())
	{
		return (*iter).second;
	}
	else
	{
		temp_colors.insert(make_pair(color, trans_color(color[0], color[1], color[2])));
		iter = temp_colors.find(color);
		return (*iter).second;
	}
	
}

/*void MY_LED::trans_list(void)
{
	forward_list<uint8_t*>::iterator iter;
	forward_list<uint8_t*>::iterator iter2;
	uint8_t* temp[9];
	iter = temp_colors.begin();
	while(iter != temp_colors.end())
    {
		(*iter) = trans_color((*iter)[0], (*iter)[1], (*iter)[2]);
		cout << (*iter) << endl;
		iter++;
	}
	cout << endl;

	iter2 = temp_colors.begin();
	while(iter2 != temp_colors.end())
    {
		cout << (*iter2) << endl;
		iter2++;
	}
}*/