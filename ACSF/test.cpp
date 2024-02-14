#include <iostream>

using std::cout;
using std::endl;

int main()
{
    char *p;
    char a = 'a';
    p = &a;

    cout << *p << " " << a << endl;

    char *q = new char;
    *q = 'b';
    char &b = *q;

    cout << *q << " " << b << endl;
    cout << q << " " << (&b) << endl;

    delete q;
    q = nullptr;

    cout << q << " " << b << endl;

    return 0;
}