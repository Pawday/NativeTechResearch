#include <iostream>
#include <string>



#ifdef U8_WITH_MSVC
    #define HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS 1
#else
    #define HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS 0
#endif



#if HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS
    #define CHAR_LITERAL_MATH_PI 'π'
    #define CHAR_LITERAL_MAN '♂'
    #define CHAR_LITERAL_WOMAN '♀'
    #define CHAR_LITERAL_GBAKURUNEN '߷'
#else
    #define CHAR_LITERAL_MATH_PI '?'
    #define CHAR_LITERAL_MAN '?'
    #define CHAR_LITERAL_WOMAN '?'
    #define CHAR_LITERAL_GBAKURUNEN '?'
#endif

template <typename LITERAL_T>
void PrintLiteralMeta(std::string name, LITERAL_T val)
{
    std::cout << "Meta of " << name << std::endl;
    std::cout << "val=" << val << std::endl;
    std::cout << "representation_start" << std::endl;
    std::cout.write((char*) &val, sizeof(val));
    std::cout << std::endl;
    std::cout << "representation_end" << std::endl;
}

int main()
{
#if !HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS
    std::cout << "This program compiled without support of utf8 char literals" << std::endl;
    std::cout << "Exit seminormaly" << std::endl;
    return 0;
#else

    auto gbakurunen_v = CHAR_LITERAL_GBAKURUNEN;
    auto pi_v = CHAR_LITERAL_MATH_PI;
    auto man_v = CHAR_LITERAL_MAN;
    auto woman_v = CHAR_LITERAL_WOMAN;

    std::cout << "Typeof literal is "<< typeid(gbakurunen_v).name() << std::endl;
    std::cout << "sizeof literal is "<< sizeof(gbakurunen_v) <<  std::endl;

    std::cout << std::endl << std::endl;

    PrintLiteralMeta("CHAR_LITERAL_GBAKURUNEN", gbakurunen_v);
    std::cout << std::endl;

    PrintLiteralMeta("CHAR_LITERAL_MATH_PI", pi_v);
    std::cout << std::endl;

    PrintLiteralMeta("CHAR_LITERAL_MAN", man_v);
    std::cout << std::endl;

    PrintLiteralMeta("CHAR_LITERAL_WOMAN", woman_v);


#endif // #else !HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS
    return 0;
}