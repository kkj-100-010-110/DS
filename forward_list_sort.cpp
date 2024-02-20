#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list fl{23, 0, 1, -3, 34, 32};

    fl.sort();
    for (auto& e : fl)
        std::cout << e << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    fl.sort(std::greater<int>());
    for (auto& e : fl)
        std::cout << e << " ";
    std::cout << std::endl;

    std::forward_list<int> list1 = {2, 53, 1, 0, 4, 10};
    for (auto& e : list1)
        std::cout << e << " ";
    std::cout << std::endl;
    list1.reverse();
    for (auto& e : list1)
        std::cout << e << " ";
    std::cout << std::endl;
    list1 = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    for (auto& e : list1)
        std::cout << e << " ";
    std::cout << std::endl;
    list1.unique();
    for (auto& e : list1)
        std::cout << e << " ";
    std::cout << std::endl;

    list1 = {0, 1, 0, 1, 1, -1, 10, 5, 5, 10, 0};
    for (auto& e : list1)
        std::cout << e << " ";
    std::cout << std::endl;
    list1.sort();
    for (auto& e : list1)
        std::cout << e << " ";
    std::cout << std::endl;
    list1.unique();
    for (auto& e : list1)
        std::cout << e << " ";
    std::cout << std::endl;
    list1.unique([](int a, int b) { return (b - a) < 2; });
    for (auto& e : list1)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}