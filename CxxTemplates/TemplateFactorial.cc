#include <iostream>

template<int n>
struct Factorial
{
	static constexpr int value = n * Factorial<n - 1>::value;
};

template<>
struct Factorial<1>
{
	static constexpr int value = 1;
};


static int fac_3 = Factorial<3>::value;
static int fac_5 = Factorial<5>::value;


int main()
{
	std::cout << fac_3 << '\n';
	std::cout << fac_5 << '\n';
}