#ifndef LRUCACHEPRIVATE_H_
#define LRUCACHEPRIVATE_H_

#include <optional>
#include <map>

// 利用SFINAE原则定义一个类型萃取器（type trait），用于检查是否可以从T类型构造std::string
template<typename T, typename = void>
struct can_construct_string : std::false_type {};

template<typename T>
struct can_construct_string<T, std::void_t<decltype(std::string(std::declval<T>()))>> : std::true_type {};


template<typename K, typename V>
struct LinkNode
{
    LinkNode() = default;
    LinkNode(K k, V v) :  key(k), val(v) {};
    struct LinkNode<K, V>* prev = nullptr;
    struct LinkNode<K, V>* next = nullptr;
    K key;
    V val;
};

template<typename K, typename V>
struct LinkList
{
    LinkList() :  headNode(new struct LinkNode<K, V>()), tailNode(headNode) {};
    struct LinkNode<K, V>* headNode; // 头结点标兵， next指向链表中第一个node
    struct LinkNode<K, V>* tailNode; // 表示链表中最后一个node
};

template<class K, class V>
class LruCachePrivate
{
public:
    LruCachePrivate(int size) : m_size(size) { m_map.clear(); };

    void insert(std::pair<K, V> pair);
    std::optional<V> get(K key);
    int currentSize();
    int roomSize();
    std::string repr() {
        if (!can_construct_string<V>::value) {
            return "";
        }
        std::string res;
        res += "[";
        struct LinkNode<K, V>* p = m_list.headNode;
        while (p->next) {
            p = p->next;
            res += std::string(p->val);
            res += ", ";
        }
        res += "]\n";
        return res;
    }

private:
    void deleteTail();
    void moveHead(struct LinkNode<K, V> * node);
    void insertHead(struct LinkNode<K, V> * node);

private:
    int m_size = 50;
    std::map<K, struct LinkNode<K, V> *> m_map;
    struct LinkList<K, V> m_list;
};



#include "LruCachePrivate.hpp"

#endif // LRUCACHEPRIVATE_H_
