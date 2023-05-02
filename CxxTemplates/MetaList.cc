#define METABOOL static constexpr bool


template <typename ...Elems>
struct MetaList;

template <typename Single>
struct MetaList<Single>
{
    using Head = Single;
};

template <typename First, typename ... Rest>
struct MetaList<First, Rest...>
{
    using Head = First;
    using Tail = MetaList<Rest...>;
};

template <typename A, typename B>
METABOOL AreSame = false;

template <typename One>
METABOOL AreSame<One,One> = true;

template <typename A, typename B>
METABOOL AreNotSame = false == AreSame<A,B>;

static_assert(AreNotSame<int, float>);
static_assert(!AreNotSame<int, int>);
static_assert(AreSame<int, int>);

using LongDouble = MetaList<long, double>;
using DoubleLong = MetaList<double, long>;

static_assert(AreSame<MetaList<int,int>, MetaList<int,int>>);
static_assert(AreNotSame<MetaList<int,int>, MetaList<int,double>>);

template <typename T, typename ... MetaListContent>
METABOOL IsMetaList = AreSame<MetaList<MetaListContent...>,T>;

template <typename ...T>
METABOOL IsSingledMetaList = false;

template <typename Input, typename AnyType>
METABOOL IsSingledMetaList<Input, AnyType> = AreSame<MetaList<AnyType>, Input>;


//TODO: make assertion below work
static_assert(false == IsSingledMetaList<MetaList<float>>);
static_assert(false == IsMetaList<MetaList<int,long>>);


LongDouble swap(DoubleLong value)
{
    LongDouble ret;

    return ret;
}

DoubleLong swap(LongDouble value)
{
    DoubleLong ret;

    return ret;
}



int main()
{

}