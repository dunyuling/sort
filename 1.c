#include <stdio.h>

int main() {
    int arr[9] = {11,4,90,48,73,62,84,190,11};
    sort3(arr,9);
    printf("%s\n","----------");
    out(arr,9);
}

//Binary Insertion Sort
sort4(int arr[],int length) {
    int i,j,monitor=-1,low,mid,high,count;
    for(i=1;i<length;i++) {
	arr[monitor]=arr[i];
	low=0;high=i-1;
	while(low<=high){
	    mid=low+high;
	    if(arr[monitor]<arr[mid]) high=mid-1;
	    else low=mid+1;
	}
	for(j=i-1;j>=high+1;j--) {
	    arr[j+1]=arr[j];
	    count++;
	}
	arr[high+1]=arr[monitor];
    }
    printf("%s%d\n","total_count=",count);
}

//Straight Insertion Sort
sort3(int arr[],int length) {
    int i,j,monitor=-1,count=0;
    for(i=1;i<length;i++) {
	if(arr[i] < arr[i-1]) {
	    arr[monitor] = arr[i];
	    arr[i] = arr[i-1];
            //count++;
	    for(j=i-2;arr[monitor]<arr[j]&&j>=0;--j) {
		arr[j+1] = arr[j];
		count++;
	    }	    
	    arr[j+1]=arr[monitor];
	}
    } 
    printf("%s%d\n","total_count=",count);
}

//Simple Selection Sort
sort2(int arr[],int length) {
    int temp,i ,j,k,count = 0;
    for(i=0;i<length;i++) {
	k = i;
        for(j=i+1;j<length;j++) {
	    if(arr[i]>arr[j]) {
		i=j;
	    }
	}
	if(i != k) {
	    temp = arr[k];
	    arr[k] = arr[i];
	    arr[i] = temp;
	    count++;
	}
	i=k;
    }
    printf("%s%d\n","total_count=",count);
}

//Bubble Sort
sort1(int arr[],int length) {
    int temp, i,j, count = 0;
    for(i=0;i<length;i++) {
        for(j=i+1;j<length;j++) {
 	    if(arr[i]>arr[j]) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		count++;
	    }
	}
    } 
    printf("%s%d\n","total_count=",count);

}

out(int arr[],int length) {
   int i;
   for(i=0;i<length;i++) {
       printf("%d\n",arr[i]);
   }
}
