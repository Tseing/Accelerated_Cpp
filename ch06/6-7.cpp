#include <algorithm>
#include <iostream>
#include <vector>
#include "Student_info.h"
#include "median.h"
#include "grade.h"


using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::remove_copy;
using std::remove_copy_if;
using std::remove_if;
using std::stable_partition;


bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

vector<Student_info> extract_didnt(vector<Student_info>& students)
{
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), did_all_hw);
    vector<Student_info> didnt(iter, students.end());
    students.erase(iter, students.end());

    return didnt;
}


int main()
{
    vector<Student_info> did, didnt, students;
    Student_info student;
    while(read(cin, student))
        students.push_back(student);

    didnt = extract_didnt(students);
    did = students;

    if(did.empty())
        cout << "Non student did all the homework!" << endl;
    if(didnt.empty())
        cout << "Every student did all the homework!" << endl;

    cout << "did:" << endl;
    for(vector<Student_info>::const_iterator it = did.begin(); it != did.end(); ++ it)
        cout << it->name << "\t";
    cout << endl;

    cout << "didnt:" << endl;
    for(vector<Student_info>::const_iterator it = didnt.begin(); it != didnt.end(); ++ it)
        cout << it->name << "\t";
    cout << endl;

    return 0;
}