#include "x.h"
#include <vector>
#include <iostream>
#include <string>
class X::XImpl{
public:
   XImpl() = default;
   std::vector<std::string> array_;
};

X::X()
    :pimpl_{new XImpl}
{

}

// or =default; This is neccessary,because
// unique_ptr’s destructor requires a complete type in order to invoke delete;
// here force it to be defined in a place where impl is already defined
// see: https://herbsutter.com/gotw/_100/
X::~X(){}

X::X(const X &x)
{
   pimpl_ = std::make_unique<XImpl>();
   *pimpl_ = *x.pimpl_;
}

X &X::operator=(const X &other)
{
    if(&other == this){
        return *this;
    }
    *pimpl_ = *other.pimpl_;
    return *this;
}

void X::push_element(const std::string &str)
{
    pimpl_->array_.push_back(str);
}

void X::print()
{
    for(const auto & i :pimpl_->array_){
        std::cout<< i <<" ";
    }
    std::cout<<std::endl;
}
