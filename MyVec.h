#ifndef MY_VEC
#define MY_VEC
#include <stdlib.h>
#include <memory>
#include <exception>

template<typename T>
class vector {
public:
    constexpr vector() noexcept;
    constexpr vector(std::initializer_list<T>) noexcept;
    constexpr vector(int) noexcept;
    constexpr vector(const vector<T>&) noexcept;
    constexpr vector(int, T&) noexcept;
    constexpr vector(const vector<T>&&) noexcept;
    constexpr void print() noexcept;
    ~vector() noexcept;
    constexpr void pop_back();
    constexpr void push_back(T);
    constexpr size_t size_ret() const;
    constexpr void clear() noexcept;
    constexpr T* begin() const;
    constexpr T* end() const;
    constexpr T operator[](const int);
    constexpr bool empty();
    constexpr void operator=(vector<T>&);
    constexpr void reserve(int);
    constexpr T* insert(T*, const T&);
    constexpr T* insert(T*, const T&&);
    constexpr T* insert(T*, size_t, const T&);
    constexpr T* insert(T*, std::initializer_list<T>);
    friend std::ostream& operator<<(std::ostream& os, vector<T> vec)  {
        for(int i = 0; i < vec.size; ++i) {
            os << vec.buf[i] << " ";
        }
        return os;
    } 
private:
    void allocator();
    void realloc();
    void realloc(size_t);
    size_t size;
    size_t capacity;
    T* buf = nullptr; 
};


#include "MyVec.hpp"
#endif //MY_VEC