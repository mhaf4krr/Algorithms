#include<stdio.h>


void Merge(int * Array,int low,int mid,int high){
    int i=low;int j=mid+1;int k=0;
    int TempArray[25];

    while( (i<=mid) && (j<=high) ){
        if(Array[i]<Array[j]){
            TempArray[k]=Array[i];
            i++;k++;
        }
        else if(Array[i]>Array[j]){
            TempArray[k]=Array[j];
            j++;k++;
        }

        else {
            TempArray[k]=Array[i];
            i++;j++;k++;
        }
    }

    while(i<=mid){
        TempArray[k]=Array[i];
        i++;k++;
    }

    while(j<=high){
        TempArray[k]=Array[j];
        j++;k++;
    }

    /* Copy Back */
    k=0;
    for(int i=low;i<=high;i++,k++){
        Array[i]=TempArray[k];
    }

}
void MergeSort(int* Array,int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(Array,low,mid);
        MergeSort(Array,mid+1,high);
        Merge(Array,low,mid,high);
    }
}

int main(){
    int trial[]={50,30,40,10,20,0};
    MergeSort(trial,0,5);
    
    for(int i=0;i<6;i++){
        printf(" %d ",trial[i]);
    }
}