#include "Hiker.hpp"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
TEST_GROUP(Hiker)
{
    Hiker * hhg;
    int a = 3;
    int b = 3;
    void setup()
    {
        hhg = new Hiker();
    }
    void teardown()
    {
        delete hhg;
        mock().clear();
    }
};
void productionCode(int p1 ,int p2)
{
    mock().actualCall("productionCode").withParameter("p1", p1).withParameter("p2", p2);
}
TEST(Hiker, Life_the_universe_and_everything)
{
    mock().expectOneCall("productionCode").withParameter("p1", a).withParameter("p2", b);
    // a simple example to start you off
    LONGS_EQUAL(54, hhg->answer());
    //CHECK(1);
    //CHECK_TRUE(1);
    //CHECK_FALSE(0);
    //STRCMP_EQUAL("hey", "hey");
    //FAIL("Start here");
     mock().checkExpectations();
}
