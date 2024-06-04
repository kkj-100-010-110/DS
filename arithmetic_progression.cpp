#include <iostream>
#include <vector>

const int n = 10;

int main(int argc, char* argv[])
{
    int** arr = new int*[n];
    for (int i = 0; i < n; ++i)
        arr[i] = new int[n];

    std::vector<int> t(n*n);

    int m = 1;
    for (int i = 0; i < n*n; ++i)
    {
        if ((i + 1) % n == 0)
            m++;
        m = (i + 1) / n + m;
        t[i] = 1 + (m * (m - 1)) / 2;
    }

    for (int i = 0; i < n*n; ++i)
    {
        std::cout << t[i] << "  ";
        if ((i+1) % n == 0)
        {
            std::cout << '\n';
        }
    }

    for (int i = 0; i < n; ++i)
        delete[] arr[i];
    delete[] arr;

    return 0;
}