#include <stdio.h>

void Show_all_debit(){
struct debit_info {
    char name[50];
    int amount;
};

typedef struct debit_info dbi;


    FILE *debit;
    debit = fopen("debit.bin", "rb");

    if (!debit) {
        printf("File not found\n");
       
    }

    dbi d;

    // Read and print data until the end of the file is reached
    while (fread(&d, sizeof(dbi), 1, debit)) {
        printf("Name: %s\n", d.name);
        printf("Amount: %d\n", d.amount);
        printf("\n");
    }

    fclose(debit);

}
