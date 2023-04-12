#include <string>
#include <utility>
#include <iostream>
#include <unordered_map>

class Key
{
public:
    explicit Key(uint32_t id): _keyId(id) {}

    bool operator< (const Key& other) const
    {
        return this->_keyId < other._keyId;
    }

    bool operator== (const Key& other) const
    {
        return this->_keyId == other._keyId;
    }


private:
    uint32_t _keyId;

    friend std::hash<Key>;
};

template <>
class std::hash<Key>
{
public:
    std::size_t operator()(const Key& key) const;
};

std::size_t std::hash<Key>::operator()(const Key &key) const
{
    return key._keyId;
}


class Value
{
public:

    Value() = default;
    explicit Value (std::string &str) : str(str) {}
    explicit Value (std::string &&str) : str(std::move(str)) {}

private:
    std::string str;
};

int main()
{
    Key k(256);
    Key k2(257);

    std::unordered_map<Key,Value> map;
    
    Value val("masp");
    Value val2("new");

    bool status;
    status = map.try_emplace(k, val).second;
    status = map.try_emplace(k2, val2).second;



    
    std::cout << "Hash of key is: " << 2 << '\n';
   

    return 0;
}
