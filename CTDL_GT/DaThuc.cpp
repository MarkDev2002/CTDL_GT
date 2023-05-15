#include <iostream>
using namespace std;
struct DaThuc
{
    int n;
    float *HeSo;
};
typedef struct DaThuc DATHUC;

void Input(DATHUC *x)
{
    do
    {
        cout << "\nNhap vao so bac cua da thuc : ";
        cin >> x->n;
        if (x->n < 1)
        {
            cout << "\nSo bac cua da thuc phai >=1";
        }
    } while (x->n < 1);

    x->HeSo = new float[x->n + 1];
    for (int i = 0; i <= x->n; i++)
    {
        cout << "\nNhap vap he so thu " << i << " la : ";
        cin >> x->HeSo[i];
    }
}

void Output(DATHUC *x)
{
    for (int i = 0; i < x->n; i++)
    {
        cout << x->HeSo[i] << " * x^" << i << " + ";
    }
    cout << x->HeSo[x->n] << " * x^" << x->n;
}

int main(int argc, char **argv)
{
    DATHUC *x = new DATHUC;
    Input(x);
    Output(x);
    delete x;
    cout << endl;
    return 0;
}