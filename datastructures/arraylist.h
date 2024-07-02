
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <memory>

namespace wstd {
    template<typename T>
class arraylist {
    public:
        arraylist() = default;

        explicit arraylist(const size_t initCapacity) : capacity(initCapacity) {
            array = static_cast<T*>(::operator new [](sizeof(T) * capacity));
        }

        arraylist(arraylist<T>& other) : array(other.array), size(other.size), capacity(other.capacity) {
            std::cout << "array list copy constructor\n";
        }

        arraylist(arraylist<T>&& other)  noexcept : size(other.size), capacity(other.capacity) {
            array = std::move(other.array);
            std::cout << "array list move constructor\n";
        }

        ~arraylist() {
            for (size_t i = 0; i < capacity; i++) {
                array[i].~T();
            }
        }

        [[nodiscard]] size_t get_size() const { return size; }

        void resize(const size_t newCapacity) {
            T* newArray = static_cast<T*>(::operator new [](newCapacity * sizeof(T)));
            capacity = newCapacity;

            for (size_t i = 0; i < capacity; i++) {
                newArray[i] = std::move(array[i]);
                array[i].~T();
            }

            delete [] array;

            array = newArray;
        }

        void push_back(T& newData) {
            if (size >= capacity) {
                resize(capacity + capacity / 2);
            }

            array[size] = std::move(newData);
            size++;
        }

        T& operator [] (const size_t index) {
            return array[index];
        }

    private:
        T* array{};
        size_t size = 0;
        size_t capacity{};
    };
}

#endif //ARRAYLIST_H
