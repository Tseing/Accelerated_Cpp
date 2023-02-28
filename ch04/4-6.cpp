#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info_modified.h"

using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;


int main()
{
    vector<Student_info_modified> students;
    Student_info_modified record;
    string::size_type maxlen = 0;
    while(read_grade(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }


    sort(students.begin(), students.end(), comp);
    for(vector<Student_info_modified>::size_type i = 0;
        i != students.size(); ++i)
    {
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        double final_grade = students[i].grade;
        streamsize prec = cout.precision();
        cout << setprecision(3) << final_grade << setprecision(prec);

        cout << endl;
    }
    return 0;
}
