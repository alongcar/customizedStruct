#pragma once
#include<memory>
#include<iostream>
#define INITMAX 10


//MyStack<int> stk;
//for (int i = 1; i <= 20; i++) {
//	std::cout << *(stk.push(i)) << " ";
//}
//std::cout << std::endl;
//stk.traversal();
//while (!stk.isEmpty()) {
//	std::cout << *(stk.pop()) << " ";;
//}
//std::cout << std::endl;
//}


/** ջ��ջstack��Ԫ��T�����п�����ֵ���캯�� */
template<typename T>
class MyStack
{
public:
	MyStack():maxSize(INITMAX) { bottom = alloc.allocate(maxSize); last = bottom; }
	bool isFull() {
		if (last - bottom == maxSize -1)
			return true;
		return false;
	}
	T* push(T x);
	T* pop();
	T* top() { return last == bottom ? nullptr : last; }
	bool isEmpty() { if (last == bottom) return true; else return false; }
	void traversal();
private:
	size_t maxSize;
	std::allocator<T> alloc;
	T* last;
	T* bottom;
	/*** ��չ˳��ջ���ڴ�ռ� ***/
	void expand();
	
	
};

template<typename T>
void MyStack<T>::expand() {
	T* newbottom = alloc.allocate(maxSize * 2 + 1);
	T* newlast = newbottom;
	T* oldbottom = bottom;
	// alloc.deallocate(bottom, 1);
	while (bottom != last) {
		// traversal();
		++bottom;
		/* �������ʹstack��Ԫ��T�����п�����ֵ���캯�� */
		alloc.construct(++newlast, *bottom);
		alloc.destroy(bottom);
	}
	// traversal();
	alloc.deallocate(oldbottom, maxSize);
	last = newlast;
	bottom = newbottom; maxSize = maxSize * 2 + 1;
	// traversal();
}

template<typename T>
T* MyStack<T>::push(T x) { 
	if (isFull()) expand(); 
	alloc.construct(++last, x); 
	return last; 
}

template<typename T>
T* MyStack<T>::pop() { 
	if (isEmpty()) throw "lack element!";
	/// catch (std::string msg) { std::cerr << msg; }
	alloc.destroy(last);  
	return last--; 
}

/*** ����ջ��Ԫ�� ***/
template<typename T>
void MyStack<T>::traversal() {
	std::cout << std::endl;
	std::cout << "ջ��Ԫ����Ϊ��" << std::endl;
		for (auto i = bottom + 1; i != last + 1; i++)
			std::cout << *i << " ";
	std::cout << std::endl;
}