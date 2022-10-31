#include "the1.h"
#include <climits>


//You can add your own helper functions
void insertionSort(int* arr, long &comparison, long & swap, int size) 
{
    for(int i = 1; i < size; i++) {
        int x = arr[i], j = i - 1;
        while(j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparison++;
            swap++;
        }
        if(j >= 0) {
            comparison++;
        }
        arr[j + 1] = x;
    }
}

void heapify(int* arr, int size, long &comparison, long &swap, int i, int *orArr) {
    int l, r, s;
    s = i;
    l = 2*i;
    r = 2*i + 1;
	
    if(l <= size && arr[l] < arr[s]) {
        s = l;
    }
    if(r <= size && arr[r] < arr[s]) {
        s = r;
    }
    if(l <= size && arr[l] != INT_MAX)
    	{comparison++;}
    if(r <= size && arr[r] != INT_MAX)
    	{comparison++;}
    if(s != i) {
        int temp = arr[i];
        arr[i] = arr[s];
        arr[s] = temp;
		temp = orArr[i];
		orArr[i] = orArr[s];
		orArr[s] = temp;
        swap++;
        heapify(arr, size, comparison, swap, s, orArr);
    }
}


int kWayMergeSortWithHeap(int* arr, int K, int size, long& comparison, long& swap){
  
  int number_of_calls = 1;
	if(size < K) {
	    insertionSort(arr, comparison, swap, size);

	}
	else {
	    int divider = size / K, myArr[size], minHeap[K + 1], myArrSize = 0, arrTracker[K], originalTracker[K + 1];
	    int * pTracker[K], *temp = arr;
	    minHeap[0] = originalTracker[0] = INT_MAX;
	    for(int i = 0; i < K; i++) {
	        number_of_calls += kWayMergeSortWithHeap(temp, K, divider, comparison, swap);
	        pTracker[i] = temp;
	        arrTracker[i] = 0;
	        minHeap[i+1] = *temp;
			originalTracker[i+1] = i+1;
	        temp += divider;
	    }
		for(int j = K / 2; j > 0; j--) {
	        heapify(minHeap, K, comparison, swap, j, originalTracker);
	    }
	    while(myArrSize < size) {
	        myArr[myArrSize] = minHeap[1];
			if(arrTracker[originalTracker[1]-1] + 1 < divider) {
			arrTracker[originalTracker[1]-1] += 1;
			minHeap[1] = *(pTracker[originalTracker[1]-1] + arrTracker[originalTracker[1]-1]);
		}
		else {
			minHeap[1] = INT_MAX;
		}
	        heapify(minHeap, K, comparison, swap, 1, originalTracker);
	        myArrSize++;
	    }
	    for(int i = 0; i < size; i++) {
	        arr[i] = myArr[i];
	    }
	}
	    
	//Your code here
	
	
	return number_of_calls;
}


