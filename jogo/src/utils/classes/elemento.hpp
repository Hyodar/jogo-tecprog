#ifndef ELEMENTO_HPP_
#define ELEMENTO_HPP_

template<class T>

class Elemento{

private:
    Elemento<T>* next;
    Elemento<T>* prev;
    T* info;

public:
    Elemento();
    ~Elemento();

    T* getInfo()const;
    void setInfo(T* pi);

    void setNext(Elemento<T>* pn);
    void setPrev(Elemento<T>* pp);
    Elemento<T>* getNext()const;
    Elemento<T>* getPrev()const;
};

// ---------------------------------------------------------------------------

template<class T>
Elemento<T>::Elemento(){
    next = nullptr;
    prev = nullptr;
    info = nullptr;
}

// ---------------------------------------------------------------------------

template<class T>
Elemento<T>::~Elemento(){
    //noop
}

// ---------------------------------------------------------------------------

template<class T>
T* Elemento<T>::getInfo()const{
    return info;
}

// ---------------------------------------------------------------------------

template<class T>
void Elemento<T>::setInfo(T* pi){
    info=pi;
}

// ---------------------------------------------------------------------------

template<class T>
void Elemento<T>::setNext(Elemento<T>* pn){
    next=pn;
}

// ---------------------------------------------------------------------------

template<class T>
void Elemento<T>::setPrev(Elemento<T>* pp){
    prev=pp;
}

// ---------------------------------------------------------------------------

template<class T>
Elemento<T>* Elemento<T>::getNext()const{
    return next;
}

// ---------------------------------------------------------------------------

template<class T>
Elemento<T>* Elemento<T>::getPrev()const{
    return prev;
}

#endif // ELEMENTO_HPP_
