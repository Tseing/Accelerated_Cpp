#include <iostream>

int main()
{
    int k = 0;
    {
        using std::cout;
        cout << "*";
        ++k;
    }
    std::cout << std::endl;
    return 0;
}