#include<stdbool.h>
#include<stdio.h>



bool isSafetoPlace(int board[][10],int row,int column,int n){
    /*Queen will be safe to place if and only if 
        1) No Other Queen is Placed in same column -to find itterate over previous
        2) No Other Queen is Placed in Right Upper Diagonal
        3) No Other Queen is Placed in Left Upper Diagonal
    */
    // 1 - Same Column Check
    for(int i=0 ;i<row;i++){
        if(board[i][column]==1){
            /* Queen already placed in some previous row at the column we are checking for . Thus we cannot place so return false*/
            return false;
        }
    }

  

    // 2 - Right Upper Diagonal

        int x=row;
        int y=column;

        while(x>=0 && y<n){
            if(board[x][y]==1)
            {return false;}
            x--;
            y++;
        }

    //3 - Left Upper Diagonal 

        x=row;
        y=column;

        while(x>=0 && y>=0){
            if(board[x][y]==1)
            {return false;}
            x--;
            y--;
        }
    /* if control reaches upto here it means , these conditions are not satisfied and Queen is safe to be placed*/

    return true;
}

void DisplayBoard(int board[][10],int n){
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n;j++){
            
            if(board[i][j]==1){
                printf(" Q ");
            }

            else {
                printf(" _ ");
            }
        }

        printf("\n\n");
    }
}

bool solveNQueen(int board[][10],int current_row,int n){
    /*Base Case: successfully placed Queens in N rows */
    if(current_row == n){
        /* Print Board Config*/
        printf("\n\n ************* \n\n");
        DisplayBoard(board,n);
        return false;
    }

    /* Recursie Case: Try to find the the right column in current row*/
    for(int current_column=0;current_column<n;current_column++){
        
        if(isSafetoPlace(board,current_row,current_column,n)){
            // Place the Queen assuming this is correct position
            board[current_row][current_column]=1;

            /* Ask the Remaining Board if next Queen can be Placed in Next Row*/
            bool canNextQueenBePlaced = solveNQueen(board,current_row+1,n);
            if(canNextQueenBePlaced){
                /* it means we have placed Queen above is Right and need not be shifted*/
                return true;
            }

            /* if next queen cannot be placed , our above assumption is wrong and needs to be corrected , Queen needs to be shifted in the current row and possibiliites need to be recalculated*/
            // Backtrack
            else board[current_row][current_column]=0;
        }

    }

    // At this control point we have tried all possible positions in current row but have failed to place a Queen, hence return False

    return false;

}   

int main(){
    
    /* Initialize board to 0 */
    int board[10][10]={0};
 

    solveNQueen(board,0,4);
   

}