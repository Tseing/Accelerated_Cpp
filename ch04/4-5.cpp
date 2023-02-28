#include <iostream>
#include <vector>
#include <istream>
#include <algorithm>

std::istream& read_words(std::istream& s, std::vector<std::string>& words)
{
    std::string word;
    if(s)
    {
        s >> word;
        words.push_back(word);
    }
    return s;
}

int main()
{
    std::vector<std::string> words;
    while(read_words(std::cin, words));

    std::cout << "Total words: " << words.size() << std::endl;

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