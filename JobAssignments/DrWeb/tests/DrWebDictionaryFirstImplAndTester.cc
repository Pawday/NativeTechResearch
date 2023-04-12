#include <DrWebDictionary.hh>


#include <map>
// Реализация интерфейса dictionary из задания с использованием контейнера std::map

// Если используется 20-ый стандарт С++, то ограничим тип ключа для нашей реализации концептом
// В данном случае ограничением является возможность сравнить два класса ключа между собой и
// возможность скопировать ключ через его конструктор копирования
#if __cplusplus >= 202002L
template <typename T>
concept ConstComparable = requires(const T first, const T second)
{
    first < second;
};

template<typename Key>
concept FairKey = ConstComparable<Key> && std::copy_constructible<Key>;

#else
/*
 * Замена концепта FairKey с помощью макроса на ключевое слово typename для использования в шаблонах
 * при стандарте C++ ниже 20-ого
 * Техника позаимствована из обучающего пособия по STL и шаблонам
 * https://github.com/vjacquet/praxis/blob/a0558c1c4f569682792f317f9c94ff3167126fda/xp/fakeconcepts.h
*/
#define FairKey typename
#endif

template<FairKey Key, typename Value>
class DictionaryImplSTDMap : public dictionary<Key, Value>
{
    using ValueT = Value;
    std::map<Key, Value> _container;

public:
    const Value &get(const Key &key) const noexcept(false) override;
    void set(const Key &key, const Value &value) override;
    bool is_set(const Key &key) const noexcept override;
};

template<FairKey Key>
class NotFoundExceptionImpl : public not_found_exception<Key>
{
    const Key &_key;

public:
    explicit NotFoundExceptionImpl(const Key &key) : _key(key){}

    const Key &get_key() const noexcept override;
};

template<FairKey Key>
const Key &NotFoundExceptionImpl<Key>::get_key() const noexcept
{
    return this->_key;
}

template<FairKey Key, typename Value>
bool DictionaryImplSTDMap<Key, Value>::is_set(const Key &key) const noexcept
{
    if (this->_container.empty()) return false;
    if (this->_container.count(key) != 0) return true;
    return false;
}

template<FairKey Key, typename Value>
const Value &DictionaryImplSTDMap<Key, Value>::get(const Key &key) const noexcept(false)
{
    if (!this->is_set(key)) throw NotFoundExceptionImpl<Key>(key);
    return this->_container.at(key);
}

template<FairKey Key, typename Value>
void DictionaryImplSTDMap<Key, Value>::set(const Key &key, const Value &value)
{
    if (this->is_set(key))
    {
        this->_container[key] = value;
        return;
    }
    //Ключ будет скопирован в структуру через std::pair
    this->_container.insert(std::pair<Key, Value>(key, value));
}



class TheKey
{
    int val = 0;
public:
    explicit TheKey(int val) : val(val) {}

    TheKey(const TheKey &other) : val(other.val){}

    bool operator<(const TheKey &other) const
    {
        return this->val < other.val;
    }
};

int main()
{
    DictionaryImplSTDMap<TheKey,int> map;
    const TheKey key(1);
    TheKey key_nonExist(2);
    
    bool b = map.is_set(key);
    map.set(key, 11);
    b = map.is_set(key);

    int i = map.get(key);
    try
    {
        int i2 = map.get(key_nonExist);
    } catch (not_found_exception<TheKey> &exc)
    {
        const TheKey &theKey = exc.get_key();
    }

    map.set(key, 12);

    bool set = map.is_set(key_nonExist);

    set = map.is_set(key_nonExist);

    
    return 0;

}



