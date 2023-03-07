#include <iostream>
#include <vector>

int main()
{
    std::vector<int> u(10, 100);
    std::vector<int> v1;
    std::vector<int> v2;

    for(std::vector<int>::const_iterator it = u.begin(); it != u.end(); ++ it)
        v1.push_back(*it);

    for(std::vector<int>::const_iterator it = u.begin(); it != u.end(); ++it)
        v2.insert(v2.end(), *it);

    for(std::vector<int>::const_iterator it = u.begin(); it != u.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;

    for(std::vector<int>::const_iterator it = v1.begin(); it != v1.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;

    for(std::vector<int>::const_iterator it = v2.begin(); it != v2.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;
}