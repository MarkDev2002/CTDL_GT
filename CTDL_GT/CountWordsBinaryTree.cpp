#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct NODE
{
    string data;
    int counter;
    NODE *pLeft;
    NODE *pRight;
};
typedef NODE *Tree;

NODE *CreateNode(string data)
{
    NODE *p = new NODE();
    p->data = data;
    p->counter = 1;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void AddNode(Tree &t, NODE *p)
{
    if (t != NULL)
    {
        if (t->data.compare(p->data) == 0)
        {
            t->counter++;
        }
        else if (t->data.compare(p->data) > 0)
        {
            AddNode(t->pLeft, p);
        }
        else
        {
            AddNode(t->pRight, p);
        }
    }
    else
    {
        t = p;
    }
}

void ShowNode(Tree t)
{
    if (t != NULL)
    {
        ShowNode(t->pLeft);
        cout << left << setw(12) << t->data << ": " << t->counter << endl;
        ShowNode(t->pRight);
    }
}

void ReadData(Tree &t)
{
    ifstream ifs("test.txt");
    while (!ifs.eof())
    {
        string word;
        ifs >> word;
        NODE *p = CreateNode(word);
        AddNode(t, p);
    }
    ifs.close();
}

int main()
{
    Tree t = NULL;
    ReadData(t);
    ShowNode(t);
    cout << endl;
    return 0;
}