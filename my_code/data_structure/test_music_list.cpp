#include "music_list.h"

int main()
{
    // MY::PLAYLIST pl;

    // pl.insert(1);
    // pl.insert(2);

    // std::cout << "재생 목록: ";
    // pl.loopOnce();

    // MY::PLAYLIST pl2 = pl;

    // pl2.erase(2);
    // pl2.insert(3);
    // std::cout << "두 번째 재생 목록: ";
    // pl2.loopOnce();

    MY::PLAYLIST pl;

    pl.insert("one");
    pl.insert("two");

    std::cout << "재생 목록: ";
    pl.loopOnce();

    MY::PLAYLIST pl2 = pl;

    pl2.erase("two");
    pl2.insert("three");
    std::cout << "두 번째 재생 목록: ";
    pl2.loopOnce();

    return 0;
}