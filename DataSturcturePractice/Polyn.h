#pragma once
#include"MyQueue.hpp"


//MyQueue<Polyn> qpy1, qpy2;
//cinPolyn(qpy1);
//printPolyn(qpy1);
//cinPolyn(qpy2);
//printPolyn(qpy2);
//addPolyn(qpy1, qpy2);

/*** ����ʽԪ������ ***/
struct Polyn {
    /** ϵ�� */
    int coef;
    /** ָ�� */
    int expon;
    Polyn(int cf, int ep) :coef(cf), expon(ep) {}
    Polyn() = default;
    Polyn(const Polyn& py) :coef(py.coef), expon(py.expon) {}
};

/*** �������ʽ�ĺ��� ***/
void addPolyn(MyQueue<Polyn> py1, MyQueue<Polyn> py2);

/*** �������ʽ ***/
void cinPolyn(MyQueue<Polyn>& mq);

/*** ��ӡ����ʽ ***/
void printPolyn(const MyQueue<Polyn>& mq);


