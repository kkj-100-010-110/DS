#include "array.h"
#include <iostream>
#include <sstream>
#include <algorithm>

struct student
{
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
    int nStudents;
    std::cout << "1반 학생 수를 입력하세요: ";
    std::cin >> nStudents;

    my::dynamic_array<student> class1(nStudents);
    for (int i = 0; i < nStudents; i++)
    {
        std::string name;
        int standard;
        std::cout << i + 1 << " 번째 학생 이름과 나이를 입력하세요: ";
        std::cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    try
    {
        // class1.at(nStudents) = student{"John", 8};
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        std::cout << "예외 발생!" << std::endl;
    }

    auto class2 = class1;
    std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

    auto class3 = class1 + class2;
    std::cout << "1반과 2반 합쳐 3반 생성: " << class3.to_string() << std::endl;

    return 0;
}