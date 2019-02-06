// author: sunchaothu
// brief: a singleton base class offering an easy way to create singleton
// ref:
// 1. https://stackoverflow.com/questions/34519073/inherit-singleton?r=SearchResults
// 2. https://www.cnblogs.com/lidabo/p/3949226.html

#include <memory> // shard_ptr
#include <mutex>
#include <iostream>
template<typename T>
class Singleton{
    typedef std::shared_ptr<T> Ptr;
protected:
    Singleton() noexcept=default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    virtual ~Singleton() = default; // to silence base class Singleton<T> has a
    // non-virtual destructor [-Weffc++]

    static Ptr instance_ptr;
    static std::mutex singleton_mutex;
public:

    static Ptr get_instance() noexcept(std::is_nothrow_constructible<T>::value)
    {
        if(instance_ptr==nullptr){
           std::lock_guard<std::mutex> lk(singleton_mutex);
           if(instance_ptr==nullptr){
                instance_ptr = std::shared_ptr<T>(new T());
           }
        }
        return instance_ptr;

    }
};
template <typename T>
std::shared_ptr<T> Singleton<T>::instance_ptr=nullptr;

template <typename T>
std::mutex Singleton<T>::singleton_mutex;


/********************************************/
// Example:
// 1.friend class declaration is requiered!
// 2.constructor should be private


class DerivedSingle:public Singleton<DerivedSingle>{
   // !!!! attention!!!
   // needs to be friend in order to
   // access the private constructor/destructor
   friend class Singleton<DerivedSingle>;
   int value;
public:

   void info(){
       std::cout<<"value: \n";
       std::cout<<value<<std::endl;
   }
   void set_value(int i){
       value  = i;
   }
   int get_value(){
       return value;
   }
private:
   DerivedSingle():value(0){}
   DerivedSingle(const DerivedSingle&)=delete;
   DerivedSingle& operator =(const DerivedSingle&)= delete;
};

int main(int argc, char* argv[]){
    std::shared_ptr<DerivedSingle> instance  = DerivedSingle::get_instance();
    instance->info();
    instance->set_value(1);
    std::shared_ptr<DerivedSingle> instance2 = DerivedSingle::get_instance();
    instance2->info();
    return 0;
}
