#include<stdio.h>

#define num_obj 7


void init_arrays(float* p_by_w,int n,float* profit,float* weight,float* solutions){
    for(int i=0;i<n;i++){
        p_by_w[i]=profit[i]/weight[i];
        solutions[i]=0;
    }
}

int main(){
    float profits[]={10,5,15,7,6,18,3};
    float weights[]={2,3,5,7,1,4,1};
    float profit_by_weight[num_obj];
    float solution[num_obj];

    init_arrays(profit_by_weight,num_obj,profits,weights,solution);

 
    int available_capacity=15;

    

    for(int i=0;i<num_obj && available_capacity>0 ;i++){

        int greatest=0;
        int index = 0;

        for(int j=0 ;j<num_obj;j++)
        {
            if(profit_by_weight[j]>greatest && solution[j]==0){
                index = j;
                greatest = profit_by_weight[j];
            }
        }

        if(available_capacity >= weights[index]){
            solution[index]=1;
            available_capacity = available_capacity - weights[index];
        }

        /* Hanlde Fractionals */

        else if(available_capacity < weights[index]){
            float temp =  available_capacity/weights[index];
            solution[index]=temp;
            available_capacity =- weights[index];
        }
    }

    for(int i=0;i<num_obj;i++){
        printf(" %f ",solution[i]);
    }

}