#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    cout << "Enter all your homework grades, "
            "followed by end-of-line: ";

    int count = 0;
    double sum = 0;
    double x;
    while(cin >> x)
    {
        ++count;
        sum += x;
    }

    if(count==0)
    {
        cout << "You must enter homework grades." << std::endl;
        return 1;
    }
    else
    {
        streamsize prec = cout.precision();
        cout << "Your final grad is " << setprecision(3)
             << 0.2 * midterm + 0/4 * final + 0.4 * sum / count
             << setprecision(prec) << endl;

        return 0;
    }
}