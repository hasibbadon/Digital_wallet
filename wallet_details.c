#include <stdio.h>
#include <string.h>

struct Wallet_struct{
    char HolderName[50];
    int CreditAmmount;
};
typedef struct Wallet_struct ws;

void Show_wallet_details(){
    FILE *Credit;
    Credit=fopen("Wallet_dt.bin","rb");
    if(!Credit){
        printf("File doesn't exit");
    }
    else{
        ws w1;
        fread(&w1,sizeof(w1),1,Credit);
        printf("Acoount Holder name: %s\n",w1.HolderName);
        printf("\nAcoount CreditAmmount: %d",w1.CreditAmmount);
    }
    fclose(Credit);
    }


    void Add_Credit_Ammount(){
    FILE *Credit;
    Credit=fopen("Wallet_dt.bin","rb");
    if(!Credit){
        printf("File doesn't exit");
    }
    else{
        int ammount;
        ws w1;
        printf("Adding Ammount: ");
        scanf("%d",&ammount);
        fread(&w1,sizeof(w1),1,Credit);
        w1.CreditAmmount+=ammount;
        fclose(Credit);
        Credit=fopen("Wallet_dt.bin","wb");
        fwrite(&w1,sizeof(w1),1,Credit);
        fclose(Credit);
        printf("\n\t***Wallet Amount Added Successfully***\n");
        Show_wallet_details();


    }}



    void Action_On_Credit_Ammount(int a,int ammount){
    FILE *Credit;
    Credit=fopen("Wallet_dt.bin","rb");
    if(!Credit){
        printf("File doesn't exit");
    }
    else{
        // int ammount;

        ws w1;
        // printf("Adding Ammount: ");
        // scanf("%d",&ammount);
        if(a==1){
        fread(&w1,sizeof(w1),1,Credit);
        w1.CreditAmmount+=ammount;
        fclose(Credit);
        Credit=fopen("Wallet_dt.bin","wb");
        fwrite(&w1,sizeof(w1),1,Credit);
        fclose(Credit);
        printf("\n\t***Wallet %d credit Added Successfully***\n",ammount);
        Show_wallet_details();}
        else if(a==2){
        fread(&w1,sizeof(w1),1,Credit);
        w1.CreditAmmount-=ammount;
        fclose(Credit);
        Credit=fopen("Wallet_dt.bin","wb");
        fwrite(&w1,sizeof(w1),1,Credit);
        fclose(Credit);
        printf("\n\t***Wallet Amount deatails***\n");
        printf("Now you have: %d credit",walet_ammount());

        }

    }}
int walet_ammount(){
    FILE *Credit;
    Credit=fopen("Wallet_dt.bin","rb");
    if(!Credit){
        printf("File doesn't exit");
    }
    else{
        ws w1;
        fread(&w1,sizeof(w1),1,Credit);
        return w1.CreditAmmount;
    }
    fclose(Credit);
}

void Add_debit(){
    struct debit_info{
    char name[50];
    int ammount;
};
typedef struct debit_info dbi;
    FILE *debit;
    debit=fopen("debit.bin","ab+");
    if(!debit){
        printf("File not found\n");
    }
    else{
    printf("Enter name of Debit: ");
        dbi d;
        getchar();
        fgets(d.name, sizeof(d.name), stdin);
        d.name[strcspn(d.name, "\n")] = '\0';
    
    printf("Enter the ammount: ");
    scanf("%d",&d.ammount);
    // printf("%d",d.ammount);
    int w_ammount=walet_ammount();
    if(d.ammount<=w_ammount){
    fwrite(&d,sizeof(dbi),1,debit);
    Action_On_Credit_Ammount(2,d.ammount);}
    // printf("Successfully open\n");}
    else{
        printf("Your credit amount is not enough to buy this product!\nTo add the product, please add credit to your wallet.\n");
        printf("\n\t***Wallet Amount deatails***\n");
        printf("Now you have: %d credit\n",walet_ammount());
    }
    }
    fclose(debit);
}

void Edit() {
    struct debit_info {
    char name[50];
    int amount;
};

typedef struct debit_info dbi;
    FILE *debit, *debit_w;
    debit = fopen("debit.bin", "rb+");
    if (!debit) {
        printf("File not found\n");
       
    }

    dbi data[500];
    dbi temp;
    int i = 0, c;

    while (fread(&temp, sizeof(dbi), 1, debit) == 1) {
        strcpy(data[i].name, temp.name);
        data[i].amount = temp.amount;
        i++;
    }

    printf("[number]\t[name]\t\t\t\t\t\t\t[amount]\n");
    for (int a = 0; a < i; a++) {
        printf("[%d]\t%s\t\t\t\t\t\t%d\n", a + 1, data[a].name, data[a].amount);
       
        printf("............................................................................................\n");
    }

    printf("\nWhich number of record do you want to Edit (Enter 0 to cancel): ");
    scanf("%d", &c);

    if (c != 0) {
        printf("Are you sure you want to edit record %d? (Y/N): ", c);
        char confirmation;
        scanf(" %c", &confirmation);

        if (confirmation == 'Y' || confirmation == 'y') {
            fflush(stdin);
            getchar();
            printf("Name: ");
            fgets(data[c - 1].name, sizeof(data[c - 1].name), stdin);
            printf("Amount: ");
            int amount = data[c - 1].amount;
            scanf("%d", &data[c - 1].amount);

            if (amount == data[c - 1].amount) {
                debit_w = fopen("debit.bin", "wb+");
                if (!debit_w) {
                    printf("File not found\n");
                   
                }

                for (int a = 0; a < i; a++) {
                    fwrite(&data[a], sizeof(dbi), 1, debit_w);
                }
                fclose(debit_w);
                printf("Record edited successfully.\n");
            } else {
                printf("It will overwrite your wallet's CREDIT too!\n");
                printf("Are you sure you want to edit the debit amount? (Y/N): ");
                char confirmation;
                scanf(" %c", &confirmation);

                if (confirmation == 'Y' || confirmation == 'y') {
                    if ((amount < data[c - 1].amount) && ((data[c - 1].amount-amount) <= walet_ammount())) {
                        debit_w = fopen("debit.bin", "wb+");
                        if (!debit_w) {
                            printf("File not found\n");
                            
                        }

                        for (int a = 0; a < i; a++) {
                            fwrite(&data[a], sizeof(dbi), 1, debit_w);
                        }
                        Action_On_Credit_Ammount(2, (data[c - 1].amount - amount));

                        fclose(debit_w);
                        printf("\nRecord edited successfully.\n");
                    } else if ((amount > data[c - 1].amount) && ((amount-data[c - 1].amount) <= walet_ammount())) {
                        debit_w = fopen("debit.bin", "wb+");
                        if (!debit_w) {
                            printf("File not found\n");
                            
                        }

                        for (int a = 0; a < i; a++) {
                            fwrite(&data[a], sizeof(dbi), 1, debit_w);
                        }

                        Action_On_Credit_Ammount(1, (amount - data[c - 1].amount));

                        fclose(debit_w);
                        printf("\nRecord edited successfully.\n");
                    } else {
                        printf("You cannot edit this record because your wallet's credit is less than the amount you specified.\n");
                    }
                } else {
                    printf("Edit canceled.\n");
                }
            }
        } else {
            printf("Edit canceled.\n");
        }
    } else {
        printf("Edit canceled.\n");
    }

    fclose(debit);
   
}


// int main(){
//     // int a,ammount;
//     // scanf("%d%d",&a,&ammount);
//     // Action_On_Credit_Ammount(a,ammount);
//     printf("%d",walet_ammount());
// }