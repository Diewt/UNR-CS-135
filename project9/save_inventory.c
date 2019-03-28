//Name: save_inventory.c
//Purpose: To further understanding of file I/O
//Author: Chris Diewtragulchai

#include <stdio.h>

#define FILE_NAME "inventory.txt"

int main(void)
{
    int part_number, quanity;
    float price;
    FILE *fp;

    fp = fopen(FILE_NAME, "wb+");

    printf("This program stores a business inventory.\n");

    for(;;)
    {
        printf("Please enter item data (part number, quantity, price): ");
        scanf("%d, %d, %f", &part_number, &quanity, &price);

        if(part_number != 0)
        {
            fwrite(&part_number, sizeof(int), 1, fp);
            fwrite(&quanity, sizeof(int), 1, fp);
            fwrite(&price, sizeof(float), 2, fp);
        }
        else
        {
            fwrite(&part_number, sizeof(int), 1, fp);
            printf("Thank you. Inventory stored in file inventory.txt.\n");

            fclose(fp);

            return 0;
        }
    }
}