#include <DrWebDictionarySecondImpl.hh>


#include <string>

class TestKey
{
    int _id;

public:
    explicit TestKey(int id) : _id(id) {}
    TestKey(const TestKey &other) = default;
    TestKey(TestKey &&other) = default;

    bool operator==(const TestKey &other) const
    {
        return this->_id == other._id;
    }

    [[nodiscard]] size_t hash() const
    {
        return this->_id;
    }
};


template <>
class std::hash<TestKey>
{
public:
    size_t operator()(const TestKey &keyRef) const
    {
        return keyRef.hash();
    }
};



struct TestValue
{
    TestValue() = default;
//    TestValue(const TestValue &other) = delete;
//    TestValue(TestValue &&other) = default;
    std::string str;
};

int main()
{
    DictionaryImplSTDUnorderedMap<TestKey, TestValue> map;

    TestValue a;
    TestValue b;
    
    a.str = "Hello";
    b.str = "World";

    map.set(TestKey(131), a);
    map.set(TestKey(132), b);


    bool has1 = map.is_set(TestKey(1));
    bool has131 = map.is_set(TestKey(131));
    bool has132 = map.is_set(TestKey(132));

    const TestValue &valueA = map.get(TestKey(131));
    const TestValue &valueB = map.get(TestKey(132));
    
    try
    {
        const TestValue &valueNot = map.get(TestKey(1));
    } catch (const not_found_exception<TestKey> &e)
    {
        const TestKey &key = e.get_key();
    }
    
    
}