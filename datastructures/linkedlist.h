
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cassert>

namespace wstd {

    namespace list {
        template<typename T>
        struct Node {
            T data{};
            Node<T>* nextNode;
            Node<T>* previousNode;
        };
    }

    using namespace list;
    template<typename T>
    class linkedlist {
    public:
        linkedlist() = default;

        void append(const T& newData) {
            if (head == nullptr) {
                Node<T>* newNode =  new Node { newData, tail, tail };
                head = newNode;
            }
            else if (tail == nullptr) {
                Node<T>* newNode = new Node { newData, head, head };
                head->nextNode = newNode;
                head->previousNode = newNode;
                tail = newNode;
            }
            else {
                Node<T>* newNode = new Node { newData, head, tail };
                tail->nextNode = newNode;
                tail = newNode;
            }
            size++;
        }

        void remove(const size_t index) {
            Node<T>* node = get_node_at(index);
            Node<T>* previousNode = node->previousNode;
            Node<T>* nextNode = node->nextNode;
            previousNode->nextNode = nextNode;
            nextNode->previousNode = previousNode;
            node->data.~T();
            size--;
        }

        void insert_after(const T& newData, const size_t index) {
            Node<T>* previousNode = get_node_at(index);
            Node<T>* nextNode = previousNode->nextNode;
            Node<T>* newNode = new Node {newData, nextNode, previousNode};
            nextNode->previousNode = newNode;
            previousNode->nextNode = newNode;
            size++;
        }

        void insert_before(const T& newData, const size_t index) {
            Node<T>* nextNode = get_node_at(index);
            Node<T>* previousNode = nextNode->previousNode;
            Node<T>* newNode = new Node {newData, nextNode, previousNode};
            nextNode->previousNode = newNode;
            previousNode->nextNode = newNode;
            size++;
        }

        Node<T>* get_node_at(const size_t targetNode) {
#ifdef NDEBUG
            assert(size > 0 && "attempted to access an empty linked list\n");
            assert(targetNode <= size && "acces of linked list out of bounds\n");
#endif
            const size_t midpoint = size / 2;
            if (targetNode <= midpoint && head != nullptr) {
                size_t index = 0;
                Node<T>* currentNode = head;
                while (currentNode->nextNode != nullptr && index < targetNode) {
                    currentNode = currentNode->nextNode;
                    index++;
                }
                return currentNode;
            }

            size_t index = size - 1;
            Node<T>* currentNode = tail;
            while (currentNode->previousNode != nullptr && index > targetNode) {
                currentNode = currentNode->previousNode;
                index--;
            }
            return currentNode;
        }

        T& operator [] (const size_t targetNode) {
#ifdef NDEBUG
            assert(size > 0 && "attempted to access an empty linked list\n");
            assert(targetNode <= size && "acces of linked list out of bounds\n");
#endif

            const size_t midpoint = size / 2;
            if (targetNode <= midpoint && head != nullptr) {
                size_t index = 0;
                Node<T>* currentNode = head;
                while (currentNode->nextNode != nullptr && index < targetNode) {
                    currentNode = currentNode->nextNode;
                    index++;
                }
                return currentNode->data;
            }

            size_t index = size - 1;
            Node<T>* currentNode = tail;
            while (currentNode->previousNode != nullptr && index > targetNode) {
                currentNode = currentNode->previousNode;
                index--;
            }
            return currentNode->data;
        }

        [[nodiscard]] size_t getSize() const { return size; }

    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        size_t size = 0;
    };
}

#endif //LINKEDLIST_H
