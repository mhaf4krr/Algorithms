#include<stdio.h>
#include<string.h>

int main(){
     
     char String[20];
     char Pattern[20];

     printf("Enter the String ? \n");
     scanf("%s",String);

     printf("Enter the Pattern in String : ' %s ' \n",String);
     scanf("%s",Pattern);

        int flag=0;

        int string_len = strlen(String);
        int pattern_len = strlen(Pattern);

     for(int i=0;i<string_len;i++){

         int j; /* Note declared outside its loop */
         for(j=0;j<pattern_len;j++){
             if(String[i+j] != Pattern[j])
             break;
         }

         if(j == pattern_len){
             flag=1;
             printf("Pattern has been found at index : %d \n",i);
         }
     }

        if(!flag){
            printf("Pattern didnt match anywhere");
        }

}