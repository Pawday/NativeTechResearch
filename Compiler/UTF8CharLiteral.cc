#include <iostream>
#include <bitset>



#ifdef U8_WITH_MSVC
    #define HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS 1

    //allow emoji for testing MSVC compiler on "Compiler Error C2015"
    #ifndef ALLOW_EMOJI
        #define ALLOW_EMOJI 0
    #endif
#else
    #define HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS 0
#endif



#if HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS
    #define CHAR_LITERAL_MATH_PI 'π'
    #define CHAR_LITERAL_MAN '♂'
    #define CHAR_LITERAL_WOMAN '♀'
    #define CHAR_LITERAL_GBAKURUNEN '߷'
#if ALLOW_EMOJI
    #define CHAR_LITERAL_PRIDE_FLAG '🏳️‍🌈'
#endif
#else
    #define CHAR_LITERAL_MATH_PI '?'
    #define CHAR_LITERAL_MAN '?'
    #define CHAR_LITERAL_WOMAN '?'
    #define CHAR_LITERAL_GBAKURUNEN '?'
    #define CHAR_LITERAL_PRIDE_FLAG '?'
#endif

template <typename LITERAL_T>
void PrintLiteralMeta(const std::string &name, LITERAL_T val)
{
    std::cout << "Meta of " << name << std::endl;
    std::cout << "Number: " << val << std::endl;
    std::cout << "Bits: 0b" << std::bitset<sizeof(LITERAL_T) * 8>(val) << std::endl;
    std::cout << "____representation_start" << std::endl;
    std::cout.write((char*) &val, sizeof(val));
    std::cout << std::endl;
    std::cout << "____representation_end_" << std::endl;
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

#if ALLOW_EMOJI
    auto pride_v = CHAR_LITERAL_PRIDE_FLAG;
#endif

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
    std::cout << std::endl;
#if ALLOW_EMOJI
    PrintLiteralMeta("CHAR_LITERAL_PRIDE_FLAG", pride_v);
    std::cout << std::endl;
#endif


#endif // #else !HAS_SUPPORT_FOR_UTF8_CHAR_LITERALS
    return 0;
}