#pragma once
#include"MyQueue.hpp"


//MyQueue<Polyn> qpy1, qpy2;
//cinPolyn(qpy1);
//printPolyn(qpy1);
//cinPolyn(qpy2);
//printPolyn(qpy2);
//addPolyn(qpy1, qpy2);

/*** 多项式元素类型 ***/
struct Polyn {
    /** 系数 */
    int coef;
    /** 指数 */
    int expon;
    Polyn(int cf, int ep) :coef(cf), expon(ep) {}
    Polyn() = default;
    Polyn(const Polyn& py) :coef(py.coef), expon(py.expon) {}
};

/*** 计算多项式的函数 ***/
void addPolyn(MyQueue<Polyn> py1, MyQueue<Polyn> py2);

/*** 输入多项式 ***/
void cinPolyn(MyQueue<Polyn>& mq);

/*** 打印多项式 ***/
void printPolyn(const MyQueue<Polyn>& mq);


