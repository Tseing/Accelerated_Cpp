#include <iostream>
#include <iomanip>

int main()
{
    for(double i = 1.0; i <= 100; ++i)
    {
        std::cout << i << "\t\t" << i * i << std::endl;
    }
    return 0;
}