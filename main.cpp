#include "runningTest.hpp"
#include "serialiser.hpp"
int main(void){
    STATE(TESTSTATE1);
    TEST_W_STATE(TESTSTATE1, TestSelf1, 1 == 1);
    STATE(TESTSTATE2);
    TEST_W_STATE(TESTSTATE2, TestSelf2, 1 == 1);
    STATE(TESTSTATE3);
    TEST_W_STATE(TESTSTATE3, TestSelf3, 1 == 2);
    TEST_W_STATE(TESTSTATE3, TestSelf4, false == true);
    TEST_W_STATE(TESTSTATE2, TestSelf5, true == true);

    int State = 1;
    STORE_VALUE(int, State);
    
    SUMMARY();
    
}
