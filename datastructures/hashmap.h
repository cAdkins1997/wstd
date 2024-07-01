
#ifndef HASHMAP_H
#define HASHMAP_H
#include <cmath>

namespace wstl {
    namespace hash {
        template<typename K, typename V>
        struct node {
            K key;
            V value;
            node* next{};
        };

        template <typename K>
        struct keyhash {
            size_t operator()(const K& key) const {
                unsigned int x = key;
                x ^= x << 13;
                x ^= x >> 17;
                x ^= x << 55;
                return key = x;
            }
        };
    }

    using namespace hash;
    template<typename K, typename V, typename F = keyhash<K>>
    class hashmap {
    public:
        explicit hashmap(const size_t initSize) : size(initSize) {
            table = new node<K, V> *[initSize]();
        }

        ~hashmap() {
            for (size_t i = 0; i < size; i++) {
                node<K, V> *entry = table[i];
                while (entry != nullptr) {
                    node<K, V> *previous = entry;
                    entry = entry->next;
                    delete previous;
                }
                table[i] = nullptr;
            }
            delete [] table;
        }

        void put(const K &key, const V& value) {
            size_t hashValue = hashFunction(key);
            node<K, V> *previous = nullptr;
            node<K, V> *entry = table[hashValue];

            while(entry != nullptr && entry->key != key) {
                previous = entry;
                entry = entry->next;
            }

            if (entry == nullptr) {
                entry = new node<K, V>(key, value);
                if (previous == nullptr) {
                    table[hashValue] = entry;
                }
                else {
                    previous->next = entry;
                }
            }
            else {
                entry->value = value;
            }
        }

    private:
        node<K, V> **table;
        F hashFunction;
        size_t size;
    };

}



#endif //HASHMAP_H
