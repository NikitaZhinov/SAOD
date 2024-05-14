#include <print>
#include <random>

export module Contaners;

export template <typename T> class list {
private:
    struct Node {
        Node *next_, *prev_;
        T value_;

        Node(const T &value) :
            next_(nullptr), prev_(nullptr), value_(value) {}
    };

    Node *first_, *last_;
    std::size_t size_;

    Node *get(std::size_t index) {
        if (index == 0)
            return first_;
        if (index == size_ - 1)
            return last_;
        if (index >= size_)
            throw std::logic_error("Accessing a non-existent object!");

        Node *p = first_;
        if (index < size_ / 2)
            for (std::size_t i = 0; i < index; i++)
                p = p->next_;
        else
            for (std::size_t i = size_ - 1; i >= index; i--)
                p = p->prev_;
        return p;
    }

public:
    list() :
        first_(nullptr), last_(nullptr), size_(0) {}

    list(const list<T> &other) {
        for (std::size_t i = 0; i < other.size_; i++)
            push_back(other[i]);
        size_ = other.size_;
    }

    ~list() {
        clear();
    }

    void clear() {
        for (std::size_t i = 0; i < size_; i++)
            pop_back();
    }

    list(list<T> &&other) {
        size_ = other.size_;
        first_ = other.first_;
        last_ = other.last_;

        other.size_ = 0;
        other.first_ = nullptr;
        other.last_ = nullptr;
    }

    void push_back(const T &value) {
        if (size_ == 0) {
            first_ = new Node(value);
            last_ = first_;
            size_ = 1;
        } else {
            Node *p = new Node(value);
            last_->next_ = p;
            p.prev_ = last_;
            size_++;
        }
    }

    T pop_back() {
        if (size_ == 0)
            throw std::logic_error("Clearing an empty list!");

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

    std::size_t get_size() {
        return size;
    }

    T operator[](std::size_t index) {
        return get(index)->value_;
    }

    void push_front(const T &value) {
        if (size_ == 0) {
            first_ = new Node(value);
            last_ = first_;
            size_ = 1;
        } else {
            Node *p = new Node(value);
            first_->prev_ = p;
            p.next_ = first_;
            size_++;
        }
    }

    void print() {
        for (std::size_t i = 0; i < size_; i++)
            std::print("{} ", (*this)[i]);
        std::println("");
    }
};

export template <typename T> class stack : private list<T> {
public:
    void push(const T &value) {
        push_back(value);
    }

    T pop() {
        if (size_ == 0)
            throw std::logic_error("Accessing a non-existent object!");
        return pop_back();
    }

    T check() {
        if (size_ == 0)
            throw std::logic_error("Accessing a non-existent object!");
        return (*this)[get_size() - 1];
    }

    void fill_inc(std::size_t size) {
        for (std::size_t i = 0; i < size; i++)
            push(i);
    }

    void fill_dec(std::size_t size) {
        for (std::size_t i = 0; i < size; i++)
            push(size - i);
    }

    void fill_rand(std::size_t size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 100);
        for (size_t i = 0; i < size; i++)
            push(dist(gen));
    }
};

export template <typename T> class queue : private list<T> {
public:
    void push(const T &value) {
        push_front(value);
    }

    T pop() {
        if (size_ == 0)
            throw std::logic_error("Accessing a non-existent object!");
        return pop_back();
    }

    T check() {
        if (size_ == 0)
            throw std::logic_error("Accessing a non-existent object!");
        return (*this)[get_size() - 1];
    }

    void fill_inc(std::size_t size) {
        for (std::size_t i = 0; i < size; i++)
            push(i);
    }

    void fill_dec(std::size_t size) {
        for (std::size_t i = 0; i < size; i++)
            push(size - i);
    }

    void fill_rand(std::size_t size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 100);
        for (size_t i = 0; i < size; i++)
            push(dist(gen));
    }
};
