#include <iostream>
#include "MyVec.h"

template<typename T>
constexpr vector<T>::vector() noexcept {
    capacity = 2;
    size = 1;
    allocator();
}

template<typename T>
constexpr vector<T>::vector(std::initializer_list<T> list) noexcept  {
    size = list.size();
    capacity = size * 2;
    allocator();
    for(int i = 0; i < size; ++i) {
        buf[i] = *(list.begin() + i);
    }
}

template<typename T>
constexpr vector<T>::vector(int size_in) noexcept {
    if(size_in <= 0) {
        std::cout << "invalid size" << "\n";
        return;
    }
    size = size_in;
    capacity = size * 2;
    allocator();
}

template<typename T>
constexpr vector<T>::vector(const vector<T>& other) noexcept {
    size = other.size;
    capacity = other.capacity;
    allocator();
    for(int i = 0; i < size; ++i) {
        buf[i] = other.buf[i];
    }
}

template<typename T>
constexpr vector<T>::vector(const vector<T>&& other) noexcept {
    size = other.size;
    capacity = other.capacity;
    allocator();
    for(int i = 0; i < size; ++i) {
        buf[i] = other.buf[i];
    }
}

template<typename T>
constexpr vector<T>::vector(int size_in, T& symbol) noexcept {
    if(size_in <= 0) {
        std::cout << "invalid size" << "\n";
        return;
    }
    size = size_in;
    capacity = size * 2;
    allocator();
    for(int i = 0; i < size; ++i) {
        buf[i] = symbol;
    }
}

template<typename T>
vector<T>::~vector() noexcept {
    delete[] buf;
    buf = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void vector<T>::realloc() {
    capacity += size;
    T* tmp = buf;
    allocator();
    for(int i = 0; i < size; ++i) {
        buf[i] = tmp[i];
    }
    delete[] tmp;
    tmp = nullptr;
}

template<typename T>
void vector<T>::realloc(size_t size) {
    capacity = size;
    allocator();
}

template<typename T>
void vector<T>::allocator() {
    buf = new T[capacity];
}

template<typename T>
constexpr void vector<T>::push_back(T obj) {
    ++size;
    if(size == capacity) {
        realloc();
    }
    buf[size - 1] = obj;
}

template<typename T>
constexpr void vector<T>::pop_back() {
    if(size == 0) {
        return;
    }
    --size;
}
template<typename T>
constexpr void vector<T>::print() noexcept {
    for(int i = 0; i < size; ++i) {
        std::cout << buf[i] << " ";
    }
}

template<typename T>
constexpr T* vector<T>::begin() const {
    if (buf) {
        return buf;
    }
    return nullptr;
}

template<typename T>
constexpr T* vector<T>::end() const{
    return buf + size_ret();
}
template<typename T>
constexpr size_t vector<T>::size_ret() const {
    return this->size;
}
template<typename T> 
constexpr void vector<T>::clear() noexcept{
    size = 0;
}
template<typename T>
constexpr void vector<T>::operator=(vector<T>& v1)  {
    if(v1.size > this->capacity) {
        this->capacity = v1.size;
        this->realloc();
    }
    for(int i = 0; i < v1.size; ++i) {
        this->buf[i] = v1.buf[i];
    }
}
template<typename T>
constexpr T vector<T>::operator[](const int index) {
    try {
        if(index > size - 1) {
            throw index;
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return buf[index];
}
template<typename T>
constexpr bool vector<T>::empty() {
    return size - 1;
}
template<typename T>
constexpr void vector<T>::reserve(int res_size) {
    realloc(res_size);
}
template<typename T> 
constexpr T* vector<T>::insert(T* pos, const T& value) {
    size++;
    int index = pos - begin();
    if(size == capacity) {
        realloc();
    }
    for(int i = size - 1; i >= index; --i) {
        buf[i + 1] = buf[i];
    }
    buf[index] = value;
    return pos;
}
template<typename T> 
constexpr T* vector<T>::insert(T* pos, const T&& value) {
    size++;
    int index = pos - begin();
    if(size == capacity) {
        realloc();
    }
    for(int i = size - 1; i >= index; --i) {
        buf[i + 1] = buf[i];
    }
    buf[index] = value;
    return pos;
}
template<typename T> 
constexpr T* vector<T>::insert(T* pos, size_t count, const T& value) {
    size += count;
    int index = pos - begin();
    if(size >= capacity) {
        realloc();
    }
    for(int i = size - 1; i >= index; --i) {
        buf[i + count] = buf[i];
    }
    for(int i = index; i < index + count; ++i) {
        buf[i] = value;
    }
    return pos;
}
template<typename T>
constexpr T* vector<T>::insert(T* pos, std::initializer_list<T> list) {
    size += list.size();
    int size_ = list.size();
    int index = pos - begin();
    if(size >= capacity) {
        realloc();
    }
    for(int i = size - 1; i >= index; --i) {
        buf[i + size_] = buf[i];
    }
    for(int i = index; i < index + size; ++i) {
        buf[i] = *(list.begin() + i);;
    }
    return pos;
}