#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    const string::size_type a = 10;
    string square_h(a, '*');
    string square_spaces(a - 2, ' ');

    for(string::size_type r = 0; r != a; ++r)
    {
        string::size_type c = 0;
        while(c != a)
        {
            if(r == 0 || r == a - 1)
            {
                cout << square_h;
                c += square_h.size();
            }

            else
            {
                if(c == 1)
                {
                    cout << square_spaces;
                    c += square_spaces.size();
                }
                else
                {
                    cout << "*";
                    ++c;
                }
            }
        }
        cout << endl;
    }

    string rectangle_h(a, '*');
    string rectangle_spaces(a - 2, ' ');
    const string::size_type b = 15;

    for(string::size_type r = 0; r != b; ++r)
    {
        string::size_type c = 0;
        while(c != a)
        {
            if(r == 0 || r == b - 1)
            {
                cout << rectangle_h;
                c += rectangle_h.size();
            }
            else
            {
                if(c == 1)
                {
                    cout << rectangle_spaces;
                    c += rectangle_spaces.size();

                }
                else
                {
                    cout << "*";
                    ++c;
                }
            }
        }
        cout << endl;
    }

    const string::size_type h = 10;
    const string::size_type gap = 2;
    for(string::size_type r = 0; r != h; ++r)
    {
        if(r == 0)
        {
            cout << "*";
        }
        else
        {
            if(r == h - 1)
            {
                cout << string(gap*h, '*');
            }
            else
            {
                cout << "*" << string(gap*r, ' ') << "*";
            }
        }
        cout << endl;
    }

    return 0;
}