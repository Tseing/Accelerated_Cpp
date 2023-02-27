#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main()
{
    std::vector<int> dataset;
    std::cout << "Please enter a set of int numbers: " << std::endl;
    int num;
    while(std::cin >> num)
    {
        dataset.push_back(num);
    }
    std::sort(dataset.begin(), dataset.end());
    std::cout << std::setprecision(3);
    for(std::vector<int>::size_type i = dataset.size(); i != 0; --i)
    {
        std::cout << dataset[i - 1] / 4.0 << "\t";
    }
    std::cout << std::endl;
    return 0;
}