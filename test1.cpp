#include "singly_ll.h"

int main()
{
    singly_ll sll = {1,2,3};
    sll.push_front(0);

    std::cout << "첫 번째 리스트: ";
    for (auto i : sll)
        std::cout << i << " ";
    std::cout << std::endl;

    auto sll2 = sll;
    sll2.push_front(-1);

    std::cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";
    for (auto i : sll2)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "깊은 복사 후 첫 번째 리스트: ";

    for (auto i : sll)
        std::cout << i << ' ';
    std::cout << std::endl;
}