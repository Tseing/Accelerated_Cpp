#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "Student_info.h"
#include "median.h"
#include "grade.h"


using std::find;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::transform;
using std::back_inserter;
using std::domain_error;
using std::ostream;
using std::accumulate;
using std::remove_copy;
using std::remove_copy_if;
using std::remove_if;
using std::stable_partition;


bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade_aux(const Student_info& s)
{
    try
    {
        return grade(s);
    }
    catch(domain_error)
    {
        return grade(s.midterm, s.final, 0);
    }

}

double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}

double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    if(nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

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
//    vector<Student_info> fail;
//    remove_copy_if(students.begin(),students.end(), back_inserter(fail), pgrade);
//    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}

int main()
{
    vector<Student_info> did, didnt;
    Student_info student;
    while(read(cin, student))
    {
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    if(did.empty())
    {
        cout << "Non student did all the homework!" << endl;
//        return 1;
    }
    if(didnt.empty())
    {
        cout << "Every student did all the homework!" << endl;
//        return 1;
    }

    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
//    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    vector<Student_info> did_fail = extract_fails(did);
    vector<Student_info> didnt_fail = extract_fails(didnt);

    cout << "Fails:" << endl;
    for(vector<Student_info>::const_iterator it = did_fail.begin(); it != did_fail.end(); ++ it)
        cout << it->name << "\t";
    cout << endl;

    for(vector<Student_info>::const_iterator it = didnt_fail.begin(); it != didnt_fail.end(); ++ it)
        cout << it->name << "\t";
    cout << endl;

    return 0;
}