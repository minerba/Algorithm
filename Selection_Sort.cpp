// Selection_sort
#pragma once

#define N        11
#define MAX_QUERY  2048
#define SWAP(a, b, tmp) ((tmp)=(a), (a) = (b), (b) = (tmp))

void Selection_Sort(int ar[]){
	int i, j, least, tmp; 
	for (i = 0; i < N - 1; i++){
		least = i; 
		for (j = i + 1; j < N; j++){
			if (ar[least] > ar[j]){ // Descending  &&  Ascending  
				least = j; 
			}
		}
		if (i != least) 
			SWAP(ar[i], ar[least], tmp);
	}
	return; 
}




