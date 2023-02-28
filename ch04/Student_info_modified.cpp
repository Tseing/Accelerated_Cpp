#include "Student_info_modified.h"
#include "grade.h"


using std::istream;
using std::vector;


bool compare(const Student_info_modified& x, const Student_info_modified& y)
{
    return x.name < y.name;
}
istream& read_grade(istream& is, Student_info_modified& s)
{
    double midterm, final;
    is >> s.name >> midterm >> final;

    vector<double> hw;
    double x;
    hw.clear();
    if(is)
    {
        while(is >> x)
            hw.push_back(x);
        s.grade = grade(midterm, final, hw);
        is.clear();
    }
    return is;
}
