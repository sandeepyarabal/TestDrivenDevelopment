#include "Hiker.hpp"
#include "CppUTest/TestHarness.h"

TEST_GROUP(Hiker)
{
    Hiker * hhg;

    void setup()
    {
        hhg = new Hiker();
    }
    void teardown()
    {
        delete hhg;
    }
};

TEST(Hiker, Led)
{
     unsigned int  virtualLed = 0xffff;
     hhg->led_driver_create(&virtualLed);  
    // a simple example to start you off
    LONGS_EQUAL(54, virtualLed);
   
}
