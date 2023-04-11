//--------------------------------------------------------------
template <typename T, T VFirst, T VSecond>
constexpr bool IsEqual = (VFirst == VSecond);

#if __cplusplus >= 201700L
    template <auto I1, auto I2>
    constexpr bool IsEqualV = IsEqual<decltype(I1), I1, I2>;
    #define STATIC_ASSERT_MESSAGE_STUB
#else
    #define STATIC_ASSERT_MESSAGE_STUB , ""
#endif
//--------------------------------------------------------------


static_assert(IsEqual<int, 1, 1> == true STATIC_ASSERT_MESSAGE_STUB);
static_assert(IsEqual<int, 1, 2> == false STATIC_ASSERT_MESSAGE_STUB);
static_assert(IsEqual<int, 'a', 'a'> == true STATIC_ASSERT_MESSAGE_STUB);
static_assert(IsEqual<int, 'a', 'b'> == false STATIC_ASSERT_MESSAGE_STUB);
static_assert(IsEqual<int, 1, 2> == false STATIC_ASSERT_MESSAGE_STUB);

#if __cplusplus >= 201700L
static_assert(IsEqualV<1, 1> == true);
static_assert(IsEqualV<1, 2> == false);
static_assert(IsEqualV<'a', 'a'> == true);
static_assert(IsEqualV<'a', 'b'> == false);
static_assert(IsEqualV<1, 2> == false);

constexpr char SomeString[] = "Hello";
constexpr char SomeStringExtended[] = "Hello World";

static_assert(IsEqualV<SomeString[0], SomeStringExtended[0]> == true);
static_assert(IsEqualV<SomeString[1], SomeStringExtended[1]> == true);
static_assert(IsEqualV<SomeString[2], SomeStringExtended[2]> == true);
static_assert(IsEqualV<SomeString[3], SomeStringExtended[3]> == true);
static_assert(IsEqualV<SomeString[4], SomeStringExtended[4]> == true);
static_assert(IsEqualV<SomeString[5], SomeStringExtended[5]> == false);
#endif
