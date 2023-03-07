#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> u(10, 100);
    std::vector<int> v(u.size());
    std::copy(u.begin(), u.end(), v.begin());

    for(std::vector<int>::const_iterator it = u.begin(); it != u.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;

    for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;

    return 0;
}