#include<stdio.h>

int max(int a, int b) { return (a > b)? a : b; } 

int main(){
    
    int profits[] = {0,60,100,120}; 
    int weights[] = {0,10,20,30}; 
    
    /* IMPORTANT :  Add 0 as first entry in both the Arrays and then proceed as usual*/
    /* Number of objects = actual objects(inserted apart from 0 entry)*/

    int objects = 3;
    int capacity_constraint = 50;

    int Table[objects+1][capacity_constraint+1];

    for(int i=0 ;i<= objects;i++) {

        for(int w=0 ; w <= capacity_constraint ; w++){

            /*3 cases exist
            1) Fill row 0 and col 0 with Zero
            2) When weight of Object is less than a column use Formula
            3) Copy the entry from previous row
            */
             
             if(i==0 || w==0){
                 Table[i][w]=0;
             }
            else if(weights[i]<=w){
                 Table[i][w] = max(Table[i-1][w] , Table[i-1][w-weights[i]] + profits[i]);
             }

             else {
                 /* Weight of an Object is Greater*/
                 Table[i][w] = Table[i-1][w];
             }
        }
    }

               for(int i=0 ; i<objects+1;i++){
                for(int j=0;j<capacity_constraint+1 ; j++){
                    

                    printf(" %d ",Table[i][j]);
                }
                printf("\n");
            }


      printf(" Max Profit : %d ",Table[objects+1][capacity_constraint+1]);


    
}