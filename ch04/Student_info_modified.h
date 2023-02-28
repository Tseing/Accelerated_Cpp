#ifndef GUARD_Stuent_info_modified
#define GUARD_Stuent_info_modified

#include <iostream>
#include <string>
#include <vector>

struct Student_info_modified
{
    std::string name;
    double grade;
};

bool comp(const Student_info_modified&, const Student_info_modified&);
std::istream& read_grade(std::istream&, Student_info_modified&);

#endif
