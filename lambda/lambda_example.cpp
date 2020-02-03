#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for_each
int external = 1;
void func(int param){
    static int sum = 0;
    int internal_local = 1;
    // lambda: [capture list](parameter list)->return type{function body}
    // [...] capture list: non-static local variable!
    auto add = [internal_local,param](int a,int b){
        return sum + internal_local+param+external+a+b;

    };
    std::cout<<add(1,2)<<std::endl;
}


int main(){
    func(1);
    std::string str[5] ={"I"," ","love"," ","C++"};
//    std::vector<std::string> str_vec(&str[0],&str[4]); // output: I love (without C++)
//    std::vector<std::string> str_vec(&str[0],&str[5]); // It outputs "I love C++",but str[5] the index is overflow!
    std::vector<std::string> str_vec(str,str+5); // good!
    std::for_each(str_vec.begin(),str_vec.end(),
                  [](const std::string& s){ std::cout <<  s;}); // empty capture list;
    return 0;
}
