#include <stdio.h>
int count = 0;
int main() {
    int arr[] = {11,4,90,48,73,62,84,190,11};
    int arr_len = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,arr_len-1);
    printf("%s%d\n","total_count=",count);
    print_arr(arr,arr_len);		

    return 0;
}

int partition(int arr[],int low ,int high) {
    int pivot = arr[low];
    while(low<high) {
	while(low<high && arr[high]>=pivot) --high;
	if(low<high) {
	    arr[low] = arr[high];
	    count++;
	    low++;
	}
	while(low<high && arr[low]<=pivot) ++low;
	if(low<high) {
	    arr[high] = arr[low];
	    count++;
	    high--;
	}
    }
    arr[low] = pivot;
    return low;
}

int quickSort(int arr[],int low,int high) {
    if(low<high) {
	int pivot = partition(arr,low,high);
	quickSort(arr,1,pivot-1);
	quickSort(arr,pivot+1,high);
    }
    return 0;
}

int print_arr(int *arr,int arr_len) {
    int i = 0;
    while(i<arr_len) {
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
    return 0;
}
