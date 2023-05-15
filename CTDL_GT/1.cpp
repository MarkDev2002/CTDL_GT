#include <iostream>
#include <string.h>
using namespace std;
struct SinhVien
{
    char MSSV[8];
    char hoten[26];
    float dcb;
    float dcn1;
    float dcn2;
};
typedef SinhVien SV;
void NhapSV(SV *s)
{
    cout << "\nNhap ma so sinh vien : ";
    cin >> s->MSSV;
    cout << "Nhap ho ten : ";
    fflush(stdin);
    gets(s->hoten);
    cout << "Nhap diem co ban : ";
    cin >> s->dcb;
    cout << "Nhap diem chuyen nganh 1 : ";
    cin >> s->dcn1;
    cout << "Nhap diem chuyen nganh 2 : ";
    cin >> s->dcn2;
}
void XuatSV(SV *s)
{
    cout << "THONG TIN SINH VIEN BAN VUA NHAP\n";
    cout << "MSSV: " << s->MSSV << endl;
    cout << "Ho va ten: " << s->hoten << endl;
    cout << "Diem co ban: " << s->dcb << endl;
    cout << "Diem chuyen nganh 1: " << s->dcn1 << endl;
    cout << "Diem chuyen nganh 2: " << s->dcn2 << endl;
    int tong = s->dcb + s->dcn1 + s->dcn2;
    cout << "Tong diem cua 3 mon: " << tong << endl;
}
void NhapN(int &n)
{
    do
    {
        cout << "Nhap so phan tu : ";
        cin >> n;
    } while (n <= 0);
}
void NhapDSSV(SV *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\tNhap sinh vien thu " << i + 1 << endl;
        NhapSV(a + i);
    }
}
void XuatDSSV(SV *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        XuatSV(a + i);
    }
}
int main()
{
    int n;
    NhapN(n);
    SV *s = new SV[n];
    NhapDSSV(s, n);
    XuatDSSV(s, n);
    delete s;
    return 0;
}