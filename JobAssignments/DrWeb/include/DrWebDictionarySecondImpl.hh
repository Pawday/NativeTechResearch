#include "DrWebDictionary.hh"

#include <unordered_map>


#if __cplusplus >= 202002L
#include <concepts>

#define IF_CPP20_REQUIRES_KW requires

template<typename Key>
concept Hashable = requires(const Key &inst){{std::hash<Key>()(inst)} -> std::same_as<size_t>;};

template <typename T>
struct THashOpType {using Type = size_t (std::hash<T>::*)(const T &) const;};

template <typename K>
concept HashCallOpIsConst = requires {std::same_as<decltype(&std::hash<K>::operator()), typename THashOpType<K>::Type>;};

#define KEY_CONSTRAINTS(KEY_TYPE) \
std::copy_constructible<KEY_TYPE> && Hashable<KEY_TYPE> && HashCallOpIsConst<KEY_TYPE> && std::equality_comparable<KEY_TYPE>

#else // STDCPP < 2020
#define IF_CPP20_REQUIRES_KW
#define KEY_CONSTRAINTS(KEY_TYPE)
#endif


template <typename Key, typename Value>
IF_CPP20_REQUIRES_KW KEY_CONSTRAINTS(Key)
class DictionaryImplSTDUnorderedMap : dictionary<Key, Value>
{
    std::unordered_map<Key, Value> _container;

public:

    const Value &get(const Key &key) const noexcept(false) override
    {
        if (!this->is_set(key))
            throw DictImplSTDUnorderedMapNotFoundException<Key>(key);

        return this->_container.at(key);
    }

    void set(const Key &key, const Value &value) override
    {
        _container.insert_or_assign(key, value);
    }

    bool is_set(const Key &key) const noexcept override
    {
        if (this->_container.empty()) return false;
        if (this->_container.find(key) == this->_container.end()) return false;

        return true;
    }
};


template<typename Key>
IF_CPP20_REQUIRES_KW KEY_CONSTRAINTS(Key)
class DictImplSTDUnorderedMapNotFoundException : public not_found_exception<Key>
{
    const Key _key;

public:
    DictImplSTDUnorderedMapNotFoundException() = delete;
    explicit DictImplSTDUnorderedMapNotFoundException(const Key& keyRef) : _key(keyRef) {}

public:

    const Key &get_key() const noexcept override
    {
        return _key;
    }
};

#undef IF_CPP20_REQUIRES_KW
#undef KEY_CONSTRAINTS