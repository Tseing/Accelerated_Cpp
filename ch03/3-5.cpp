#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<string> names;
    vector<double> grades;
    cout << "Please enter students' names: ";
    string name;
    while(cin >> name)
    {
        if(cin.get() == '\n')
            break;
        names.push_back(name);
    }


    for(vector<string>::size_type i = 0; i != 2; ++i)
    {
        cout << "Please enter " << names[i] << "'s midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;

        cout << "Enter 3 homework grades: ";
        vector<double> homework;
        double x;
        const vector<double>::size_type size = 3;

        for(vector<double>::size_type j = 0; j != size; ++j)
        {
            cin >> x;
            homework.push_back(x);
        }


        double median, grade;
        vector<string>::size_type mid = size / 2;
        median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
                               : homework[mid];


        grade = 0.2 * midterm + 0.4 * final + 0.4 * median;
        grades.push_back(grade);
    }

    for(vector<string>::size_type i = 0; i != names.size(); ++i)
        cout << names[i] << " : " << grades[i] << endl;


    return 0;
}