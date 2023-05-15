#include <iostream>
using namespace std;
void Move(int n, char nguon, char trungGian, char dich)
{
    if (n == 1)
    {
        cout << nguon << " -- > " << dich << endl;
    }
    else
    {
        Move(n - 1, nguon, dich, trungGian);
        Move(1, nguon, trungGian, dich);
        Move(n - 1, trungGian, nguon, dich);
    }
}
int main()
{
    int n;
    cout << "Nhap vao so dia n : " << endl;
    cin >> n;
    Move(n, 'A', 'B', 'C');
    cout << endl;
    return 0;
}