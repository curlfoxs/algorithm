#include <iostream>
#include "LruCache.h"

int main(int argc, char *argv[]) {
    LruCache<std::string, std::string> lruCache(4);
    lruCache.insert({"1", "keke1.img"});
    std::cout << lruCache.repr();
    lruCache.insert({"2", "keke2.img"});
    std::cout << lruCache.repr();
    lruCache.insert({"3", "keke3.img"});
    std::cout << lruCache.repr();
    std::cout << lruCache.get("1").value_or("") << std::endl;
    std::cout << lruCache.repr();
    lruCache.insert({"4", "keke4.img"});
    std::cout << lruCache.repr();
    lruCache.insert({"5", "keke5.img"});
    std::cout << lruCache.repr();
    lruCache.insert({"6", "keke6.img"});
    std::cout << lruCache.repr();
    lruCache.insert({"7", "keke7.img"});
    std::cout << lruCache.repr();
    return 0;
}
