#include <iostream>
#include <functional>
class BeCalled{
public:
    int handle(int x,int y){
        std::cout<<x<<" "<<y<<" "<< a+x*y <<std::endl;
    }
private:
    int a = 10;
};

class Caller{
private:
    std::function<int(int)> func_;
public:
    void register_callback(std::function<int(int)> handle){
        func_=handle;
    }
    void call(int x){
        if(func_ == nullptr)
            std::cout<<" nullptr"<<std::endl;
        else
            func_(x);
    }

};
int main(int argc,char** argv){
    BeCalled c;
    Caller caller;
//    caller.register_callback(std::bind(&BeCalled::handle,c,std::placeholders::_1,3));
    caller.call(4);
    return 0;
}
