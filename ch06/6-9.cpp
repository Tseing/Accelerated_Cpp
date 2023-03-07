#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


int main()
{
    std::string word;
    std::vector<std::string> words;
    while(std::cin >> word)
        words.push_back(word);

    std::string init = "";
    std::string sentence = std::accumulate(words.begin(), words.end(), init);
    for(std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++ it)
        std::cout << *it << ", ";
    std::cout << std::endl;
    std::cout << sentence << std::endl;

    return 0;
}