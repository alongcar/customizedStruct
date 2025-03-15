#include"chapter01.hpp"
#include<iostream>
#include<stdio.h>
void printN_for(int n) {
	for (int i = 1; i <= n; i++) {
		std::cout << i << " ";
	}
}

void printN_recursion(int n) {
	if (n) {
		printN_recursion(n - 1);
		std::cout << n << " ";
	}
}

void calcuExpN_normal(double a[], double x, size_t n) {
	double result = 0;
	for (size_t i = 0; i < n; i++) {
		result += a[i] * pow(x, i);
	}
	// std::cout << result << std::endl;
}

void calcuExpN_develop(double a[], double x, size_t n) {
	if (n == 0) {
		// std::cout << 0; 
		return;
	}
	double result = a[n-1];
	if (n == 1) {
		// std::cout << a[n - 1]; 
		return;
	}
	for (int i = n-2; i >= 0; i--) {
		result = a[i] + result * x;
	}
	// std::cout << result << std::endl;
}

void printRunningTime(void(*f)(double*, double, size_t)) {
	double a[] = { 1, 2, 3, 4 };
	double x = 1.5;
	size_t n = sizeof(a) / sizeof(a[0]);
	const double MAX_TIME = 100000;
	clock_t start = clock();
	for(int i = 0;i < MAX_TIME;i++)
	    f(a, x, n);
	clock_t end = clock();
	double desction = ((double(end - start))/ CLK_TCK)/ MAX_TIME ;
	printf("%f16\n", desction);
}

// static int count = 0;
/**求序列ai到aj的和,其中ai>aj*/
int getFij(int i, int j, int a[]){
	int sum = 0;
	for (int k = i; k >= j; k--) {
		// ++count;
	    
		sum += a[k];
	}
	return sum;
}

/**求序列n的最大子序列方式1-暴力法的简化*/
void MaxSubSeqSum1(int a[], int n){
	int maxsum = 0;
	for (int i = 0; i < n; i++) {
		// 计算含i的最大子序列
		int sumij = 0;
		for (int j = i; j >= 0; j--) {
			sumij += a[j];
			// std::cout << sumij;
			if (maxsum < sumij) maxsum = sumij;
			// ++count;
		}
	}
	// std::cout << count << std::endl;
	std::cout << "最大子序列和：" << maxsum << std::endl;
}

/**求序列n的最大子序列方式2-在线处理法
* 该方法利用最大子序列只会从正值中得到来计算
*/
void MaxSubSeqSum2(int a[], int n) {
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < n; i++) {
		ThisSum += a[i]; // 向右累加
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;/* 发现更大的和则更新当前结果 */
		else if (ThisSum < 0)/* 如果当前子列和为负，则不可能使后面的部分增大，抛弃之*/
			ThisSum = 0;
	}
	std::cout << MaxSum;
}

