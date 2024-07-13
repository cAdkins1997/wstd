
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

            Node(Node<T>& other) : data(other.data), nextNode(other.nextNode), previousNode(other.previousNode) {
                std::cout << "node copy constructor\n";
            }

            Node(Node<T>&& other)  noexcept : data(std::move(other.data)) {
                nextNode = other.nextNode;
                previousNode = other.previousNode;
                other.nextNode = nullptr;
                other.previousNode = nullptr;

                std::cout << "node move copy constructor";
            }

            Node& operator = (const Node<T>& other) {
                data = other.data;
                nextNode = other.nextNode;
                previousNode = other.previousNode;
                std::cout << "node copy assignment operator";
                return *this;
            }

            Node& operator = (Node<T>&& other) noexcept {
                data = std::move(other.data);
                nextNode = other.nextNode;
                previousNode = other.previousNode;

                other.nextNode = nullptr;
                other.previousNode = nullptr;

                std::cout << "node move assignment operator";
                return *this;
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
            head = static_cast<arraylist<T>&&>(other.head);
            tail = static_cast<arraylist<T>&&>(other.tail);
            other.size = static_cast<arraylist<T>&&>(0);

            other.tail = nullptr;
            other.head = nullptr;

            std::cout << "linked list move constructor\n";
        }

        linkedlist<T>& operator = (const linkedlist<T>& other) {

            if (other.head != nullptr) {
                head = other.head;
                Node<T>* currentNode = head;
                while(currentNode->nextNode != nullptr) {
                    append(currentNode->data);
                }
                append(tail->data);
            }

            size = other.size;

            std::cout << "linked list copy assignment operator\n";

            return *this;
        }

        linkedlist<T>& operator = (linkedlist<T>&& other) noexcept {

            head = std::move(other.head);
            tail = std::move(other.tail);
            size = std::move(other.size);

            other.tail = nullptr;
            other.head = nullptr;

            std::cout << "linked list move assignment operator\n";

            return *this;
        }

        ~linkedlist() {
            if (head != nullptr) {
                Node<T>* currentNode = head;
                tail->nextNode = nullptr;
                while (currentNode->nextNode != nullptr) {
                    Node<T>* previousNode = currentNode;
                    currentNode = currentNode->nextNode;
                    previousNode->data.~T();
                            ::operator delete(previousNode);
                }

                tail->data.~T();
                ::operator delete(tail);
            }
        }

        void append(T&& newData) {
            if (head == nullptr) {
                auto* newNode = static_cast<Node<T>*>(::operator new (sizeof(Node<T>)));
                newNode->data = std::move(newData);
                head = newNode;
            }
            else if (tail == nullptr) {
                auto* newNode = static_cast<Node<T>*>(::operator new (sizeof(Node<T>)));
                newNode->data = std::move(newData);
                newNode->nextNode = head;
                newNode->previousNode = head;
                head->nextNode = newNode;
                head->previousNode = newNode;
                tail = newNode;
            }
            else {
                auto* newNode = static_cast<Node<T>*>(::operator new (sizeof(Node<T>)));
                newNode->data = std::move(newData);
                newNode->nextNode = head;
                newNode->previousNode = tail;
                tail->nextNode = newNode;
                tail = newNode;
            }
            size++;
        }

        void append(T& newData) {
            if (head == nullptr) {
                auto* newNode = static_cast<Node<T>*>(::operator new (sizeof(Node<T>)));
                newNode->data = std::move(newData);
                head = newNode;
            }
            else if (tail == nullptr) {
                auto* newNode = static_cast<Node<T>*>(::operator new (sizeof(Node<T>)));
                newNode->data = std::move(newData);
                newNode->nextNode = head;
                newNode->previousNode = head;
                head->nextNode = newNode;
                head->previousNode = newNode;
                tail = newNode;
            }
            else {
                auto* newNode = static_cast<Node<T>*>(::operator new (sizeof(Node<T>)));
                newNode->data = std::move(newData);
                newNode->nextNode = head;
                newNode->previousNode = tail;
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

        std::string to_string() {
            std::string string;
            for (size_t i = 0; i < size; i++) {
                string.append(std::to_string( operator[](i)));
            }

            return string;
        }

    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        size_t size = 0;
    };
}

template<typename T>
std::ostream& operator << (std::ostream& ostream, wstd::linkedlist<T>& list) {
    ostream << list.to_string();
    return ostream;
}

#endif //LINKEDLIST_H
