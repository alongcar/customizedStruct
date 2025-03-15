#include "Sort.h"
#include<iostream>
#include<forward_list>
#include<algorithm>

void sortPractice() {
	/* std::vector<int> arr{6, 5, 1, 3, 2, 4};
	Bubble_sort(arr, arr.size());printVec(arr);
	std::vector<int> arr1{ 6, 5, 1, 3, 2, 4 };
	insertion_sort(arr1); */
	std::vector<int> arr2{ 6, 5, 1, 3, 2, 4 , 7, 10, 78, 27};
	// shell_sort(arr2);
	// heap_sort(arr2);
	// merge_sort(arr2);
	quick_sort(arr2);
	printVec(arr2);
	/* std::forward_list<int> flst{6, 5, 1, 3, 2, 4};
	Bubble_sort(flst, 6); */
}

void printVec(const std::vector<int>& arr) {
	std::cout << std::endl;
	for (const auto &i : arr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

/*** 冒泡排序 ***/
void Bubble_sort(std::vector<int> &arr, int n) {
	size_t cnt = 0;
	bool is_swap = true;
	while (is_swap) {
		is_swap = false;
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				is_swap = true;
			}
		}
		cnt++;
	}
	std::cout << cnt << std::endl;
}

void Bubble_sort(std::forward_list<int>& flst, int n) {
	size_t cnt = 0;
	bool is_swap = true;
	while (is_swap) {
		is_swap = false;
		for (std::forward_list<int>::iterator q = flst.begin(), p = q++ ; q != flst.end();++q, ++p) {
			if ( *p > *q) {
				std::swap(*p, *q);
				is_swap = true;
			}
		}
		for (const auto &i : flst) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
		cnt++;
	}
	
	std::cout << std::endl;
}

/*** 插入排序 ***/
void insertion_sort(std::vector<int>& arr) {
	int n = arr.size();
	for (int i = 1; i < n ; ++i) {
		int temp = arr[i]; int j = i - 1;
		while (j >= 0) {
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];
			}
			else {
				arr[j + 1] = temp;
				break;
			}
			--j;
		}
		if (j == -1) arr[j + 1] = temp;
		// printVec(arr);
	}
}

/*** 希尔排序 ***/
void shell_sort(std::vector<int>& arr) {
	int n = arr.size(), D = n / 2;
	while (D != 0) {
		for (int i = D; i < n; ++i) {
			int j = i - D, temp = arr[i];
			while (j >= 0 && arr[j] > temp ) {
				arr[j + D] = arr[j];
				j -= D;
			}
			arr[j + D] = temp;
		}
		printVec(arr);
		D /= 2;
	}
}

/*** 堆调整操作，大顶堆 ***/
void prcoDown(std::vector<int>& arr, int root, int last) {
	for (int i = root, left = 2 * i + 1, right = left + 1, max_child = left; left <= last; left = 2 * i + 1, right = left + 1, max_child = left) {
		if (right <= last && arr[right] > arr[left]) max_child = right;
		if (arr[i] < arr[max_child]) {
			int temp = arr[i];
			arr[i] = arr[max_child];
			arr[max_child] = temp;
			i = max_child;
		}
		else break;
	}

}

/*** 堆排序 ***/
void heap_sort(std::vector<int>& arr) {
	int n = arr.size();
	/* 将数组调整为大顶堆 */
	for (int i = n / 2; i >= 0; --i) {
		prcoDown(arr, i, n - 1);
	}
	for (int i = n - 1; i >= 0; --i) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		prcoDown(arr, 0, i - 1);
	}
}

/*** 合并arr中的两个子列到tmparr ***/
void merge(std::vector<int>& arr, std::vector<int> &tmparr, int first, int second, int end) {
	// first : 第一个子列的起始位置，second: 第二个子列的起始位置，end: 第二个子列的最后一个元素下标
	int f = first, s = second, tmp = first;
	while (f < second && s <= end) {
		if (arr[f] < arr[s]) tmparr[tmp++] = arr[f++];
		else tmparr[tmp++] = arr[s++];
	}
	while (f < second) tmparr[tmp++] = arr[f++];
	while (s <= end) tmparr[tmp++] = arr[s++];
}

