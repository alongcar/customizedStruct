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
* ��ʽ���� 
* Ԫ��Ϊָ�룺first��rear
* �������QNode
* QNodeԪ��Ϊvalue��next
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
    MyQueue():first(nullptr), rear(nullptr) {} // ���ܲ�д����дfirst����һ��δ��ʼ����ָ�룬�ᵼ��һ��δ֪���ڴ��ַ�е�ֵ���޸ģ�����ɴ���
    MyQueue(const MyQueue<T>& mq): MyQueue() { // �������캯��ҲҪ�ǵó�ʼ�����ñ���������ᵼ�������Ų�Ĵ���
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
    // std::cout << "������" << std::endl;
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
    QNode<T>* q = new QNode<T>(x); // �ǵ�delete
    // �ӿգ���ͷβָ�붼ָ���һ��Ԫ�أ��Ӳ�Ϊ�գ���ǰβԪ��nextָ����Ԫ�أ�βָ��ָ����һ��Ԫ��
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
            throw new std::out_of_range("�ӿգ���ǰ������Ԫ�ؿɳ���");
        }
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    // ����ֻ��һ��Ԫ�أ���ͷβָ���ÿգ�����ͷָ��ָ�������һ��Ԫ��
    if (first == rear && first != nullptr) {
        first = nullptr;
        rear = nullptr;
    }
    else {
        first = first->next;
    }
    delete (q);
    /* 
    // ��ʾ���Ӻ���ڵ�Ԫ��
    QNode<T>* temp = first;
    while (temp != nullptr) {
        std::cout << temp->value.coef << "x^" << temp->value.expon;
        temp = temp->next;
        temp == nullptr ? std::cout << std::endl : std::cout << "+";
    }
    */
    return first;
}


// ��֤���в������Զ���ִ�г��Ӽ���Ӳ�����
template<typename T>
void testQueue(MyQueue<T> &mq) {
    std::cout << "��Ӳ�����ÿ�ζ�βԪ�����£�" << std::endl;
    for (int i = 0; i < 10; ++i) {
        QNode<int> q(i);
        mq.inqueue(q);
        std::cout << (mq.rear)->value << " ";
    }
    std::cout << std::endl;
    std::cout << "���Ӳ�����ÿ�γ���֮�󣬶�����Ԫ�����£�" << std::endl;
    while (!mq.isEmpty()) {
        QNode<T>* q = mq.dequeue();
        if(!mq.isEmpty()) 
            std::cout << q->value << " ";
    }
    std::cout << std::endl;
}





