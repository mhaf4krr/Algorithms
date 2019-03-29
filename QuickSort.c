#include<stdio.h>

void swap(int* Array,int a,int b){
    int temp=Array[a];
    Array[a]=Array[b];
    Array[b]=temp;
}

int Partition(int Array[],int low,int high){
    int pivot = Array[low];
    int i=low-1;
    int j=high+1;

    while(i<j){
        do{
            i++;
        }while(Array[i]<=pivot);

        do{
            j--;
        }while(Array[j]>pivot);

        if(i<j){
            swap(Array,i,j);
        }
    }

    swap(Array,low,j);
    return j;
}
void QuickSort(int Array[],int low,int high){

    if(low<high){

    int partition_index = Partition(Array,low,high);
    QuickSort(Array,low,partition_index-1);
    QuickSort(Array,partition_index+1,high);
    
    }
}

int main(){
    int Array[7]={50,20,30,10,5,60,70};
    QuickSort(Array,0,6);

    for(int i=0;i<7;i++){
        printf(" %d ",Array[i]);
    }
}