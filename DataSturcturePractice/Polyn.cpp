#include "Polyn.h"

void cinPolyn(MyQueue<Polyn>& mq) {
    std::string linepy1;
    getline(std::cin, linepy1);
    std::stringstream is(linepy1);
    Polyn py;
    std::string scoef, sexpon;
    while (is >> scoef, is >> sexpon) {
        py.coef = stoi(scoef);
        py.expon = stoi(sexpon);
        mq.inqueue(QNode<Polyn>(py));
    }
}

void addPolyn(MyQueue<Polyn> py1, MyQueue<Polyn> py2) {
    // std::cout << "已经拷贝成功" << py1.first->value.coef << std::endl;
    MyQueue<Polyn> pyque_sum;
    Polyn pysum;
    while (!py1.isEmpty() && !py2.isEmpty()) {
        if (py1.first->value.expon == py2.first->value.expon) {
            pysum.coef = py1.first->value.coef + py2.first->value.coef;
            pysum.expon = py1.first->value.expon;
            pyque_sum.inqueue(QNode<Polyn>(pysum));
            // std::cout << py1.first->value.coef << " " << py1.first->value.expon << " ";
            py1.dequeue();
            // std::cout << py2.first->value.coef << " " << py2.first->value.expon << " ";
            py2.dequeue();

        }
        else if (py1.first->value.expon >= py2.first->value.expon) {
            pysum.coef = py1.first->value.coef;
            pysum.expon = py1.first->value.expon;
            pyque_sum.inqueue(QNode<Polyn>(pysum));
            py1.dequeue();
        }
        else if (py1.first->value.expon <= py2.first->value.expon) {

            pysum.coef = py2.first->value.coef;
            pysum.expon = py2.first->value.expon;
            pyque_sum.inqueue(QNode<Polyn>(pysum));
            py2.dequeue();
        }
    }
    if (py1.isEmpty() && !py2.isEmpty()) {
        while (!py2.isEmpty()) {
            pyque_sum.inqueue(*(py2.first));
            py2.dequeue();
        }
    }

    if (py2.isEmpty() && !py1.isEmpty()) {
        while (!py1.isEmpty()) {
            pyque_sum.inqueue(*(py1.first));
            py1.dequeue();
        }

    }

    //while (!pyque_sum.isEmpty()) {
    //    std::cout << pyque_sum.first->value.coef << "x^" << pyque_sum.first->value.expon;
    //    pyque_sum.first == pyque_sum.rear ? std::cout << "+" : std::cout << std::endl;
    //    pyque_sum.dequeue();
    //}
    printPolyn(pyque_sum);


}

void printPolyn(const MyQueue<Polyn>& mq) {
    //while (!qpy.isEmpty()) {
    //    std::cout << qpy.first->value.coef << "x^" << qpy.first->value.expon;
    //    qpy.first == qpy.rear ? std::cout << std::endl :  std::cout << "+";
    //    qpy.dequeue();
    //}

    QNode<Polyn>* qit = mq.first;
    while (qit != nullptr) {
        std::cout << qit->value.coef << "x^" << qit->value.expon;
        qit = qit->next;
        qit == nullptr ? std::cout << std::endl : std::cout << "+";
    }
}
