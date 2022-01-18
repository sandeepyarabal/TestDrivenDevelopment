#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "Hiker.hpp"


TEST_GROUP(MockDocumentation)
{
    int result;
    
    void teardown()
    {
        result =0;
        mock().checkExpectations();
        mock().clear();
    }
};

int productionCode(int val1 , int val2)
{ 
    mock().actualCall("productionCode")
        .withParameter("val1", val1).withParameter("val2", val2);
    return mock().intReturnValue();


}

TEST(MockDocumentation, SimpleScenario)
{
    mock().expectOneCall("productionCode")
        .withParameter("val1", 10).withParameter("val2", 20).andReturnValue(30);

    result = calc();
    LONGS_EQUAL(30, result);
}
