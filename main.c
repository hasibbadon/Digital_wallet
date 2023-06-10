#include <stdio.h>
#include "Options.c"
void Option_op(int option);
int main(){
    int option;
        printf("\t\t\t ****Options****\n press 1\t For watch wallet details.\n press 2\t For Add credit ammounts into your wallet.\n press 3\t For Add spend ammounts into your wallet.\n press 4\t For all your spend details.\n press 5\t For edit a history of spend.\n press 6\t For search a spemd history.\n press 7\t For deleate a history of spend.\n press 8\t For create a new wallet and deleate old one.\n press 9\t For watch all the available options.\n press 0\t For exit.\n");
             


    do{
        
        printf("\n\nOption: ");    
        scanf("%d",&option);
        if(!option)
        break;
        if(option<=9 && option >=1){
            // printf("you type %d\n",option);
            Option_op(option);

        }
        else
        printf("\t\t*** Invalid key.For see all options press 9  \n\t\t\t\tOr \n\t\t    For exit press 0 ****\n");
    }while(option);

}

