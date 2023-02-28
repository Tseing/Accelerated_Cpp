#include <iostream>
#include <vector>

int main()
{
    int num;
    std::vector<int> nums;
    while(std::cin >> num)
    {
        nums.push_back(num);
    }

    if(nums.size() == 0)
    {
        std::cout << "Empty vector." << std::endl;
        return 1;
    }

    double sum = 0;
    for(std::vector<int>::size_type i = 0; i != nums.size(); ++i)
    {
        sum += nums[i];
    }


    std::cout << "Average: " << sum / nums.size() << std::endl;
    return 0;
}