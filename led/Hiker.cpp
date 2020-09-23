#include "Hiker.hpp"

Hiker::Hiker()
{
}

Hiker::~Hiker()
{
}



void Hiker:: led_driver_create(unsigned int * address)
{
    
    ledaddress = address;
    *ledaddress = 10;
}
