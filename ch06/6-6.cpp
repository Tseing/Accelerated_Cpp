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

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
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

double analysis(const vector<Student_info>& students, double analysis_mode(const Student_info&))
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), analysis_mode);
    return median(grades);
}

void write_analysis(ostream& out, const string& name,
                    double analysis_mode(const Student_info&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did, analysis_mode) << ", median(didnt) = " << analysis(didnt, analysis_mode) << endl;
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
        cout << "Non student did all the homework!" << endl;
    if(didnt.empty())
        cout << "Every student did all the homework!" << endl;

    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);

    return 0;
}