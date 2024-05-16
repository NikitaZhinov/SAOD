#include "Lists.h"

// LIST

template <typename T>
list<T>::list(const list<T> &other) {
    for (std::size_t i = 0; i < other.size_; i++)
        push_back(other(i));
}

template <typename T>
list<T>::list(list<T> &&other) {
    size_ = other.size_;
    first_ = other.first_;
    last_ = other.last_;

    other.size_ = 0;
    other.first_ = nullptr;
    other.last_ = nullptr;
}

template <typename T>
list<T>::~list() {
    clear();
}

template <typename T>
void list<T>::clear() {
    while (size_ > 0)
        pop_back();
}

template <typename T>
std::size_t list<T>::get_size() {
    return size_;
}

template <typename T>
void list<T>::push_back(const T &value) {
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

template <typename T>
void list<T>::push_front(const T &value) {
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

template <typename T>
T list<T>::pop_back() {
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

template <typename T>
T list<T>::pop_front() {
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

template <typename T>
void list<T>::fill(const T &value) {
    NodeList<T> *p = first_;
    for (std::size_t i = 0; i < size_; i++) {
        p->value_ = value;
        p = p->next_;
    }
}

template <typename T>
T list<T>::operator()(std::size_t index) const {
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

template <typename T>
void list<T>::print() {
    for (std::size_t i = 0; i < size_; i++)
        std::cout << (*this)(i) << " ";
    std::cout << std::endl;
}

template <typename T>
std::size_t list<T>::merge(const list<T> &a, const list<T> &b, list<T> &c) {
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

// возможно не работает
template <typename T>
std::size_t list<T>::split(list<T> &a, list<T> &b) {
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

// не работает
template <typename T>
std::size_t list<T>::merge_sort() {
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

// STACK

template <typename T>
stack<T>::stack(const stack<T> &other) {
    NodeList<T> *p = other.first_;
    for (std::size_t i = 0; i < other.size_; i++) {
        push(p->value_);
        p = p->next_;
    }
}

template <typename T>
stack<T>::stack(stack<T> &&other) {
    size_ = other.size_;
    first_ = other.first_;
    last_ = other.last_;

    other.size_ = 0;
    other.first_ = nullptr;
    other.last_ = nullptr;
}

template <typename T>
stack<T>::~stack() {
    clear();
}

template <typename T>
void stack<T>::clear() {
    while (size_ > 0)
        pop();
}

template <typename T>
std::size_t stack<T>::get_size() {
    return size_;
}

template <typename T>
void stack<T>::push(const T &value) {
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

template <typename T>
T stack<T>::pop() {
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

template <typename T>
T stack<T>::check() {
    return last_->value_;
}

template <typename T>
void stack<T>::fill_inc(std::size_t size) {
    clear();
    for (std::size_t i = 0; i < size; i++)
        push(i);
}

template <typename T>
void stack<T>::fill_dec(std::size_t size) {
    clear();
    for (std::size_t i = 0; i < size; i++)
        push(size - i);
}

template <typename T>
void stack<T>::fill_rand(std::size_t size) {
    clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    for (std::size_t i = 0; i < size; i++)
        push(dist(gen));
}

// QUEUE

template <typename T>
queue<T>::queue(const queue<T> &other) {
    NodeList<T> *p = other.first_;
    for (std::size_t i = 0; i < other.size_; i++) {
        push(p->value_);
        p = p->next_;
    }
}

template <typename T>
queue<T>::queue(queue<T> &&other) {
    size_ = other.size_;
    first_ = other.first_;
    last_ = other.last_;

    other.size_ = 0;
    other.first_ = nullptr;
    other.last_ = nullptr;
}

template <typename T>
queue<T>::~queue() {
    clear();
}

template <typename T>
void queue<T>::clear() {
    while (size_ > 0)
        pop();
}

template <typename T>
std::size_t queue<T>::get_size() {
    return size_;
}

template <typename T>
void queue<T>::push(const T &value) {
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

template <typename T>
T queue<T>::pop() {
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

template <typename T>
T queue<T>::check() {
    return last_->value_;
}

template <typename T>
void queue<T>::fill_inc(std::size_t size) {
    clear();
    for (std::size_t i = 0; i < size; i++)
        push(i);
}

template <typename T>
void queue<T>::fill_dec(std::size_t size) {
    clear();
    for (std::size_t i = 0; i < size; i++)
        push(size - i);
}

template <typename T>
void queue<T>::fill_rand(std::size_t size) {
    clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    for (std::size_t i = 0; i < size; i++)
        push(dist(gen));
}
