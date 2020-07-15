#include "list.h"

int main()
{
    
    class NewList<uint8_t*> my_list;
     
    uint8_t red[3] = {255, 0, 0};
    uint8_t green[3] = { 0, 255, 0};
    uint8_t blue[3] = {0, 0, 255};

    my_list.Add(red);
    my_list.Add(green);
    my_list.Add(blue);
    my_list.PrintList();

    // my_list.DeleteBack();
    // my_list.PrintList();

    // my_list.Add(9);
    // my_list.Add(77);
    // my_list.PrintList();
    // my_list.Swap(my_list.back()->Next, my_list.back());
    // my_list.PrintList();
    // cout << static_cast<unsigned>(my_list.front()->content) << endl;
   
}