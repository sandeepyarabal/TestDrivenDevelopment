#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(MockDocumentation)
{
    void teardown()
    {
        mock().clear();
    }
};
class prod
{
   public:
     virtual ~ prod() {};
     virtual void productionCode()=0;

};
class production:public prod
{
   public:
     void productionCode()
     {
        mock().actualCall("productionCode");
     }
};

TEST(MockDocumentation, SimpleScenario)
{
    mock().expectOneCall("productionCode");
    
    prod* object = new production(); /* create mock instead of real thing */
    object->productionCode();

    mock().checkExpectations();
    
    delete object;
}
