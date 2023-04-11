// This file contains experiments with constants char arrays and cxx templates
// Seems it is possible to make for example CompileTime RegExp matcher in cpp now

#include <iostream>

template <const char c>
void PrintCharCT()
{
    std::cout << (int) c << '\n';
}


// Intercepting printing for specific letter
template<>
void PrintCharCT<'o'>()
{
    std::cout << "o LATTER" << '\n';
}

template<>
void PrintCharCT<'e'>()
{
    std::cout << "e LATTER" << '\n';
}



template <const char STRING[], size_t FULLSTRLEN, size_t INDEX>
struct PrintStringIndexedCT;

template <const char STRING[], size_t FULLSTRLEN, size_t INDEX>
struct PrintStringIndexedCT
{
    PrintStringIndexedCT()
    {
        PrintCharCT<STRING[INDEX]>();
        PrintStringIndexedCT<STRING, FULLSTRLEN, INDEX+1>();
    }

    PrintStringIndexedCT(PrintStringIndexedCT &other) = delete;
    PrintStringIndexedCT(PrintStringIndexedCT &&other) = delete;
};

template <const char STRING[], size_t LASTINDEX>
struct PrintStringIndexedCT<STRING, LASTINDEX, LASTINDEX>
{
    PrintStringIndexedCT()
    {
        PrintCharCT<STRING[LASTINDEX]>();
    }

    PrintStringIndexedCT(PrintStringIndexedCT &other) = delete;
    PrintStringIndexedCT(PrintStringIndexedCT &&other) = delete;
};


static constexpr char arr[] = "aLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";

int main()
{
    PrintStringIndexedCT<arr,sizeof(arr) - 1, 0>();
}

