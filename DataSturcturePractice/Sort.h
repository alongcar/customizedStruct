#pragma once
#include<vector>
#include<forward_list>
/*** ц╟ещеепР ***/
void Bubble_sort(std::vector<int> &arr, int n);

void printVec(const std::vector<int>& arr);

void Bubble_sort(std::forward_list<int>& flst, int n);

void insertion_sort(std::vector<int>& arr);

void shell_sort(std::vector<int>& arr);

void heap_sort(std::vector<int>& arr);

void merge_sort(std::vector<int>& arr);

void normal_quick_sort(std::vector<int>& arr, int left, int right);

void quick_sort(std::vector<int>& arr);

void sortPractice();

void sort_test();