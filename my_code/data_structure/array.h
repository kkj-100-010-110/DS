#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <type_traits>

namespace MY
{
    template<typename T>
    class ARRAY
    {
    private:
        T* data_;
        size_t n_;
        size_t capacity_;

    public:
        /** Constructor */
        ARRAY() : n_(0), capacity_(0), data_(nullptr) {}
        /** Constructor */
        ARRAY(int n) : n_(n), capacity_(n)
        {
            data_ = new T[n];
            for (int i = 0; i < n_; ++i)
                data_[i] = 0;
        }
        /** Constructor */
        ARRAY(std::initializer_list<T> list) : n_(list.size()), capacity_(list.size())
        {
            data_ = new T[n_];
            int i = 0;
            for (auto it = list.begin(); it != list.end(); ++it)
                data_[i++] = *it;
        }
        /** Copy Constructor */
        ARRAY(const ARRAY<T>& other)
        {
            n_ = other.n_;
            capacity_ = other.capacity_;
            data_ = new T[n_];
            for (int i = 0; i < n_; ++i)
                data_[i] = other.data_[i];
        }
        /** Destructor */
        ~ARRAY() { delete[] data_; }
        /** Assignment Operator overloading */
        ARRAY<T>& operator=(const ARRAY<T>& other)
        {
            if (this != &other) {
                if (n_ < other.n_) {
                    delete[] data_;
                    n_ = other.n_;
                    data_ = new T[n_];
                    capacity_ = n_;
                    for (int i = 0; i < n_; ++i)
                        data_[i] = other.data_[i];
                } else {
                    int i, j;
                    for (i = 0; i < other.n_; ++i)
                        data_[i] = other.data_[i];
                    for (j = i; j < this->n_; ++j)
                        data_[j] = 0;
                    this->n_ = other.n_;
                }
            }
            return *this;
        }
        /** Subscript Operator Overloading */
        T& operator[](int idx) { return data_[idx]; }
        /** Const Subscript Operator Overloading */
        const T& operator[](int idx) const { return data_[idx]; }
        /** Return the pointer at the beginning of the data */
        T* begin() { return data_; }
        /** Return the const pointer at the beginning of the data */
        const T* begin() const { return data_; }
        /** Return the pointer at the end of the data */
        T* end() { return data_ + n_; }
        /** Return the const pointer at the end of the data */
        const T* end() const { return data_ + n_; }
        /** Return the ARRAY object that contains arr1's and arr2's elements */
        friend ARRAY<T> operator+(const ARRAY& arr1, const ARRAY& arr2)
        {
            ARRAY<T> result(arr1.size() + arr2.size());
            auto it = result.begin();
            for (auto it_loop = arr1.begin(); it_loop != arr1.end(); it_loop++, it++)
                *it = *it_loop;
            for (auto it_loop = arr2.begin(); it_loop != arr2.end(); it_loop++, it++)
                *it = *it_loop;
            return result;
        }
        /** Output streams << operator overloading */
        friend std::ostream& operator<<(std::ostream& os, const ARRAY<T>& arr)
        {
            if (arr.size() == 0)
                return (os << "");
            os << arr.data_[0];
            for (int i = 1; i < arr.size(); ++i)
                os << ", " << arr.data_[i];
            return os;
        }
        /** To get the value at the index of the array. */
        T& at(int idx)
        {
            if (idx < n_)
                return data_[idx];
            throw std::out_of_range("Index Out of Range in 'at()'");
        }
        /** To add the value at the end of the array. */
        void push_back(T value)
        {
            if (n_ < capacity_)
            {
                data_[n_] = value;
                n_++;
            }
            else
            {
                T* tmp = new T[capacity_ * 2];
                int i;
                for (i = 0; i < n_; i++)
                    tmp[i] = data_[i];
                tmp[i] = value;
                n_++;
                capacity_ *= 2;
                delete[] data_;
                data_ = tmp;
            }
        }
        /** To insert the value into the index of the array. */
        void insert(size_t idx, T value)
        {
            if (idx > n_)
                throw std::out_of_range("Index Out of Range in 'insert()'");
            n_++;
            if (n_ < capacity_)
            {
                for (int i = n_ - 1; idx < i; --i)
                    data_[i] = data_[i - 1];
                data_[idx] = value;
            }
            else
            {
                T* tmp = new T[capacity_ * 2];
                int i;
                for (i = 0; i < idx; i++)
                    tmp[i] = data_[i];
                tmp[i] = value;
                for (i += 1; i < n_; i++)
                    tmp[i] = data_[idx++];
                capacity_ *= 2;
                delete[] data_;
                data_ = tmp;
            }
        }
        /** To return the size of the array. */
        size_t size() const { return n_; }
        size_t capacity() const { return capacity_; }
    };
}

// generic usage for creating std::array
template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
    using commonType = typename std::common_type<Args...>::type;
    return {std::forward<commonType>((Args&&)args)...};
}


#endif//_ARRAY_H_