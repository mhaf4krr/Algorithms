#include<stdio.h>

int main(){

    // D - Dimensions Array
    int D[] = {5,4,6,2,7};

    int Matrix[10][10]={0};
    int Split[10][10]={0};

    int n = 5; // Elements in Dimension Array
    /*
    Matrix - Matrix Cost Matrix
    Split  - Split Matrix stores where does the split occur
    */

   /* we need to find the cost for Matrix Multiplication in following Order
       we need to find diagonal elements for upper triangle diagonals
   */
    int j,min,q;

    for(int d=1 ; d < n-1 ; d++){

        for(int i=1 ; i < n-d ; i++){

            // i -> Rows , j is calculated using i and d

            j= i+d;
            min = 32767;
            Matrix[i][j]=min;
            

            for(int k=1 ; k<= j-1; k++){
                q = Matrix[i][k] + Matrix[k+1][j] + D[i-1] * D[k] * D[j];
                
                if(q<min){
                    min = q;
                    Split[i][j] = k;
                }

                
            }

            Matrix [i][j] = min;

        }
    }


    printf(" Answer : %d \n",Matrix[1][n-1]);
    
    for(int i=1 ; i<n ;i++){

        for(int j=1 ; j<n ;j++)
        {
            printf(" %d ",Matrix[i][j]);
        }

        printf("\n");
    }
}