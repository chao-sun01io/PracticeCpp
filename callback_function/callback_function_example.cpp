#include <iostream>

///*** Step1:C-style function pointer ***/
//typedef int (*FP)(int a, int b);


// or like below
using FP = int(*)(int a,int b);

int add(int a, int b){
    return a+b;
}

int minus(int a,int b){
    return a-b;
}


int main(int argc, char** argv){


    /* test1: C-style function pointer */
    int (*func_ptr)(int,int);
    func_ptr =add;
    FP func_ptr2=add;
    std::cout<<"Test1..."<<func_ptr(1,2)<<"  "<<func_ptr2(2,3)<<std::endl;
    FP fp_array[]={add,minus};
    std::cout<<"Test2..."<<fp_array[0](1,2)<<" "<<fp_array[1](2,3)<<std::endl;

    return 0;
}


//#include<functional>// std::function

//void func(void)
//{
//    std::cout << __FUNCTION__ << std::endl;
//}

//class Foo
//{
//public:
//    static int foo_func(int a)
//    {
//        std::cout << __FUNCTION__ << "(" << a << ") ->: ";
//        return a;
//    }
//};

//class Bar
//{
//public:
//    int operator() (int a)
//    {
//        std::cout << __FUNCTION__ << "(" << a << ") ->: ";
//        return a;
//    }
//};

//int main()
//{

//    std::cout << __FUNCTION__ << std::endl;
//    // 绑定普通函数
//    std::function<void(void)> fr1 = func;
//    fr1();

//    // 绑定类的静态成员函数，需要加上类作用域符号
//    std::function<int(int)> fr2 = Foo::foo_func;
//    std::cout << fr2(100) << std::endl;

//    // 绑定仿函数
//    Bar bar;
//    fr2 = bar;
//    std::cout << fr2(200) << std::endl;

//    return 0;
//}
