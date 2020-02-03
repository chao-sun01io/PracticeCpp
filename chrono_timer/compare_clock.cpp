// compare system_clock¡¢ steady_clock and high_resolution_clock


#include <chrono>
#include "clock.hpp"

int main(int argc, char** agrv)
{
    std::cout << "system_clock: " << std::endl;
    printClockData<std::chrono::system_clock>();
    std::cout << "\nhigh_resolution_clock: " << std::endl;
    printClockData<std::chrono::high_resolution_clock>();
    std::cout << "\nsteady_clock: " << std::endl;
    printClockData<std::chrono::steady_clock>();

#ifdef _WIN32
    system("pause");
#endif
    return 0;
}