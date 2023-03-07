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


bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}


vector<Student_info> extract_students(vector<Student_info>& students, bool condition(const Student_info&))
{

    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), condition);
    vector<Student_info> unmatched(iter, students.end());
    students.erase(iter, students.end());

    return unmatched;
}

int main()
{
    vector<Student_info> students_1, students_2;
    Student_info student;
    while(read(cin, student))
        students_1.push_back(student);

    students_2 = students_1;

    vector<Student_info> fail_1 = extract_fails(students_1);
    vector<Student_info> fail_2 = extract_students(students_2, pgrade);

    cout << "fails:";
    for(vector<Student_info>::const_iterator it = fail_1.begin(); it != fail_1.end(); ++ it)
        cout << it->name << "\t";
    cout << endl;

    cout << "fails:";
    for(vector<Student_info>::const_iterator it = fail_2.begin(); it != fail_2.end(); ++ it)
        cout << it->name << "\t";
    cout << endl;

    cout << "pass:";
    for(vector<Student_info>::const_iterator it = students_1.begin(); it != students_1.end(); ++ it)
        cout << it->name << "\t";
    cout << endl;

    cout << "pass:";
    for(vector<Student_info>::const_iterator it = students_2.begin(); it != students_2.end(); ++ it)
        cout << it->name << "\t";
    cout << endl;

    return 0;
}