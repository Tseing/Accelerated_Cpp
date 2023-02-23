#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    int vertical_pad;
    int horizontal_pad;
    cout << "Please enter vertical pad: ";
    cin >> vertical_pad;
    cout << "Please enter horizontal pad: ";
    cin >> horizontal_pad;

    const int rows = vertical_pad * 2 + 3;
    const string::size_type cols = greeting.size() + horizontal_pad * 2 + 2;

    cout << endl;
    for(int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;
        while(c != cols)
        {
            if(r == vertical_pad + 1 && c == horizontal_pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if(r == 0 || r == rows - 1|| c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}