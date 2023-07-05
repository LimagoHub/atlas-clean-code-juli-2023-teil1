#include <iostream>

template<class T, class U>
auto add(T a, U b) -> decltype(a + b) {
    static_assert(std::is_arithmetic<T>::a, "Not an arithmetic type");
    static_assert(std::is_arithmetic<T>::b, "Not an arithmetic type");
    return a + b;
}


template<class T>
auto max(T a, T b)->T {
    return a>b?a:b;
}

class bar{
    virtual auto xyz() -> int = 0;
    virtual auto abc()->void = 0;
};
auto foo() {
    return 42;
}


auto main() -> int {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
