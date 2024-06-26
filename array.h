#ifndef TESTES_ARRAY_H
#define TESTES_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

bool in_arr(int key, int *arr, unsigned len) {
	for (unsigned i = 0; i < len; i++)
		if (arr[i] == key)
   		return 1;
	return 0;
}

float arr_avg(int *arr, unsigned len) {
	if (!len) return 0;
		float acc = 0;
	for (unsigned i = 0; i < len; ++i)
		acc += arr[i];
 	return acc / len;
}

int bin_search(int key, int *arr, unsigned len) {
	int stt = 0, end = len-1, mid;
 	while (stt <= end) {
		mid = (stt + end) / 2;
		if (key > arr[mid]) stt = mid + 1;
		else if (key < arr[mid]) end = mid - 1;
		else return mid;
 	}
 	return -1;
}

int seq_search(int key, int *arr, unsigned len) {
	for (unsigned i = 0; i < len; i++)
  	if (arr[i] == key)
   		return i;
 	return -1;
}

int arr_max(int *arr, unsigned len) {
	float max = arr[0];
	for (unsigned i = 1; i < len; ++i)
  	if (arr[i] > max)
   		max = arr[i];
 	return max;
}

int arr_min(int *arr, unsigned len) {
	float min = arr[0];
	for (unsigned i = 1; i < len; ++i)
  	if (arr[i] < min)
   		min = arr[i];
	return min;
}

int arr_sum(int *arr, int len) {
	float acc = 0;
	for (int i = 0; i < len; ++i)
  	acc += arr[i];
	return acc;
}

void make_arr(int *arr, unsigned len) {
	for (unsigned i = 0; i < len; ++i)
		scanf("%d", &arr[i]);
}

void insertion_sort(int *arr, unsigned len) {
	int j, key;
 	for (unsigned i = 1; i < len; ++i) {
		key = arr[i],
		j = i-1;
		while (0 <= j && arr[j] > key)
			arr[j+1] = arr[j], --j;
		arr[j+1] = key;
	}
}

void invert_arr(int *arr, unsigned len) {
	int temp;
	for (unsigned i = 0; i < len/2; ++i)
		temp = arr[i],
		arr[i] = arr[len-1-i],
		arr[len-1-i] = temp;
}

void msortR(int *arr, int *aux, int a, int b) {
	if (a < b) {
		int i = a, j = (a + b) / 2 + 1, k = i;
		msortR(arr, aux, a, j - 1);
		msortR(arr, aux, j, b);
		while (i < j && j <= b) {
			if (arr[i] < arr[j]) aux[k] = arr[i], i++, k++;
			else aux[k] = arr[j], j++, k++;
		}
		while (i < j) aux[k] = arr[i], ++i, ++k;
		while (j <= b) aux[k] = arr[j], ++j, ++k;
		for (k = a; k <= b; ++k) arr[k] = aux[k];
	}
}

void msort(int *arr, int len) {
	int *aux = malloc(len * sizeof(int));
	msortR(arr, aux, 0, len-1);
	free(aux);
}

void quick_sort(int *arr, unsigned stt, unsigned end) {
    int i = stt, j = end, temp;
    if (i < j) {
        int mid = (i + j) / 2 + 1;
        while (arr[i] < arr[mid]) ++i;
        while (arr[j] > arr[mid]) --j;
        if (i <= j)
            temp = arr[i],
            arr[i] = arr[j],
            arr[j] = temp,
            ++i, --j;
    }
    if (stt < j) quick_sort(arr, stt, j);
    if (i < end) quick_sort(arr, i, end);
}

void selection_sort(int *arr, unsigned len) {
	int temp;
	unsigned i, j, min;
	for (i = 0; i < len-1; i++) {
		min = i;
		for (j = i+1; j < len; ++j)
			if (arr[j] < arr[min])
				min = j;
		temp = arr[i],
		arr[i] = arr[min],
		arr[min] = temp;
	}
}

void show_arr(int *arr, unsigned len) {
	for (unsigned i = 0; i < len; i++)
		printf("%d\n", arr[i]);
	printf("\n");
}

#endif
