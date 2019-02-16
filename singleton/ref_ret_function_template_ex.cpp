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

template<typename T>
T& get_global(){
    static T instance;
    return instance;
}

int main(int argc, char *argv[])
{
    A& instance_1 = get_global<A>();
    A& instance_2 = get_global<A>();
    return 0;
}
