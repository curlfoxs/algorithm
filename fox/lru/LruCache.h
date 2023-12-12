#ifndef LRUCACHE_H_
#define LRUCACHE_H_

#include "LruCachePrivate.h"

template<typename K, typename V>
class LruCache
{
public:
    LruCache() : m_implement(50) {};
    LruCache(int nSize) : m_implement(std::min(1000, nSize)) {};
    virtual ~LruCache() =  default;

    void insert(std::pair<K, V> pair) {
        return m_implement.insert(pair);
    }

    std::optional<V> get(K key) {
        return m_implement.get(key);
    }

    int currentSize() {
        return m_implement.currentSize();
    }

    int roomSize() {
        return m_implement.roomSize;
    }

    std::string repr() {
        return m_implement.repr();
    }

private:
    LruCachePrivate<K, V> m_implement;
};

#endif // LRUCACHE_H_
