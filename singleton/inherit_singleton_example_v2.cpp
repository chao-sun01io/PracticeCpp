// author: sunchaothu
// brief: a singleton base class offering an easy way to create singleton
#include <iostream>

template<typename T>
class Singleton{
public:
    static T& get_instance() noexcept(std::is_nothrow_constructible<T>::value){
        static T instance{token()};
        return instance;
    }
    virtual ~Singleton() =default;
    Singleton(const Singleton&)=delete;
    Singleton& operator =(const Singleton&)=delete;
protected:
    struct token{}; // helper class
    Singleton() noexcept=default;
};


/********************************************/
// Example:
// constructor should be public because protected `token` control the access


class DerivedSingle:public Singleton<DerivedSingle>{
public:
   DerivedSingle(token){
       std::cout<<"constructor called!"<<std::endl;
   }

   ~DerivedSingle(){
       std::cout<<"destructor called!"<<std::endl;
   }
   DerivedSingle(const DerivedSingle&)=delete;
   DerivedSingle& operator =(const DerivedSingle&)= delete;
};

int main(int argc, char* argv[]){
    DerivedSingle& instance1 = DerivedSingle::get_instance();
    DerivedSingle& instance2 = DerivedSingle::get_instance();
    return 0;
}
