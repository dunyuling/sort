#include <stdio.h>

typedef struct heap_t {
    int *arr;
    int heapMaxIndex;
    int arrLength;
}Heap;
void printArr(int *p ,int size);
Heap *createHeap(int *p ,int arrLength,Heap *hp);
void sortHeap(Heap *hp);

int main() {
	int arr[9] = {11,4,90,48,73,62,84,190,11};
	printArr(arr,9);
	
	Heap hpa,*phpa;
	phpa = createHeap(arr,9,&hpa);
	printArr(arr,9);
	sortHeap(phpa);
	
	printArr(arr,9);
	return 0;
}

void printArr(int *p ,int size) {
	int i;
	for(i=0;i<size;i++) {
		printf("%d\t",p[i]);
	}
	printf("\n");
}

void maxHeapify(Heap *hp,unsigned int nodei) {
	unsigned int l = (nodei+1) << 1 -1;
	unsigned int r = (nodei+1) << 1;
	unsigned int largest = 0;														
	int heapMaxI = hp->heapMaxIndex;
	
	if(l <= heapMaxI && hp->arr[l] > hp->arr[nodei])
		largest = l;
	else 
		largest = nodei;

	if(r <= heapMaxI && hp->arr[r] > hp->arr[largest])
		largest = r;

	if(largest != nodei) {
		int tmp ;
		tmp = hp->arr[largest];
		hp->arr[largest] = hp->arr[nodei];
		hp->arr[nodei] = tmp;

		maxHeapify(hp,largest);
	} else {
		return;
	}
}

Heap *createHeap(int *arrp,int arrLength,Heap *hp) {
	hp->arr = arrp;
	hp->heapMaxIndex = arrLength-1;
	hp->arrLength = arrLength;

	int i;
	for(i=arrLength >> 1 -1;i>=0;i--) {
		maxHeapify(hp,i);
	}	
	return hp;
}

void sortHeap(Heap *hp) {
	int tmp ;
	int last;
	while(hp->heapMaxIndex > 0) {
		last = hp->heapMaxIndex;
		tmp = hp->arr[last];
		hp->arr[last] = hp->arr[0];
		hp->arr[0] = tmp;
		hp->heapMaxIndex -= 1;
		maxHeapify(hp,0);
	}
}
