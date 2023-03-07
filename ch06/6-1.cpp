#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::isspace;
using std::getline;
using std::max;
using std::cin;
using std::cout;
using std::endl;

vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size())
    {
        while(i != s.size() && isspace(s[i]))
            ++i;
        string_size j = i;
        while(j != s.size() && !isspace(s[j]))
            ++j;
        if(i != j)
        {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
        maxlen = max(maxlen, it->size());
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    ret.push_back(border);
    for(vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
        ret.push_back("* " + *it + string(maxlen - it->size(), ' ') + " *");
    ret.push_back(border);
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    string::size_type width1 = width(left) + 1;
    vector<string>::const_iterator i = left.begin(), j = right.begin();
    while(i != left.end() || j != right.end())
    {
        string s;
        if(i != left.end())
            s = *i++;
        s += string(width1 - s.size(), ' ');

        if(j != right.end())
            s += *j++;

        ret.push_back(s);
    }
    return ret;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        vector<string> v1 = split(s);
        vector<string> v2 = frame(v1);
        vector<string> v = hcat(v1 , v2);
        for(vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
            cout << *it <<endl;
    }
    return 0;
}