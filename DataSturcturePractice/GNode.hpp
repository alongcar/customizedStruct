#pragma once

template<typename T>
class GNode
{
public:
	typedef struct GNode<T>* GList;
	/** 通过Tag来区分是表还是数据元素 */
	int tag; 
	union {
		T data;
		GList subList;
	}URegion; 
	GList next;
};



