#pragma once

#include "Lists.hpp"
#include <cstddef>
#include <stdexcept>

template <typename T> struct HashNode {
    HashNode<T> *next, *prev;
    unsigned key;

    list<T> *data;

    HashNode(unsigned key_, const T &value) :
        next(nullptr), prev(nullptr), key(key_) {
        data = new list<T>;
        data->push_back(value);
    }

    ~HashNode() {
        if (prev != nullptr)
            prev->next = next;
        if (next != nullptr)
            next->prev = prev;
        data->clear();
        delete data;
    }
};

template <typename TKey, typename TValue> class HashTable {
private:
    HashNode<TValue> *firts;
    HashNode<TValue> *last;
    std::size_t size;

    unsigned getHash(const TKey &key, std::size_t size_table) {
        return key % size_table;
    }

public:
    HashTable() :
        firts(nullptr), last(nullptr), size(0) {}

    ~HashTable() {
        clear();
    }

    void clear() {
        HashNode<TValue> *p = firts;
        HashNode<TValue> *temp = firts;
        while (size > 0) {
            temp = p;
            p = p->next;
            delete temp;
            size--;
        }
    }

    void add(const TKey &key, const TValue &value, std::size_t size_table) {
        unsigned hash = getHash(key, size_table);
        bool is_exist = false;
        HashNode<TValue> *p = firts;
        while (p != nullptr) {
            if (p->key == hash) {
                is_exist = true;
                break;
            }
            p = p->next;
        }
        if (is_exist)
            p->data->push_back(value);
        else {
            p = new HashNode<TValue>(hash, value);
            if (size == 0)
                last = firts = p;
            else {
                p->prev = last;
                last->next = p;
                last = p;
            }
            size++;
        }
    }

    void remove(const TKey &key) {
        unsigned hash = getHash(key);
        HashNode<TValue> *p = firts;
        while (p != nullptr && p->key != hash)
            p = p->next;
        if (p == nullptr)
            return;
        delete p;
        size--;
    }

    TValue get(const TKey &key) {
        unsigned hash = getHash(key);
        HashNode<TValue> *p = firts;
        while (p != nullptr && p->key != hash)
            p = p->next;
        if (p == nullptr)
            throw std::logic_error("Key is not normal!");
        return (*p->data)(0);
    }

    std::size_t get_collisions() {
        HashNode<TValue> *p = firts;
        std::size_t collision = 0;

        while (p != nullptr) {
            collision += p->data->get_size() - 1;
            p = p->next;
        }

        return collision;
    }
};

std::size_t directLinking(const std::string &str, std::size_t size_table);
void openAddressing();
