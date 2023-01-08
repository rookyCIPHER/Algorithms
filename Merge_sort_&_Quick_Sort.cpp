/*
Refer: 

1) https://youtu.be/y_5CFcKkc-8 (29.3 Swap function | swap without extra variable by Sreejith AV)
2) https://youtu.be/LVmWgba61iM (30.1 Merge Sort by Sreejith AV)
3) https://youtu.be/MW-dP_Sq2R8 (31.1 Simplified version of Quicksort algorithm | Worst case analysis | Average case analysis by Sreejith AV)
4) https://youtu.be/1BgA7G6R9BI (31.2 Quicksort algorithm by Sreejith AV)

*/



int* swap(int* arr, int i1, int i2){   //i1 and i2 are the two indexes to be swapped
   int a=arr[i1];
   arr[i1]=arr[i2];
   arr[i2]=a;
   return arr;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}



/*
//
void merge(int* arr1, int* arr2, int n){
    int i=0;
    int j=0;
    int k=0;
    int ptr[2*n];

    while(i<n && j<n){

       if(arr1[i]<arr2[j]){
         ptr[k]=arr1[i];
         i++;
       } else {
         ptr[k]=arr2[j];
         j++;
       }
       k++;
    }
   
    for( ;i<n;i++){
        ptr[k]=arr1[i];
        k++;
    }

    for( ;j<n;j++){
        ptr[k]=arr2[j];
        k++;
    }

}

//merge sort
void merge_sort(int* arr, int start, int end){
    int ptr[end-start+1];

    if((end-start)+1==2){ //base case
        if(arr[start]>arr[end]){
            swap(arr,start,end);
            ptr[start]=arr[start];
            ptr[end]=arr[end];
        }
    }

    int ptr1[((start+end)/2)+1];
    int ptr2[((start-end)/2)+1];

    merge_sort(arr,start,(start+end)/2);
    merge_sort(arr,((start+end)/2)+1,end);
    merge(ptr1,ptr2,((end-start)/2)+1);

}
*/


// merge sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
 

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];


    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 //keep doing the splitting until we reach size 1 where it returns because l=r so nothing to execute, then it goes on to applying merging function previous recrusive call which is size 2 and so on backwards.
        merge(arr, l, m, r);
    }
}


//quick sort

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}











/////////////////////////////////////////////////////////////////////////
//MY VERSION OF QUICKSORT-Here pivot is only used for comparison but not placed simultaneously

/*
#include<stdio.h>
#include<stdlib.h>

void swap(int x, int y, int arr[]){
    int temp=arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}

void printArray(int arr[],int length){
        for(int x=0; x<length; x++){
            printf("%d ", arr[x]);
        }
        printf("\n");
}

void QuickSort(int start, int end, int arr[]){

    if(start<end){
        int pivot=arr[start];
        int i=start;
        int j=end;
        while(i<j){
            while(arr[i]<pivot){
                if((i+1)>end){
                    break;
                }
                i++;
            }
            while(arr[j]>=pivot){
                if((j-1)<start){
                    break;
                }
                j--;
            }
            if(i<j){
                swap(i,j,arr);
            }

            //pivot as the first element
        }

        if(i==j){
             QuickSort(start,j,arr);
             QuickSort(j+1,end,arr);           
        } else{
             QuickSort(start,j,arr);
             QuickSort(i,end,arr);
        }

    }

}


int main(){
    int arr[]={1,20,13,45,21,6,7,8};
    int length=8;
    QuickSort(0,(length-1),arr);
    printArray(arr,length);
    return 0;
}
*/

/*
Another Method-Here pivot is placed at correct position simultaneously

void QuickSort(int start, int end, int* arr){

    if(start<end){
        counter+=1;
        int pivot=arr[start];
        int j =end;

        for(int i=end;i>start;i--){
            if(arr[i]>pivot){
                swap(i,j,arr);
                j--;
            }
        }
        swap(start,j,arr);
        QuickSort(start,j-1,arr);
        QuickSort(j+1,end,arr);

    } 
   )
*/
