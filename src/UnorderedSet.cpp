#include "../include/UnorderedSet.h"
#include <iostream>

template <typename Key>
UnorderedSet<Key>::UnorderedSet() {
    setSize = 0;
}

template <typename Key>
typename UnorderedSet<Key>::Iterator UnorderedSet<Key>::begin() const {
    return Iterator(root);
}
