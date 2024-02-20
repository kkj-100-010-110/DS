#include <iostream>
#include <array>
#include <type_traits>

// template<typename ... Args>
// std::array<?, ?> build_array(Args&& ... args)

// template<typename ... Args>
// auto build_array(Args&& ... args) -> std::array<typename std::common_type<Args...>::type, ?>
// {
//     using commonType = typename std::common_type<Args...>::type;
//     // 배열 생성
// }

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
    using commonType = typename std::common_type<Args...>::type;
    return {std::forward<commonType>((Args&&)args)...};
}

int main()
{
    auto data = build_array(1, 0u, 'a', 3.2f, false);
    // auto data2 = build_array(1, "Packt", 2.0); error, there's no common type.

    for (auto& e : data)
        std::cout << e << " ";
    std::cout << std::endl;
}