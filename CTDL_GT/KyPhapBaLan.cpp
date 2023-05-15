#include <iostream>
#include <fstream>
using namespace std;
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

struct stack
{
    NODE *top;
};
typedef struct stack STACK;

struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

void Init(STACK &s)
{
    s.top = NULL;
}

NODE *GetNode(string x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "Not enough memory";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

bool isEmpty(STACK s)
{
    if (s.top == NULL)
    {
        return false;
    }
    return true;
}

bool Push(STACK &s, NODE *p)
{
    NODE *p = new NODE;
    p = GetNode(x);
    if (p == NULL)
    {
        cout << "Not enough memory";
        return NULL;
    }
    if (isEmpty(s) == false)
    {
        s.top = p;
        return true;
    }
    p->pNext = s.top;
    s.top = p;
    return true;
}

bool Pop(STACK &s, string &x)
{
    if (isEmpty(s) == false)
    {
        return false;
    }
    NODE *p = s.top;
    x = p->data;
    s.top = s.top->pNext;
    delete p;
    return true;
}

bool Top(STACK s, string &x)
{
    if (isEmpty(s) == false)
    {
        return false;
    }
    x = s.top->data;
    return true;
}

void Input(STACK &s)
{
    ifstream FileIn;
    FileIn.open("C:\\Users\\nguye\\OneDrive\\Máy tính\\test.txt", ios::in);
    if (!FileIn)
    {
        cout << "Not Found";
        return 0;
    }
    string str;
    Init(s);
    for (int i = 0; i < str.length; i++)
    {
        NODE *p = new NODE;
        if (str[i] == '(')
        {
            continue;
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            char *temp = new char;
            temp[0] = str[i];
            temp[1] = '\0';
            string a = temp;
            p = GetNode(a);
            Push(s, p);
        }
    }
    getline(FileIn, str);
    cout << str;
    FileIn.close();
}

void Output(STACK s)
{
    while (isEmpty(s) == true)
    {
        string str;
        Pop(s, str);
        cout << str << endl;
    }
}
int main()
{
    Input(s);
    Output(s);
    cout << endl;
    return 0;
}