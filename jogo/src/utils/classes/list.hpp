
#ifndef LIST_HPP_
#define LIST_HPP_

/*
    Inspirado na implementação mostrada em cplusplus.com,
    com implementações e otimizações adicionais
*/

namespace bardadv::lists {

template <typename T>
class List;

template <class NodeType>
class ListIterator {

private:
    friend class List<typename NodeType::value_type>;
    NodeType* node;

    ListIterator(NodeType* pNode) : node{pNode} {}

public:
    void operator++() {
        node = node->next;
    }

    void operator++(int) {
        node = node->next;
    }

    bool operator != (ListIterator<NodeType> it2) {
        return node != it2.node;
    }

    bool operator == (ListIterator<NodeType> it2) {
        return node == it2.node;
    }

    typename NodeType::value_type operator*() {
        return node->data;
    }

    ListIterator<NodeType> operator + (int n) {
        ListIterator<NodeType> it = *this;

        for(int i = 0; i < n; i++) {
            if(it.node) ++it;
            else throw "Index error: Accessing invalid list node";
        }

        return it;
    }
};

template <typename T>
class Node {

private:
    friend class List<T>;
    friend class ListIterator<Node<T>>;

    Node() : next{nullptr} {}
    Node(T _data) : data{_data}, next{nullptr} {}
    Node(Node<T>* _next) : next{_next} {}

    T data;
    Node<T>* next;

public:
    // define o tipo de valor do node seu value_type
    typedef T value_type;

};

template <typename T>
class List {

private:
    Node<T>* head;
    int length;

public:
    typedef ListIterator<Node<T>> iterator;
    typedef T value_type;

    List() : head{nullptr}, length{0} {}
    
    ~List() {
        if(head) {
            Node<T>* iter = head;

            while(iter) {
                Node<T>* tmp = iter;
                iter = iter->next;
                delete tmp;
            }
        }

        length = 0;
    }

    int size() {
        return length;
    }

    // clear() não limpa memória dinâmica, só joga fora
    // o conteúdo da lista
    void clear() {
        head = nullptr;
        length = 0;
    }

    // deallocate() limpa memória dinâmica
    void deallocate() {
        while(head) {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }

        length = 0;
    }

    void push_back(T data) {
        if(head) {
            Node<T>* iter = head;
            
            for(; iter->next; iter = iter->next);
            iter->next = new Node<T>(data);
        }
        else {
            head = new Node<T>(data);
        }
        length++;
    }

    void push_front(T data) {
        if(head) {
            Node<T>* tmp = new Node<T>(data);
            tmp->next = head;
            head = tmp;
        } 
        else {
            head = new Node<T>(data);
        }
        length++;
    }

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }

    bool erase(iterator& toErase) {

        if(toErase.node == head) {
            head = head->next;
            delete toErase.node;
            length--;
            return true;
        }
        else {
            for(Node<T>* iter = head; iter->next; iter = iter->next) {
                if(iter->next == toErase.node) {
                    iter->next = toErase.node->next;
                    delete toErase.node;
                    length--;
                    return true;
                }
            }
        }

        return false;
    }
};

}

#endif // LIST_HPP_
