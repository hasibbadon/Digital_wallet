#include "Show_debit.c"
#include "wallet_details.c"
#include "sort_debit.c"
#include "delete_debit.c"
#include "wallet_open.c"
#include "search_debit.c"


void Option_op(int option){
    switch (option)
    {
    case 1:
        printf("\n\n\t\t\t***Showing wallet details***\n\n");
        Show_wallet_details();
        break;
    case 2:
        printf("\n\n\t\t\t***Adding credit ammount in your wallet***\n");
        int ammount;
        printf("Ammount you want to add: ");
        scanf("%d",&ammount);
        Action_On_Credit_Ammount(1,ammount);
        break;
    case 3:
        printf("\n\n\t\t\t***Adding Spend History***\n");
        Add_debit();
        
        
        break;
    case 4:
        printf("\n\n\t\t\t***Showing wallet details***\n\n");
         printf(" SORT By TIME (Press 1)\n SORT LOWEST PRICE TO HIGHEST PRICES OR HIGHEST PRICE TO LOWEST PRICE (Press 2)\n");
         int c;
         printf("Enter your choice: ");
        scanf("%d", &c);
         if(c==1)
            Show_all_debit();
        else{
            Sort();
        }
        break;
     case 5:
        printf("\n\n\t\t\t***Editing a Spend History***\n");
        Edit();
        
        break;
    case 6:
        printf("\n\n\t\t\t***Search a Spend History***\n");
        search();
        
        break;
    case 7:
        printf("\n\n\t\t\t***Deleting Spend History***\n");
        Delete();
        break;
    case 8:
                printf("Do you really want to Open new wallet and Remove your old wallet ? (Y/N): ");
                char confirmation;
                scanf(" %c", &confirmation);

                if (confirmation == 'Y' || confirmation == 'y'){
                    Wallet_open();
                    printf("New wallet Created successful");
                }
                else
                {
                    printf("\n wallet creation cancled");
                }
                break;
                
    default:
        printf("\t\t\t ****Options****\n press 1\t For watch wallet details.\n press 2\t For Add credit ammounts into your wallet.\n press 3\t For Add spend ammounts into your wallet.\n press 4\t For all your spend details.\n press 5\t For edit a history of spend.\n press 6\t For search a spemd history.\n press 7\t For deleate a history of spend.\n press 8\t For create a new wallet and deleate old one.\n press 9\t For watch all the available options.\n press 0\t For exit.\n");
        break;
    }
}