#include <stdio.h>



int Wallet_open(){
    struct Wallet_struct{
    char HolderName[50];
    int CreditAmmount;
};
typedef struct Wallet_struct ws;
    FILE *Credit,*Debit;
    Credit=fopen("Wallet_dt.bin","wb");
    if(!Credit){
        printf("File doesn't exit");
    }
    else{
        ws w1;
        printf("Enter the Wallet Holder Name: ");
        getchar();
        gets(w1.HolderName);
        printf("Enter the Credit Ammount: ");
        scanf("%d",&w1.CreditAmmount);
        fwrite(&w1,sizeof(w1),1,Credit);
        Debit=fopen("debit.bin","wb");
        

    }
    fclose(Credit);
    fclose(Debit);
}