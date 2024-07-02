
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>
#include <cstdlib>

namespace wstd {

    namespace list {
        template<typename T>
        struct Node {
            T data{};
            Node<T>* nextNode = nullptr;
            Node<T>* previousNode = nullptr;

            explicit Node(T&& newData) : data(std::move(newData)) {}
            Node(T&& newData, Node<T>* next) : data(std::move(newData)), nextNode(next) {}
            Node(T&& newData, Node<T>* next, Node<T>* previous) : data(std::move(newData)), nextNode(next), previousNode(previous){}
            Node(Node<T>& other) : data(other.data), nextNode(other.nextNode), previousNode(other.previousNode) {
#ifdef NDEBUG
                std::cout << "node copy constructor\n";
#endif
            }

            Node(const Node<T>&& other) noexcept : data(std::move(other.data)), nextNode(other.nextNode), previousNode(other.previousNode) {
#ifdef NDEBUG
                std::cout << "array list move constructor\n";
#endif
            }
        };
    }

    using namespace list;
    template<typename T>
    class linkedlist {
    public:
        linkedlist() = default;

        explicit linkedlist(const arraylist<T>& other) : size(other.size) {
            if (other.head != nullptr) {
                head = other.head;
                Node<T>* currentNode = head;
                while(currentNode->nextNode != nullptr) {
                    append(currentNode->data);
                }
                append(tail->data);
            }
            std::cout << "linked list copy constructor\n";
        }

        explicit linkedlist(const arraylist<T>&& other)  noexcept : size(other.size) {
            if (other.head != nullptr) {
                Node<T>* currentNode = other.head;
                while(currentNode->nextNode) {
                    Node<T>* previousNode = currentNode;
                    append(std::move(previousNode->data));
                    currentNode = currentNode->nextNode;
                }
            }
            std::cout << "linked list move constructor\n";
        }

        ~linkedlist() {
            if (head != nullptr) {
                Node<T>* currentNode = head;
                while(currentNode->nextNode != nullptr) {
                    Node<T>* previousNode = currentNode;
                    previousNode->data.~T();
                    currentNode = currentNode->nextNode;
                }
            }
        }

        void append(T& newData) {
            if (head == nullptr) {
                auto* newNode =  static_cast<Node<T>*>(::operator new (sizeof(Node<T>)));
                newNode->data = std::move(newData);
                head = newNode;
            }
            else if (tail == nullptr) {
                Node<T>* newNode = new Node { std::move(newData), head, head };
                head->nextNode = newNode;
                head->previousNode = newNode;
                tail = newNode;
            }
            else {
                Node<T>* newNode = new Node { std::move(newData), head, tail };
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
