#include "Student_info.h"
#include <algorithm>

int main()
{
    std::string::size_type maxlen;
    Student_info s;
    std::max(s.name.size(), maxlen);
}