// Bubble_Sort
#pragma once

#define N        11
#define MAX_QUERY  2048
#define SWAP(a, b, tmp) ((tmp)=(a), (a) = (b), (b) = (tmp))

void Bubble_Sort(int ar[]) {
	int i, j, tmp;
	for (i = N - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (ar[j] > ar[j + 1]) {
				SWAP(ar[j], ar[j + 1], tmp);
			}
		}
	}
}

