
template <class T>
class List {

    class Node {

        private:
            T* el;
            Node<T>* next;
    
        public:
            Node(T* ptr) : el{ptr} {
                // noop
            }

            void operator ++(int) {
                next = next->next;
            }

    };

    class Iterator {
        private:
            Node<T>* current;
            Node<T>* next;
    
        public:
            Iterator() 

            void operator ++(int) {
                next = next->next;
            }
    };

private:
    Node<T>* start;
    int length;

public:
    List() : start{nullptr}, end{nullptr}, length{0} {
        // noop
    }

    ~List() {
        Node<T>* it;
        Node<T>* prev;

        for(it = start; it;) {
            prev = it;
            it++;
            delete prev;
        }
    }

    void pushFront(T* node) {
        if(start == nullptr) {
            start = new Node<T*>(node);
        }
        else {
            
        }
    }



};