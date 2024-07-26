
#ifndef STRING_H
#define STRING_H

#include <cassert>
#include <ostream>

namespace wstd {
    inline size_t strlen(const char* str) {
        size_t length = 0;
        while(*str != '\0') {
            str++;
            length++;
        }
        return length;
    }

    inline void strcpy(const char* src, char* dst) {
        const size_t srcSize = wstd::strlen(src);
        for (size_t i = 0; i < srcSize; i++) {
            dst[i] = src[i];
        }
    }

    class string;
    size_t strlen(const wstd::string& str);

    class string {
    public:

        string() = default;

        string(const char* _str) {
            size = strlen(_str);
            str = new char[size + 1];
            wstd::strcpy(_str, str);
        }

        ~string() {
            delete [] str;
        }

        void resize(const size_t newSize) {
            const auto newString = new char[newSize + 1];
            size = newSize;
            strcpy(str, newString);

            delete [] str;
            str = newString;
        }

        void append(const char* newData) {
            const size_t oldSize = size;

            if (strlen(newData) + size >= size) {
                resize(strlen(newData) + size);
            }

            for (size_t i = oldSize; i < size; i++) {
                str[i] = newData[i - oldSize];
            }
        }

        void append(const wstd::string& newData) {
            const size_t oldSize = size;

            if (strlen(newData) + size >= size) {
                resize(strlen(newData) + size);
            }

            for (size_t i = oldSize; i < size; i++) {
                str[i] = newData[i - oldSize];
            }
        }

        [[nodiscard]] size_t get_size() const {
            return size;
        }

        [[nodiscard]] const char* get_string() const {
            return str;
        }

        char& operator [] (const size_t index) const {
            assert(str != nullptr);
            return str[index];
        }

        string& operator = (const char* _str) {
            wstd::strcpy(_str, str);
            return *this;
        }

    private:
        size_t size{};
        char* str{};
    };

    inline std::ostream& operator << (std::ostream& ostream, const wstd::string& str) {
        ostream << str.get_string();
        return ostream;
    }

    inline const char* operator + (const wstd::string& left, const wstd::string& right) {
        wstd::string string;
        string.append(left.get_string());
        string.append(right.get_string());
        return string.get_string();
    }

    inline const char* operator + (const wstd::string& string, const char* str) {
        wstd::string ret = string.get_string();
        ret.append(str);
        return ret.get_string();
    }

    inline size_t strlen(const wstd::string& str) {
        return str.get_size();
    }

    inline void strcpy(const wstd::string& src, const wstd::string& dst) {
        const size_t srcSize = src.get_size();
        for (size_t i = 0; i < srcSize; i++) {
            dst[i] = src[i];
        }
    }
}

#endif //STRING_H