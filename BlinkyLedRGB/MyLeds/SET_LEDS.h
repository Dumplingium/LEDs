#ifndef DSET_LEDS
#define DSET_LEDS

#include "MY_LED.h"
#include "MY_LED_RGB.h"

class SET_LEDS: protected MY_LED_RGB
{
protected:
    uint32_t AdaptationColor(uint8_t color)
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
    void TransColor(uint8_t *buff)
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
    }
    
public:
    SET_LEDS(int Num_SPI):MY_LED_RGB(Num_SPI){};
    ~SET_LEDS()
    {
        uint8_t* begin_col = SetAllColors.next();
        uint8_t* iter = SetAllColors.back();
        do
        {
            delete [] iter;
            iter = SetAllColors.next();
        }while (iter != begin_col);

        MY_LED* begin_led = SetLeds.next();
        MY_LED* iter_led = SetLeds.back();
        do
        {
            delete iter_led;
            iter_led = SetLeds.next();
        }while (iter_led != begin_led);
    }
    NewList<MY_LED> SetLeds;
    NewList<uint8_t> SetAllColors;
    void TransList(NewList<uint8_t> *set_colors)
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
    }
    void AddNewLed(/*NewList<uint8_t> *colors_led*/)
    {
        MY_LED *new_led = new MY_LED;
        // new_led->NewLed(colors_led, &SetAllColors);
        SetLeds.Add(new_led);
        
        // delete colors_led;
    }
    void AddColorBackLed(uint8_t *buff)
    {
        SetLeds.back()->AddColor(buff, &SetAllColors);
    }
    void One()
    {
        MY_LED *begin_led = SetLeds.back();
        MY_LED *iter_led = SetLeds.back();
        
        do
        {
            uint8_t *temp = iter_led->NextAddress();
            LightOneLed(temp);
            iter_led = SetLeds.next();
    
        } while (iter_led != begin_led);
        
    }
    void BlinkyNOne(int quantity, float delay_sec)
    {
        TransList(&SetAllColors);
        SetLeds.next();
        if(quantity == 1)
        {
            while (true)
            {
                One();
                wait_us(delay_sec);
            }
        }
        else
        {
            for(int i = 0; i < quantity; i++)
            {
                One();
                wait_us(delay_sec);
            }
        }    
    }
};

#endif