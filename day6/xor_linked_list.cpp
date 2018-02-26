#include <iostream>
#include <stdint.h>
template <typename T>
struct Node {
    T val;
    Node<T>* both;
    Node(const T& t) : val(t), both(NULL){}
};

template <typename T>
class XorList {
public:
    void addNode(const T& t);
    Node<T> *getNode(const int index);
    XorList(): head(NULL), tail(NULL) {}
private:
    Node<T> *performXor(const Node<T>* a, const Node<T>* b);
private:
    Node<T>* head;
    Node<T> *tail;
};
int main() {

    XorList<int> list;
    list.addNode(10);
    list.addNode(11);
    list.addNode(12);
    list.addNode(13);
    Node<int>* a = list.getNode(3);
    if (a)
        std::cout << "Value is " << a->val << "\n";
    else
        std::cout << "Provide a valid index!\n";
    return 0;
}

template<typename T>
void XorList<T>::addNode(const T &t)
{
    Node<T>* node = new Node<T>(t);
    if (tail == NULL) {// first node
        tail = head = node;
    } else {
        Node<T>* previousNode = performXor(tail->both, NULL);
        tail->both = performXor(previousNode, node);
        node->both = performXor(tail, NULL);
        tail = node;
    }
}

template<typename T>
Node<T> *XorList<T>::getNode(const int index)
{
    if (index < 0) return NULL;
    Node<T>* node = head;
    Node<T>* prevNode = NULL;
    for (int i=1; i<=index; i++) {
        if (node == tail) {
            return NULL;
        }
        Node<T>* nextNode = performXor(node->both, prevNode);
        prevNode = node;
        node = nextNode;
    }
    return node;
}

template<typename T>
Node<T> *XorList<T>::performXor(const Node<T> *a, const Node<T> *b)
{
    intptr_t x = ((std::intptr_t)(a) ^ (std::intptr_t)(b));
    return (Node<T> *) x;
}
