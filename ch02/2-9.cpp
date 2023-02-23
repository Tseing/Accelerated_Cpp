#include <iostream>

int main()
{
    std::cout << "Please enter 2 numbers: " << std::endl;
    float a, b;
    std::cin >> a >> b;

    if(a == b)
    {
        std::cout << "Number " << a << " equals to number " << b << std::endl;
    }
    else
    {
        if(a > b)
        {
            std::cout << "Number " << a << " is larger than number " << b << std::endl;
        }
        else
        {
            std::cout << "Number " << b << " is larger than number " << a << std::endl;
        }
    }
}