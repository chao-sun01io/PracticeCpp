#include "x.h"
#include <vector>
#include <iostream>
#include <string>
int main(int argc, char *argv[])
{
    X x;
    x.push_element("I");
    x.push_element("love");
    x.push_element("coding");
    x.print();

    X x2 = x; // copy ctor
    x2.push_element(",too");
    x2.print();

    x = x2; // copy assignment op
    x.print();
    return 0;
}
