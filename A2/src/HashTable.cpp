//
// Created by goldengeneral on 04/03/24.
//

#include "../include/HashTable.h"
#include <string>
#include <vector>
#include <limits>
#include <type_traits>

template <typename KeyType, typename ValueType>
unsigned int HashTable<KeyType, ValueType>::findFreeSlot(std::vector<Bucket> &cTable, unsigned int startIndex,
                                                         unsigned int &currentHop) {

}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::rehash() {

}

template <typename KeyType, typename ValueType>
unsigned int hash(const KeyType& key, int tableSize) {
    unsigned int hashVal = 0;

    for (char ch : key) {
        hashVal = 37 * hashVal + ch;
    }

    return hashVal % tableSize;
}

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable(unsigned int size, double threshold) {
    tableSize = size;
    loadFactorThreshold = threshold;
    hashTable.resize(tableSize);
}

template <typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator HashTable<KeyType, ValueType>::begin() {
    for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
        if (it->occupied) {
            return Iterator(it, hashTable.end());
        }
    }
    return end();
}

template <typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator HashTable<KeyType, ValueType>::end() {
    return Iterator(hashTable.end(), hashTable.end());
}

template <typename KeyType, typename ValueType>
ValueType &HashTable<KeyType, ValueType>::operator[](const KeyType &key) {

}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::updateValueForKey(const KeyType &key, ValueType newValue) {

}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value) {

}

template <typename KeyType, typename ValueType>
ValueType *HashTable<KeyType, ValueType>::search(const KeyType &key) {

}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::remove(const KeyType &key) {

}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::clear() {
    hashTable.clear();
}

template <typename KeyType, typename ValueType>
unsigned int HashTable<KeyType, ValueType>::size() const {
    return tableSize;
}

template <typename KeyType, typename ValueType>
double HashTable<KeyType, ValueType>::loadFactor() const {
    return loadFactorThreshold;
}