#include "dictionary.hpp"
#include "dictionary.h"
#include "binary_search_tree.h"

int main()
{
    // Dictionary<int, int> t;
    // t.insert(10,10);
    // t.insert(5,5);
    // t.insert(15,15);
    // t.insert(2,2);
    // t.insert(4,4);
    // t.insert(3,3);
    // t.insert(6,6);
    // t.insert(8,8);
    // t.insert(7,7);
    // // t.insert(6,6);
    // t.insert(9,9);
    // t.insert(13,13);
    // t.insert(14,14);
    // t.insert(18,18);
    // t.insert(16,16);
    // t.insert(17,17);
    // t.insert(19,19);
    // t.insert(20,20);
    // t.print();
    // t.remove(5);
    // t.remove(17);
    // t.remove(18);
    // t.remove(8);
    // t.remove(10);
    // t.print();
    // std::cout << std::endl;

    Dictionary<int, int> t1;

    // t1.insert(10,10);
    // t1.insert(8, 8);
    // t1.insert(9, 9);
    // t1.insert(6, 6);
    // t1.insert(7, 7);
    // t1.insert(4, 4);
    // t1.insert(5, 5);
    // t1.insert(3, 3);
    t1.insert(8, 8);
    t1.insert(9, 9);
    t1.insert(7, 7);
    t1.insert(6, 6);
    t1.print();
    std::cout << std::endl;
    t1.remove(8);
    t1.print();

    return 0;
}