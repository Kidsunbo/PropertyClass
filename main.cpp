#include "PropertyClass.h"
#include <iostream>
class Test{

private:
    int _a{0};// This initial value has no effect

public:
    Property<int> ro_a{[this](){return _a;}};
    Property<int> rw_a{[this](){return _a;},
    [this](auto a){
        if(a>10){
            std::cout<<"This variable should not be bigger than 10"<<std::endl;
            return;
        }
        _a=a;
    },
    1};
};

int main(){
    Test t;
    std::cout<<t.ro_a<<std::endl;
    t.ro_a=10;
    std::cout<<t.ro_a<<std::endl;


    std::cout<<"-----"<<std::endl;
    std::cout<<t.rw_a<<std::endl;
    t.rw_a=10;
    std::cout<<t.rw_a<<std::endl;
    std::cout<<t.ro_a<<std::endl;
    t.rw_a=11;
    std::cout<<t.rw_a<<std::endl;
    std::cout<<t.ro_a<<std::endl;


    return 0;
}