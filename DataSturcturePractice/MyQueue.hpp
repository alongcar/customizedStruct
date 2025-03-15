#pragma once
#include<iostream>
#include<string>
#include<sstream>

template<typename T>
struct QNode {
    T value;
    QNode<T>* next;
    QNode() = default;
    QNode(T v) :value(v), next(nullptr) {};
    QNode(const QNode& q) :value(q.value), next(q.next) {}
};

/***
* 链式队列 
* 元素为指针：first、rear
* 结点类型QNode
* QNode元素为value和next
***/
template<typename T>
class MyQueue
{
public:
    QNode<T>* first;
    QNode<T>* rear;
    bool isEmpty();
    QNode<T>* inqueue(QNode<T> x);
    QNode<T>* dequeue();
    MyQueue():first(nullptr), rear(nullptr) {} // 不能不写，不写first会是一个未初始化的指针，会导致一个未知的内存地址中的值被修改，而造成错误
    MyQueue(const MyQueue<T>& mq): MyQueue() { // 拷贝构造函数也要记得初始化内置变量，否则会导致难以排查的错误
        QNode<T>* qit = mq.first;
        while (qit != nullptr) {
            inqueue(*qit);
            qit = qit->next;
        }
    }

    ~MyQueue();
    
};

template<typename T>
MyQueue<T>::~MyQueue() {
    // std::cout << "析构：" << std::endl;
    while (!isEmpty()) {
        dequeue();
    }
    first = nullptr;
    rear = nullptr;
}

template<typename T>
bool MyQueue<T>::isEmpty() {
    if (first == nullptr && rear == nullptr) return true;
    return false;
}

template<typename T>
QNode<T>* MyQueue<T>::inqueue(QNode<T> x) {
    QNode<T>* q = new QNode<T>(x); // 记得delete
    // 队空，则头尾指针都指向第一个元素，队不为空，则当前尾元素next指向新元素，尾指针指向下一个元素
    if (rear == nullptr && first == nullptr) {
        rear = q;
        first = q;
    }
    else {
        rear->next = q;
        rear = rear->next;
    }
    return rear;
}

template<typename T>
QNode<T>* MyQueue<T>::dequeue() {
    QNode<T>* q = first;
    try {
        if (first == nullptr && first == rear) {
            throw new std::out_of_range("队空，当前队内无元素可出队");
        }
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    // 队中只有一个元素，则头尾指针置空，否则，头指针指向队内下一个元素
    if (first == rear && first != nullptr) {
        first = nullptr;
        rear = nullptr;
    }
    else {
        first = first->next;
    }
    delete (q);
    /* 
    // 显示出队后队内的元素
    QNode<T>* temp = first;
    while (temp != nullptr) {
        std::cout << temp->value.coef << "x^" << temp->value.expon;
        temp = temp->next;
        temp == nullptr ? std::cout << std::endl : std::cout << "+";
    }
    */
    return first;
}


// 验证队列操作，对队列执行出队及入队操作。
template<typename T>
void testQueue(MyQueue<T> &mq) {
    std::cout << "入队操作，每次队尾元素如下：" << std::endl;
    for (int i = 0; i < 10; ++i) {
        QNode<int> q(i);
        mq.inqueue(q);
        std::cout << (mq.rear)->value << " ";
    }
    std::cout << std::endl;
    std::cout << "出队操作，每次出队之后，队内首元素如下：" << std::endl;
    while (!mq.isEmpty()) {
        QNode<T>* q = mq.dequeue();
        if(!mq.isEmpty()) 
            std::cout << q->value << " ";
    }
    std::cout << std::endl;
}





