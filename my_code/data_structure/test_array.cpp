#include "array.h"

int main()
{
    MY::ARRAY<int> arr;
    MY::ARRAY<int> arr1(1);
    MY::ARRAY<int> arr2{1,2,3,4,5};
    MY::ARRAY<int> arr3{1,2,3};
    MY::ARRAY<int> arr4(arr2);
    MY::ARRAY<int> arr5(10);

    arr = arr3;
    arr1 = arr2;
    arr5 = arr2;
    
    // constructor, copy constructor and assignment operator overloading 
    std::cout << arr1 << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << arr5 << std::endl;
    std::cout << arr4 << std::endl;

    // push_back(), insert() and + operator overloading
    std::cout << arr2 + arr5 << std::endl;
    std::cout << arr2.capacity() << std::endl;
    arr2.push_back(6);
    std::cout << arr2 << std::endl;
    std::cout << arr2.capacity() << std::endl;
    arr2.push_back(7);
    std::cout << arr2 << std::endl;
    arr5.insert(0, -1);
    std::cout << arr5 << std::endl;
    arr5.insert(6, 7);
    // arr5.insert(7, 7); // exception ok
    std::cout << arr5 << std::endl;
    arr5.insert(0, -1);
    std::cout << arr5 << std::endl;
    arr5.insert(6, 6);
    std::cout << arr5 << std::endl;

    // at() test
    std::cout << arr.at(2) << std::endl;
    // std::cout << arr.at(3) << std::endl; // exception ok

    return 0;
}