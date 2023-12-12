
template<typename K, typename V>
void LruCachePrivate<K, V>::insert(std::pair<K, V> p)
{
    if (roomSize() <= 0)
    {
        return;
    }

    while (currentSize() >= roomSize())
    {
        deleteTail();
    }

    auto node = new struct LinkNode<K, V>(p.first, p.second);
    m_map[p.first] = node;
    insertHead(node);
}

template<typename K, typename V>
std::optional<V> LruCachePrivate<K, V>::get(K key)
{
    auto p = m_map.find(key);
    if (p != m_map.end()) {
        struct LinkNode<K, V> * node = p->second;
        moveHead(node);
        return node->val;
    }
    else {
        return std::nullopt;
    }
}

template<typename K, typename V>
int LruCachePrivate<K, V>::currentSize()
{
    return m_map.size();
}

template<typename K, typename V>
int LruCachePrivate<K, V>::roomSize()
{
    return m_size;
}

template<typename K, typename V>
void LruCachePrivate<K, V>::deleteTail()
{
    if (currentSize() > 0 && m_list.tailNode != m_list.headNode && m_list.tailNode != nullptr) { // 双重保险
        auto p = m_list.tailNode;
        m_list.tailNode = p->prev;
        m_list.tailNode->next = nullptr;
        // 删除值，需要遍历键
        m_map.erase(p->key);
        delete p;
    }
}

template<typename K, typename V>
void LruCachePrivate<K, V>::moveHead(struct LinkNode<K, V> * node)
{
    if (node->prev == m_list.headNode || currentSize() <= 1) {
        return;
    }

    if (node->next == nullptr) {
        m_list.tailNode = node->prev;
        m_list.tailNode->next = nullptr;
    }
    else {
        auto tmpNode = node->prev;
        tmpNode->next = node->next;
        node->next->prev = tmpNode;
    }

    auto firstNode = m_list.headNode->next;
    m_list.headNode->next = node;
    node->prev = m_list.headNode;
    node->next = firstNode;
    firstNode->prev = node;
}

template<typename K, typename V>
void LruCachePrivate<K, V>::insertHead(struct LinkNode<K, V> * node)
{
    if (nullptr == node) {
        return;
    }

    auto h = m_list.headNode->next;
    m_list.headNode->next = node;
    node->next = h;
    node->prev = m_list.headNode;
    if (nullptr != h) {
        h->prev = node;
    }
    else {
        m_list.tailNode = node;
    }
}
