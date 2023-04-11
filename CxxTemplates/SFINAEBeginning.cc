template<typename T>
struct IsArr;

template<typename T>
struct IsArr
{
    static constexpr bool value = false;
};

template<typename T, size_t size>
struct IsArr<T[size]>
{
    static constexpr bool value = true;
};

#include <iostream>

int main()
{
    int arr[] = {1,2,3,4,5};
    int *ptr = new int[5];
    delete[] ptr;

    std::cout << std::boolalpha;
    std::cout << IsArr<decltype(arr)>::value << '\n';
    std::cout << IsArr<decltype(ptr)>::value << '\n';
}