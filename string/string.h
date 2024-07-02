
#ifndef STRING_H
#define STRING_H

#include <ostream>

namespace wstd {

    class string {
    public:
        explicit string(const char* _data) : size(sizeof(_data)), capacity(sizeof(_data)) {
            data = new char[sizeof(_data)];
            for (size_t i = 0; i < size; i++) {
                data[i] = _data[i];
            }
        }

        ~string() {
            delete [] data;
        }

        void append(const char* newString) {
            const size_t newSize = size + sizeof(newString);
            if (newSize >= capacity) {
                resize(newSize + capacity / 2);
            }

            for (size_t i = size; i < newSize; i++) {
                data[i] = newString[i];
                size++;
            }

            size = newSize;
        }

        void resize(const size_t newCapacity) {
            auto newData = new char[newCapacity * sizeof(char)];
            capacity = newCapacity;

            for (size_t i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }

            delete [] data;

            data = newData;
        }

        char& operator [] (const size_t index) const {
            return data[index];
        }

        [[nodiscard]] size_t get_size() const { return size; }

        [[nodiscard]] char* get_string() const { return data; }

    private:
        char* data{};
        size_t size{};
        size_t capacity{};
    };

    inline std::ostream& operator << (std::ostream& ostream, const string& str) {
        return ostream << str.get_string();
    }

}

#endif //STRING_H