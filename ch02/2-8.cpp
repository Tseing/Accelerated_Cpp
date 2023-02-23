#include <iostream>

int main()
{
    int prod = 1;
    for(int i = 1; i != 10; ++i)
    {
        prod = prod * i;
    }
    std::cout << prod << std::endl;
    return 0;
}