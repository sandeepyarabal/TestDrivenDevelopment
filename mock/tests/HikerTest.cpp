#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "Hiker.hpp"
#include "production.hpp"

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

void productionCode()
{
    mock().actualCall("productionCode");
}

TEST(MockDocumentation, SimpleScenario)
{
    mock().expectOneCall("productionCode");
    //productionCode();
    //mock().checkExpectations();
    result = calc();
    LONGS_EQUAL(1, result);
}
