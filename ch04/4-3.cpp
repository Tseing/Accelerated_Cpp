#include <iostream>
#include <iomanip>

int calculate_digit(int num)
{
    if(num == 0)
        return 1;

    int digit = 0;
    while( num != 0)
    {
        num = num / 10;
        ++ digit;
    }

    return digit;
}

int main()
{
    for(int i = 1; i <= 999; ++i)
    {
        int j = i* i;
        std::cout << std::setw(calculate_digit(i)) << i
                  << std::setw(10 + calculate_digit(i) + calculate_digit(j)) << j << std::endl;
    }
    return 0;
}