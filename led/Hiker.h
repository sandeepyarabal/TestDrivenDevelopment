#ifndef HIKER_INCLUDED
#define HIKER_INCLUDED

class Hiker
{
public:
  unsigned int * ledaddress;
  Hiker();
  ~Hiker();
  void led_driver_create(unsigned int * address);

};

#endif
