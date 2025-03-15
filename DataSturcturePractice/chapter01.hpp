#pragma once
#include<iostream>
void printN_for(int n);
void printN_recursion(int n);

//printRunningTime(calcuExpN_normal);
//std::cout << std::endl;
//printRunningTime(calcuExpN_develop);
void calcuExpN_normal(double a[], double x, size_t n);
void calcuExpN_develop(double a[], double x, size_t n);
void printRunningTime(void(*f)(double*, double, size_t));

//int a[] = { 1, -2, 3, 14, -6, 10 };
//MaxSubSeqSum1(a, 6);
void MaxSubSeqSum1(int a[], int n);
void MaxSubSeqSum2(int a[], int n);



//int array[3][4] = { {1, 2, 59, 33}, {15, 8, 13, 10}, {13, 2, 15, 7} };
//saddle(array);
/**求鞍点，即同时是一行的最小值和一列的最大值的元素*/
template<int N, int M>
void saddle(int (&A)[M][N]) {
	int rowMin[M];
	int calMax[N];
	for (int i = 0; i < M; i++) {
		int min = A[i][0];
		rowMin[i] = 0;
		for (int j = 1; j < N; j++) {
			if (min > A[i][j]) {
				rowMin[i] = j;
				min = A[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int max = A[0][i];
		calMax[i] = 0;
		for (int j = 1; j < M; j++) {
			if (max < A[j][i]) {
				calMax[i] = j;
				max = A[i][j];
			}
		}
	}

	int i = 0;
	bool b = M < N;
	for (b ? i = M - 1 : i = N - 1; i >= 0; i--) {
		if (b) {
			if (calMax[rowMin[i]] == i)  std::cout << "A[" << i << "][" << rowMin[i] << "]是鞍点" << std::endl;
		}
		else {
			if (rowMin[calMax[i]] == i)  std::cout << "A[" << calMax[i] << "][" << i << "]是鞍点" << std::endl;
		}
	}
}