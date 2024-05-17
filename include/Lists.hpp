#pragma once

#include <iostream>
#include <random>

template <typename T>
struct NodeList {
    NodeList *next_, *prev_;
    T value_;

    NodeList(const T &value) :
        next_(nullptr), prev_(nullptr), value_(value) {}
};

template <typename T> class list {
private:
    NodeList<T> *first_, *last_;
    std::size_t size_;

public:
    list() :
        first_(nullptr), last_(nullptr), size_(0) {}

    list(const list<T> &other) {
        for (std::size_t i = 0; i < other.size_; i++)
            push_back(other(i));
    }

    list(list<T> &&other) {
        size_ = other.size_;
        first_ = other.first_;
        last_ = other.last_;

        other.size_ = 0;
        other.first_ = nullptr;
        other.last_ = nullptr;
    }

    ~list() {
        clear();
    }

    void clear() {
        while (size_ > 0)
            pop_back();
    }

    std::size_t get_size() {
        return size_;
    }

    void push_back(const T &value) {
        NodeList<T> *p = new NodeList<T>(value);
        if (size_ == 0) {
            first_ = p;
            last_ = p;
        } else {
            last_->next_ = p;
            p->prev_ = last_;
        }
        size_++;
    }

    void push_front(const T &value) {
        NodeList<T> *p = new NodeList<T>(value);
        if (size_ == 0) {
            first_ = p;
            last_ = p;
        } else {
            first_->prev_ = p;
            p->next_ = first_;
        }
        size_++;
    }

    T pop_back() {
        if (size_ == 0)
            throw std::logic_error("This list is empty!");

        T res = 0;

        if (size_ == 1) {
            res = first_->value_;
            delete first_;
            first_ = nullptr;
            last_ = nullptr;
            size_ = 0;
        } else {
            res = last_->value_;
            last_ = last_->prev_;
            delete last_->next_;
            last_->next_ = nullptr;
        }

        return res;
    }

    T pop_front() {
        if (size_ == 0)
            throw std::logic_error("This list is empty!");

        T res = 0;

        if (size_ == 1) {
            res = first_->value_;
            delete first_;
            first_ = nullptr;
            last_ = nullptr;
            size_ = 0;
        } else {
            res = first_->value_;
            first_ = first_->next_;
            delete first_->prev_;
            first_->prev_ = nullptr;
        }

        return res;
    }

    void fill(const T &value) {
        NodeList<T> *p = first_;
        for (std::size_t i = 0; i < size_; i++) {
            p->value_ = value;
            p = p->next_;
        }
    }

    T operator()(std::size_t index) const {
        if (size_ == 0)
            throw std::logic_error("This list is empty!");
        else if (index >= size_)
            throw std::logic_error("The index is larger than size of the list!");

        NodeList<T> *res = nullptr;

        if (index == 0)
            res = first_;
        else if (index == size_ - 1)
            res = last_;
        else if (index < size_) {
            res = first_;
            if (index < size_ / 2)
                for (std::size_t i = 0; i < index; i++)
                    res = res->next_;
            else
                for (std::size_t i = size_ - 1; i >= index; i--)
                    res = res->prev_;
        }

        return res->value_;
    }

    void print() {
        for (std::size_t i = 0; i < size_; i++)
            std::cout << (*this)(i) << " ";
        std::cout << std::endl;
    }

    std::size_t merge(const list<T> &a, const list<T> &b, list<T> &c) {
        std::size_t move_copare = 0;

        c.clear();

        std::size_t size_a = a.size_, size_b = b.size_;
        std::size_t i = 0, j = 0;

        while (size_a != 0 && size_b != 0) {
            if (a(i) <= b(j)) {
                c.push_back(a(i++));
                size_a--;
            } else {
                c.push_back(b(j++));
                size_b--;
            }
            move_copare += 2;
        }
        while (size_a > 0) {
            c.push_back(a(i++));
            size_a--;
            move_copare++;
        }
        while (size_b > 0) {
            c.push_back(b(j++));
            size_b--;
            move_copare++;
        }

        return move_copare;
    }

    std::size_t split(list<T> &a, list<T> &b) { // возможно не работает
        std::size_t move_compare = 0;

        a.clear();
        b.clear();

        a.first_ = first_;
        b.first_ = first_->next_;
        move_compare += 2;

        NodeList<T> *pointer_a = a.first_;
        NodeList<T> *pointer_b = b.first_;
        move_compare += 2;

        while (pointer_b != nullptr) {
            pointer_a->next_ = pointer_b->next_;
            pointer_a = pointer_b;
            pointer_b = pointer_b->next_;
            move_compare += 3;
        }

        return move_compare;
    }

    std::size_t merge_sort() { // не работает
        std::size_t move_copare = 0;

        list<T> a, b, c0, c1;

        move_copare += split(a, b);
        std::size_t p = 1;
        while (p < this->size_) {
            c0.clear();
            c1.clear();

            std::size_t i = 0, m = this->size_;

            while (m > 0) {
                std::size_t q = 0, r = 0;

                if (m >= p)
                    q = p;
                else
                    q = m;
                m -= q;

                if (m >= p)
                    r = p;
                else
                    r = m;
                m -= r;

                move_copare += merge(a, b, (i == 1 ? c1 : c0));
                i = 1 - i;
            }
            a.first_ = c0.first_;
            b.first_ = c1.first_;
            p *= 2;
        }
        c0.last_->next_ = nullptr;
        this->first_ = c0.first_;

        return move_copare;
    }

    void fill_inc(std::size_t size) {
        clear();
        for (std::size_t i = 0; i < size; i++)
            push_back(i);
    }
};

template <typename T> class stack {
private:
    NodeList<T> *first_, *last_;
    std::size_t size_;

public:
    stack() :
        first_(nullptr), last_(nullptr), size_(0) {}

    stack(const stack<T> &other);
    stack(stack<T> &&other);
    ~stack();

    void clear();
    std::size_t get_size();
    void push(const T &value);
    T pop();
    T check();

    void fill_inc(std::size_t size);
    void fill_dec(std::size_t size);
    void fill_rand(std::size_t size);
};

template <typename T> class queue {
private:
    NodeList<T> *first_, *last_;
    std::size_t size_;

public:
    queue() :
        first_(nullptr), last_(nullptr), size_(0) {}

    queue(const queue<T> &other);
    queue(queue<T> &&other);
    ~queue();

    void clear();
    std::size_t get_size();
    void push(const T &value);
    T pop();
    T check();

    void fill_inc(std::size_t size);
    void fill_dec(std::size_t size);
    void fill_rand(std::size_t size);
};
