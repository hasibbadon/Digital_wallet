#include <stdio.h>
#include <string.h>


void search(){
    struct debit_info {
    char name[50];
    int amount;
};

typedef struct debit_info dbi;
    FILE *debit;
    debit=fopen("debit.bin","rb");
    if(!debit){
        printf("File doesn't exit");
    }
    else{
        int c;
        dbi search;
        dbi all;
        
        
            printf("Enter the ammount you want to search: ");
            scanf("%d",&search.amount);
       
        printf("\t\t[name] \t\t\t\t\t\t\t[amount use]\n");
        while(fread(&all,sizeof(all),1,debit)){
            if(all.amount==search.amount){
            printf("\t[%s]\t\t\t\t\t\t[%d]\n",all.name,all.amount);
            printf("\n");
        }
        }
    }
    fclose(debit);

}