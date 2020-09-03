#ifndef DMY_LED
#define DMY_LED

#include <iostream>
#include "NewList.h"

class MY_LED
{
    protected:
		NewList<uint8_t> SetAddress;
    public:	
		MY_LED(){}	
		~MY_LED(){}
        NewList<uint8_t> SetColors;
		MY_LED * operator=(MY_LED *new_led)
        {
            this->SetAddress = new_led->SetAddress;
            return this;
        }
        uint8_t * WriteColor(uint8_t* color, NewList<uint8_t> *set_colors, uint8_t num = 3)
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
		void NewLed(NewList<uint8_t> *set_color, NewList<uint8_t> *set_colors)
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

        }
        void AddColor(uint8_t *buff, NewList<uint8_t> *set_colors)
        {
            if(set_colors->back() == NULL)
            {
                set_colors->Add(buff);
                SetAddress.Add(set_colors->back());
            }
            else
            {
                SetAddress.Add(WriteColor(buff, set_colors));
            }
        }
		uint8_t * NextAddress()
        {
            return SetAddress.next();
        }
		uint8_t * BackAddress()
        {
            return SetAddress.back();
        }
};

#endif