#pragma once

template<typename T>
class GNode
{
public:
	typedef struct GNode<T>* GList;
	/** ͨ��Tag�������Ǳ�������Ԫ�� */
	int tag; 
	union {
		T data;
		GList subList;
	}URegion; 
	GList next;
};



