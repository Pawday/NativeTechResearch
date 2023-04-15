#include <iostream>
#include <functional>


template <typename T>
class Lazy
{
public:
    using FunctionType = T (*)();

private:
    const FunctionType _f;

public:
    Lazy() = delete;
    Lazy(Lazy &other) = delete;
    Lazy(Lazy &&other) : _f(other._f){};

    explicit Lazy(const Lazy::FunctionType &valueProvider) : _f(valueProvider) {};

    T operator()() const {return this->_f();}

    friend std::ostream& operator<<(std::ostream &os, const Lazy<T> &val)
    {
        return os << val();
    }
};

//Lazy<int> operator+(const Lazy<int> &l, const Lazy<int> &r)
//{
//    Lazy<int> lazy([&l](){return 1;});
//
//    return lazy;
//}


typedef int(*IntProvider)();

extern "C" int oneProvider(void)
{
    return 1;
}


template <typename T>
concept Callable = requires (T a) {a();};


template<Callable FunT>
void PrintType(FunT inst)
{
    std::cout << typeid(inst).name() << std::endl;
}



int main()
{
    int captureV = 0xdead;
    auto lambdaWithoutCapture = [](){return 10;};
    auto lambdaWithCapture = [captureV](){return captureV;};



    PrintType(lambdaWithoutCapture);
    PrintType(lambdaWithCapture);

    return 0;

    Lazy<int> a([](){return 40;});
    Lazy<int> b([]() {return 50;});


    std::cout << "a = " << a << " | b = " << b << std::endl;

//    std::cout << a + b << std::endl;

}