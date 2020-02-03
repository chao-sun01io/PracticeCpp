#ifndef X_H
#define X_H

#include <memory> // std::unique_ptr
#include <string>
class X
{
public:
    X();
    ~X();
    X(const X& x);
    X& operator=(const X& x);
    void push_element(const std::string& str);
    void print();
private:
    class XImpl;
    std::unique_ptr<XImpl> pimpl_;
};

#endif // X_H
