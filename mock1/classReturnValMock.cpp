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
     virtual int productionCode()=0;

};
class production:public prod
{
   public:
     int productionCode()
     {
        return mock().actualCall("productionCode").returnIntValue();
        
      
     }
};

TEST(MockDocumentation, SimpleScenario)
{
   
    mock().expectOneCall("productionCode").andReturnValue(0);
    
    prod* object = new production(); /* create mock instead of real thing */
    object->productionCode();

    mock().checkExpectations();
    
    delete object;
}
