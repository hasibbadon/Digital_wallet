#include <stdio.h>
#include <string.h>



void Delete() {
    struct debit_info {
    char name[50];
    int amount;
};

typedef struct debit_info dbi;
    FILE *debit, *debit_w;
    debit = fopen("debit.bin", "ab+");
    if (!debit) {
        printf("File not found\n");
    } else {
        dbi data[500];
        dbi temp;
        int i = 0, c;

        while (fread(&temp, sizeof(dbi), 1, debit)) {
            strcpy(data[i].name, temp.name);
            data[i].amount = temp.amount;
            i++;
        }

        printf("[number] \t\t[name] \t\t\t\t\t\t\t[amount]\n");
        for (int a = 0; a < i; a++) {
            printf("[%d]\t[%s]\t\t\t\t\t\t[%d]\n", a + 1, data[a].name, data[a].amount);
            printf("\n");
        }

        printf("Which number of record do you want to delete (Enter 0 to cancel): ");
        scanf("%d", &c);

        if (c != 0) {
            printf("Are you sure you want to delete record %d? (Y/N): ", c);
            char confirmation;
            scanf(" %c", &confirmation);

            if (confirmation == 'Y' || confirmation == 'y') {
                debit_w = fopen("debit.bin", "wb+");
                for (int a = 0; a < i; a++) {
                    if (a != c - 1) {
                        fwrite(&data[a], sizeof(dbi), 1, debit_w);
                    }
                }
                fclose(debit_w);
                printf("Record deleted successfully.\n");
            } else {
                printf("Deletion canceled.\n");
            }
        } else {
            printf("Deletion canceled.\n");
        }

        fclose(debit);
    }

   
}
