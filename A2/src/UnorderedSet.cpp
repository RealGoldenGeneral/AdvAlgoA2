#include "../include/UnorderedSet.h"
#include <iostream>

template <typename Key>
void UnorderedSet<Key>::updateSize() {

}

template <typename Key>
size_t UnorderedSet<Key>::getSize(Node<Key> *node) const {

}

template <typename Key>
void UnorderedSet<Key>::deleteOneChild(Node<Key> *node) {

}

template <typename Key>
void UnorderedSet<Key>::deleteFix(Node<Key> *node) {

}

template <typename Key>
void UnorderedSet<Key>::clearRecursive(Node<Key> *node) {

}

template <typename Key>
void UnorderedSet<Key>::rotateLeft(Node<Key> *node) {
    Node<Key>* right = node->right;
    Node<Key>* rl = right->left;
    right->left = node;
    node->right = right;
    node->parent = rl;
    if (rl != nullptr) {
        rl->parent = node;
    }
}

template <typename Key>
void UnorderedSet<Key>::rotateRight(Node<Key> *node) {
    Node<Key>* left = node->left;
    Node<Key>* lr = left->right;
    left->right = node;
    node->left = lr;
    node->parent = left;
    if (lr != nullptr) {
        lr->parent = node;
    }
}

template <typename Key>
void UnorderedSet<Key>::fixRedRedViolation(Node<Key> *node) {
    node->parent->color = Color::BLACK;
    node->parent->parent->left->color = Color::BLACK;
    node->parent->parent->color = Color::RED;
    if (node->parent != nullptr) {
        fixRedRedViolation(node->parent);
    }
}


template <typename Key>
UnorderedSet<Key>::UnorderedSet() {
    setSize = 0;
    root = nullptr;
}

template <typename Key>
UnorderedSet<Key>::~UnorderedSet() {

}

template <typename Key>
typename UnorderedSet<Key>::Iterator UnorderedSet<Key>::begin() const {
    return Iterator(root);
}

template <typename Key>
typename UnorderedSet<Key>::Iterator UnorderedSet<Key>::end() const {
    Node<Key>* end = root;
    while (end->right != nullptr) {
        end = end->right;
    }
    return Iterator(end);
}

template <typename Key>
bool UnorderedSet<Key>::insert(const Key &key) {

}

template <typename Key>
bool UnorderedSet<Key>::search(const Key &key) const {

}

template <typename Key>
bool UnorderedSet<Key>::erase(const Key &key) {

}

template <typename Key>
void UnorderedSet<Key>::clear() {

}

template <typename Key>
size_t UnorderedSet<Key>::size() const {
    return setSize;
}