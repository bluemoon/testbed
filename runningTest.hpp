#ifndef runningTest_h
#define runningTest_h

#pragma once 

#include "serialiser.hpp"
#include <cstdio>
#include <vector>
#include <map>
#include <string>

std::string g_state;

struct test{
    std::string testName;
    std::string testState;
    std::string file;
    unsigned int line;
    int         status;
} testStruct;

extern std::vector<test> resultStack;
std::vector<test> resultStack(0);

#define STORE_VALUE(Type, Variable)\
    string s##Variable;\
    s##Variable.append(#Type);\
    s##Variable.append("_");\
    s##Variable.append(#Variable);\
    serialiser<Type> v##Variable;\
    v##Variable.Serialise(Variable, s##Variable);\
    
#define STATE(newState)(g_state = #newState)
#define ASSERT(VALUE_X, VALUE_Y) (VALUE_Y == VALUE_X)


#define TEST_W_STATE(STATE, TEST_NAME, ASSERTION)\
     int result##TEST_NAME;\
     if(#STATE == g_state){\
         if(ASSERTION){\
             printf("[%s:%d] %s under %s (%s) passed\n",__FILE__, __LINE__, #TEST_NAME, #STATE, #ASSERTION);\
             result##TEST_NAME = 1;\
         }\
         else{\
             printf("[%s:%d] %s under %s (%s) failed! \n",__FILE__, __LINE__, #TEST_NAME, #STATE, #ASSERTION);\
             result##TEST_NAME = 0;\
         }\
     } else{\
        printf("[%s:%d] non-state test. (%s != %s)\n",__FILE__, __LINE__, #STATE, g_state.c_str());\
     }\
     test TEST_NAME;\
     TEST_NAME.testName  = #TEST_NAME;\
     TEST_NAME.testState = #STATE;\
     TEST_NAME.file      = __FILE__;\
     TEST_NAME.line      = __LINE__;\
     TEST_NAME.status    = result##TEST_NAME;\
     resultStack.push_back(TEST_NAME);\

#define SUMMARY()\
     std::vector<test>::iterator stackItr;\
     stackItr = resultStack.begin();\
     int pass = 0;\
     int fail = 0;\
     do{\
         if(stackItr->status == 1) pass++;\
         if(stackItr->status == 0) fail++;\
         stackItr++;\
     } while(stackItr != resultStack.end());\
    printf("Total: %d Fail: %d Pass: %d \n",(fail + pass), fail, pass);

#endif
