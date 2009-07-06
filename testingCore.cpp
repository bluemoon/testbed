#include "runningTest.hpp"

template<typename C> class Callback <C>{
public:
  Callback(C* _class_instance, Method _method){
    class_instance = _class_instance;
    method         = _method;
  }
  void execute(){
    (class_instance->*method)();
  }
};

class Test{
public:
  Test(){}
};

class callbackHolder{
public:
  void add(const char state, Callback *C){
      cbMap[state].push_back(C);
  }
private:
  map<const char,vector<Callback>> cbMap;
};
