#include <stdio.h>



int main() {
    int arr[] = {11,4,90,48,73,62,84,190,11};
    int arr_len = sizeof(arr)/sizeof(arr[0]);

    print_arr(arr,arr_len);
    shellsort(arr,arr_len);
    print_arr(arr,arr_len);

    return 0;

}

int count = 0;
shellinsert(int *arr,int dk,int arr_len) {
    int i,j,monitor=-1;
/*    for(i=dk;i<arr_len;i++) {
	if(arr[i]<arr[i-dk]) {
	    arr[monitor] = arr[i];
	    arr[i] = arr[i-dk];
	    for(j=i-dk*2;j>=0 && arr[monitor]<arr[j];j-=dk) {
		arr[j+dk] = arr[j];
	    }
	    arr[j+dk] = arr[monitor];
	}
    } */

    for(i=dk;i<arr_len;i++) {
	if(arr[i]<arr[i-dk]) {
	    arr[monitor] = arr[i];
	    for(j=i-dk;j>=0 && arr[monitor]<arr[j];j-=dk) {
		arr[j+dk] = arr[j];
	    }
	    arr[j+dk]=arr[monitor];
	}
    }    

    printf("%s%d\n","total_count=",count);
}

shellsort(int *arr ,int arr_len) {
    int dk = arr_len/2;
    while(dk>0) {
	printf("%d%s",dk,"------------");
        shellinsert(arr,dk,arr_len);
        dk = dk/2; 
    }
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

swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
