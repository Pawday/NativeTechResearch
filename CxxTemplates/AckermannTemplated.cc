#include <cstdint>
#include <iostream>

template <uint64_t M, uint64_t N>
struct Ackermann;


template <uint64_t N>
struct Ackermann<0, N>
{
    static constexpr uint64_t VAL = N + 1;
};

template <uint64_t M>
struct Ackermann<M, 0>
{
    static constexpr uint64_t VAL = Ackermann<M - 1, 1>::VAL;
};


template <uint64_t M, uint64_t N>
struct Ackermann
{
    static constexpr uint64_t VAL = Ackermann<M - 1, Ackermann<M, N - 1>::VAL>::VAL;
};

uint64_t AckermannRT(uint64_t m, uint64_t n)
{
    if (m == 0) return n + 1;
    if (n == 0) return AckermannRT(m - 1, 1);
    return AckermannRT(m - 1, AckermannRT(m, n - 1));
}

int main()
{
    uint64_t compileTimeDecidable = Ackermann<2,1>::VAL;
    std::cout << compileTimeDecidable << '\n';

    uint64_t runtimeDecidable = AckermannRT(2, 1);
    std::cout << runtimeDecidable << '\n';

//    uint64_t compileTimeOverflow = Ackermann<4,2>::VAL;
//    std::cout << compileTimeOverflow << '\n';

    uint64_t probablyRuntimeStackOverflow = AckermannRT(4, 2);
    std::cout << probablyRuntimeStackOverflow << '\n';
}