#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "Please enter some words: " << std::endl;
    std::vector<std::string> words;
    std::string word;
    while(std::cin >> word)
        words.push_back(word);

    std::sort(words.begin(), words.end());
    for(std::vector<std::string>::size_type i = 0; i != words.size();)
    {
        std::vector<std::string>::size_type j = i;
        while(words[i] == words[j])
            ++j;
        std::cout << "\"" << words[i] << "\" : " << j - i << std::endl;
        i = j;
    }
    return 0;
}