/*** 归并排序: 非递归 ***/
void merge_sort(std::vector<int> &arr) {
	int n = arr.size();
	std::vector<int> tmparr(arr);
	bool resInTemp = true;
	// 在每sublen个范围内的元素将在第一个循环中总是有序，所以当sublen小于n时，说明n范围内的元素已经有序，可以退出循环
	for (int sublen = 1; sublen <= n; sublen *= 2) {
		for (int j = 0; j + sublen < n; j += 2 * sublen) {
			// 当剩余子列不足一个子列长度，则这部分一定是有序的，直接退出循环，子列长度增长之后会自动将这部分合并
			// 当剩余元素超过一个子列长度，但不足两个子列时，将第一个子列和第一个子列之后的全部元素合并，这两个序列都是有序的，合并后是正确的
			if (j + 2 * sublen < n) {
				if (resInTemp) merge(arr, tmparr, j, j + sublen, j + 2 * sublen - 1);
				else merge(tmparr, arr, j, j + sublen, j + 2 * sublen - 1);
			}
			else {
				if(resInTemp) merge(arr, tmparr, j, j + sublen, n - 1);
				else merge(tmparr, arr, j, j + sublen, n - 1);
			}
		}
		/* if (resInTemp) printVec(tmparr);
		else printVec(arr); */
		resInTemp = !resInTemp;
	}
	if (!resInTemp) {
		for (int i = 0; i < n; ++i) {
			arr[i] = tmparr[i];
		}
	}
}

int getMidPivot(std::vector<int>& arr, int left, int right) {
	int center = (left + right) / 2;
	if (arr[left] > arr[center]) {
		std::swap(arr[left], arr[center]);
	}
	if (arr[left] > arr[right]) {
		std::swap(arr[left], arr[right]);
	}
	if (arr[center] > arr[right]) {
		std::swap(arr[center], arr[right]);
	}
	std::swap(arr[center], arr[right - 1]);
	return right - 1;
}

/*** 普通快速排序 ***/
void normal_quick_sort(std::vector<int>& arr, int left, int right) {
	if (left >= right) return;
	int minEnd = left, maxStart = right;
	int pivot = getMidPivot(arr, minEnd, maxStart);
	maxStart = pivot - 1;
	while(minEnd <= maxStart){
		if (arr[minEnd] > arr[pivot]) {
			while (minEnd <= maxStart && arr[maxStart] >= arr[pivot]) maxStart--;
			if (minEnd <= maxStart) std::swap(arr[minEnd], arr[maxStart]);
			else break;
			minEnd++;
			maxStart--;
		}
		else {
			minEnd++;
		}
	}
	std::swap(arr[minEnd], arr[pivot]);
	normal_quick_sort(arr, left, minEnd - 1);
	normal_quick_sort(arr, minEnd + 1, right);
}

const int CUTOFF = 3;

void quick_sort_recur(std::vector<int> &arr, int left, int right) {
	if (right - left > CUTOFF) {
		int pivot = getMidPivot(arr, left, right);
		int i = left, j = right - 1;
		while (1) {
			while (arr[++i] < arr[pivot]) {}
			while (arr[--j] > arr[pivot]) {}
			if (i < j) {
				std::swap(arr[i], arr[j]);
			}
			else break;
		}
		std::swap(arr[i], arr[pivot]);
		quick_sort_recur(arr, left, i - 1);
		quick_sort_recur(arr, i + 1, right);
	}
	else {
		for (int i = left + 1; i <= right; ++i) {
			int insert_ele = arr[i];
			int j = i - 1;
			while (j >= left && arr[j] >= insert_ele) {
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = insert_ele;
		}
		std::cout << left << " " << right;
		printVec(arr);
	}
}

/*** 优化的快速排序 ***/
void quick_sort(std::vector<int> &arr) {
	quick_sort_recur(arr, 0, arr.size()- 1);
}

bool compareMax(int a, int b) {
	if (a > b) return true;
	return false;
}

bool isShorter(std::string s1, std::string s2) {
	if (s1.size() < s2.size()) {
		return true;
	}
	return false;
}

void sort_test() {
	std::vector<std::string> v{ "abc", "av"};
	std::sort(v.begin(), v.end(), isShorter);
	for (const auto& i : v) {
		std::cout << i << " ";
	}
}