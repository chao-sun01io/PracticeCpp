#include <iostream>

class A
{
public:
    A() {
        std::cout<<"constructor" <<std::endl;
    }
    ~A(){
        std::cout<<"destructor"<<std::endl;
    }
};


A& ret_singleton(){
    static A instance;
    return instance;
}

int main(int argc, char *argv[])
{
    A& instance_1 = ret_singleton();
    A& instance_2 = ret_singleton();
    return 0;
}
