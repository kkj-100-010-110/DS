#ifndef _MUSIC_LIST_H_
#define _MUSIC_LIST_H_

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

/**
 * @brief to design a music list
 *
 * 1. Design a container - Circular Doubly list
 * 2. Make insert and delete functions of the container
 * 3. User-defined iterator
 * 4. Design Play-list based on the container
 * 5. Member functions next(), previous(), printall(), remove()
 */
namespace MY
{
    template<typename T>
    struct MUSIC_LIST_NODE
    {
        T* data_;
        MUSIC_LIST_NODE* next_;
        MUSIC_LIST_NODE* prev_;

        ~MUSIC_LIST_NODE() { delete data_; }
    };

    template<typename T>
    struct MUSIC_LIST
    {
    public:
        using NODE = MUSIC_LIST_NODE<T>;
        using NODE_PTR = NODE*;
    private:
        NODE_PTR head_;
        size_t n_;
    public:
        MUSIC_LIST() : n_(0)
        {
            head_ = new NODE {NULL, NULL, NULL};
            head_->next_ = head_;
            head_->prev_ = head_;
        }
        size_t size() const { return n_; }

        void insert(const T& value)
        {
            NODE_PTR newNODE = new NODE {new T(value), NULL, NULL};
            n_++;
            auto dummy = head_->prev_;
            dummy->next_ = newNODE;
            newNODE->prev_ = dummy;
            if (head_ == dummy) {
                dummy->prev_ = newNODE;
                newNODE->next_ = dummy;
                head_ = newNODE;
                return;
            }
            newNODE->next_ = head_;
            head_->prev_ = newNODE;
            head_ = newNODE;
        }

        void erase(const T& value)
        {
            auto cur = head_, dummy = head_->prev_;
            while (cur != dummy) {
                if (*(cur->data_) == value) {
                    cur->prev_->next_ = cur->next_;
                    cur->next_->prev_ = cur->prev_;
                    if (cur == head_)
                        head_ = head_->next_;
                    delete cur;
                    n_--;
                    return;
                }
                cur = cur->next_;
            }
        }

        struct MUSIC_LIST_IT
        {
        private:
            NODE_PTR ptr_;
        public:
            MUSIC_LIST_IT(NODE_PTR p) : ptr_(p) {}
            T& operator*() { return *(ptr_->data_); }
            NODE_PTR get() { return ptr_; }
            MUSIC_LIST_IT& operator++()
            {
                ptr_ = ptr_->next_;
                return *this;
            }

            MUSIC_LIST_IT operator++(int)
            {
                MUSIC_LIST_IT it = *this;
                ++(*this);
                return it;
            }

            MUSIC_LIST_IT& operator--()
            {
                ptr_ = ptr_->prev_;
                return *this;
            }

            MUSIC_LIST_IT& operator--(int)
            {
                MUSIC_LIST_IT it = *this;
                --(*this);
                return it;
            }

            friend bool operator==(const MUSIC_LIST_IT& it1, const MUSIC_LIST_IT& it2)
            {
                return it1.ptr_ == it2.ptr_;
            }

            friend bool operator!=(const MUSIC_LIST_IT& it1, const MUSIC_LIST_IT& it2)
            {
                return it1.ptr_ != it2.ptr_;
            }
        };

        MUSIC_LIST_IT begin(){return MUSIC_LIST_IT {head_};}
        MUSIC_LIST_IT begin() const {return MUSIC_LIST_IT {head_};}
        MUSIC_LIST_IT end(){return MUSIC_LIST_IT {head_->prev_};}
        MUSIC_LIST_IT end() const {return MUSIC_LIST_IT {head_->prev_};}

        MUSIC_LIST(const MUSIC_LIST &other) : MUSIC_LIST()
        {
            for (const auto &e : other)
                insert(e);
        }

        MUSIC_LIST(const std::initializer_list<T> &list) : head_(NULL), n_(0)
        {
            for (const auto &e : list)
                insert(e);
        }

        ~MUSIC_LIST()
        {
            while (size())
                erase(*(head_->data_));
            delete head_;
        }
    };

    struct PLAYLIST
    {
        MY::MUSIC_LIST<std::string> list_;

        void insert(const std::string& song)
        {
            list_.insert(song);
        }

        void erase(const std::string& song)
        {
            list_.erase(song);
        }

        void loopOnce()
        {
            for (auto &song : list_)
                std::cout << song << " ";
            std::cout << std::endl;
        }
    };
}

#endif //_MUSIC_LIST_H_