#include <iostream>
using namespace std;
int Acker(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    if (n == 0)
    {
        return Acker(m - 1, 1);
    }
    return Acker(m - 1, Acker(m, n - 1));
}
int main()
{
    int m, n;
    cout << "Nhap m : ";
    cin >> m;
    cout << "Nhap n : ";
    cin >> n;
    cout << "De quy Acker = " << Acker(m, n);
    cout << endl;
    return 0;
}