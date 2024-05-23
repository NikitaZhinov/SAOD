#include "Hash.hpp"
#include <cstddef>
#include <cstring>

std::size_t directLinking(const std::string &str, std::size_t size_table) {
    HashTable<char, char> table;
    for (char c : str)
        table.add(c, c, size_table);

    return table.get_collisions();
}
