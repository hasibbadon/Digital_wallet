#include <stdio.h>
#include <string.h>

struct debit_info {
    char name[50];
    int amount;
};

typedef struct debit_info dbi;

void Sort_by_Price(dbi *data, int i, int order) {
    dbi temp;
    for (int a = 0; a < i - 1; a++) {
        for (int c = 0; c < i - a - 1; c++) {
            if ((order == 1 && data[c].amount > data[c + 1].amount) || (order == 2 && data[c].amount < data[c + 1].amount)) {
                temp = data[c];
                data[c] = data[c + 1];
                data[c + 1] = temp;
            }
        }
    }
    for (int a = 0; a < i; a++) {
        printf("%s %d\n", data[a].name, data[a].amount);
    }
}

void Sort (){
    FILE *debit;
    debit = fopen("debit.bin", "ab+");
    if (!debit) {
        printf("File not found\n");
    } else {
        dbi data[500];
        dbi temp;
        int i = 0;

        while (fread(&temp, sizeof(dbi), 1, debit)) {
            strcpy(data[i].name, temp.name);
            data[i].amount = temp.amount;
            i++;
        }

        int choice;
        printf("SORT LOWEST PRICE TO HIGHEST PRICE (Press 1)\nSORT HIGHEST PRICE TO LOWEST PRICE (Press 2)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        Sort_by_Price(data, i, choice);

        fclose(debit);
    }

    
}
