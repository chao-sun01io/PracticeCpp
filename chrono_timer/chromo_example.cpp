#include <chrono>
#include <iostream>

using namespace std;

template <typename V, typename R>
ostream& operator << (ostream& s, const chrono::duration<V, R>& d)
{
    s << "[" << d.count() << " of " << R::num << "/"
        << R::den << "]";
    return s; 
}

int main(int argc, char** argv) {
    chrono::seconds      twentySeconds(20);
    chrono::hours        aDay(24);
    chrono::milliseconds oneMillisecond(1);
    chrono::duration<int, ratio<1, 3>> d1(1);   // 1 tick of 1/3 second
    chrono::duration<int, ratio<1, 5>> d2(1);   // 1 tick of 1/5 second

    std::cout << twentySeconds << aDay << oneMillisecond << std::endl;

#ifdef _WIN32
    system("pause");
#endif // _WIN32

    return 0;
}