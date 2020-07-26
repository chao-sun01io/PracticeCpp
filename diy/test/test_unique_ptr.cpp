#include <iostream>
#include "../unique_ptr.hpp"
using namespace std;

class TestClass{
    public:
    TestClass(){
        std::cout << "constructor!" << std::endl;
    };
    ~TestClass(){std::cout << "destructor!" << std::endl;}
    void print(){std::cout << "my address: "<<this << std::endl;}
};

int main(int argc, const char** argv) {
    auto raw_ptr = new TestClass;
    std::cout << "raw ptr point to: " << raw_ptr << std::endl;

    diy::unique_ptr<TestClass> ptr(raw_ptr);
    std::cout << "smart ptr point to: "<< ptr.get() << std::endl;
    ptr->print();

    // auto ptr1 = ptr; // compile error as expected because copy-constructor is deleted
    auto ptr2 = std::move(ptr);
    ptr2->print();

    // move assignment
    ptr = std::move(ptr2);
    ptr->print();
    return 0;
}