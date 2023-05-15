#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    long double factorial = 1.0;
    cout << fixed;
    cout << setprecision(0);
    cout << "Enter a positive number : ";
    cin >> n;
    if (n < 0)
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            factorial *= i;
            cout << "Factorial of " << (i < 10 ? " " : "") << i << " = ";
            cout << factorial << endl;
        }
        factorial *= n;
        cout << "Factorial of " << n << " = " << factorial << endl;
    }
    cout << endl;
    return 0;
}