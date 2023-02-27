#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    std::vector<std::string> words;
    std::string word;
    while(std::cin >> word)
        words.push_back(word);
    std::sort(words.begin(), words.end());
    std::cout << "The shortest word is \"" << words[0] << "\""
              << " and the longest word is \"" << words[words.size() - 1]  << "\"." << std::endl;

    return 0;
}