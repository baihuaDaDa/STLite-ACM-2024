#ifndef SJTU_PRIORITY_QUEUE_HPP
#define SJTU_PRIORITY_QUEUE_HPP

#include <cstddef>
#include <functional>
#include "exceptions.hpp"

namespace sjtu {

/**
 * a container like std::priority_queue which is a heap internal.
 */
    template<typename T, class Compare = std::less<T>>
    class priority_queue {
    private:
        struct node {
            node *left;
            node *right;
            T data;
        };

        node *root;
        size_t _size;

        node *construct(node *other_root) {
            if (other_root == nullptr) return nullptr;
            node *_root = new node(*other_root);
            _root->left = construct(other_root->left);
            _root->right = construct(other_root->right);
            return _root;
        }

        void clear(node *&_root) {
            if (_root == nullptr) return;
            clear(_root->left);
            clear(_root->right);
            delete _root;
        }

        node *&merge(node *&node1, node *&node2) {
            if (node1 == nullptr) return node2;
            if (node2 == nullptr) return node1;
            if (Compare()(node2->data, node1->data)) {
                node *tmp = node1->left;
                node1->left = merge(node1->right, node2);
                node1->right = tmp;
                return node1;
            } else {
                node *tmp = node2->left;
                node2->left = merge(node1, node2->right);
                node2->right = tmp;
                return node2;
            }
        }

    public:
        /**
         * TODO constructors
         */
        priority_queue() : _size(0), root(nullptr) {}

        priority_queue(const priority_queue &other) : _size(other._size), root(construct(other.root)) {}

        /**
         * TODO deconstructor
         */
        ~priority_queue() {
            clear(root);
        }

        /**
         * TODO Assignment operator
         */
        priority_queue &operator=(const priority_queue &other) {
            if (&other == this) return *this;
            clear(root);
            root = construct(other.root);
            _size = other._size;
            return *this;
        }

        /**
         * get the top of the queue.
         * @return a reference of the top element.
         * throw container_is_empty if empty() returns true;
         */
        const T &top() const {
            if (empty()) throw container_is_empty();
            return root->data;
        }

        /**
         * TODO
         * push new element to the priority queue.
         */
        void push(const T &e) {
            node *new_node = new node(nullptr, nullptr, e);
            try {
                root = merge(new_node, root);
                _size++;
            } catch (...) {
                delete new_node;
            }

        }

        /**
         * TODO
         * delete the top element.
         * throw container_is_empty if empty() returns true;
         */
        void pop() {
            if (empty()) throw container_is_empty();
            node *delete_ptr = root;
            root = merge(root->left, root->right);
            delete delete_ptr;
            _size--;
        }

        /**
         * return the number of the elements.
         */
        size_t size() const {
            return _size;
        }

        /**
         * check if the container has at least an element.
         * @return true if it is empty, false if it has at least an element.
         */
        bool empty() const {
            return _size == 0;
        }

        /**
         * merge two priority_queues with at most O(logn) complexity.
         * clear the other priority_queue.
         */
        void merge(priority_queue &other) {
            if (&other == this) return;
            root = merge(root, other.root);
            _size += other._size;
            other.root = nullptr;
            other._size = 0;
        }
    };

}

#endif
