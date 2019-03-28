//Name: save_inventory_c.c
//Purpose: To further understanding of file I/O
//Author: Chris Diewtragulchai

#include <stdio.h>

#define FILE_NAME "inventory.txt"

int main(void)
{
    int part_number, quanity, tracker[20] = {0}, count = 0, counter = 0, status, inventory_num = 1;
    float price;
    FILE *fp;

    fp = fopen(FILE_NAME, "wb+");

    printf("This program stores a business inventory.\n");

    for(;;)
    {
        printf("Please enter item data (part number, quantity, price): ");
        scanf("%d, %d, %f", &part_number, &quanity, &price);


        for(counter = 0;counter < inventory_num; counter++)
        {
            if(tracker[counter] != part_number)
            {
                tracker[count] = part_number;
                count++;
                status = 1;
            }
            else
            {
                status = 0;
            }
        }

        inventory_num++;

        if (status == 1)
        {
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
        else
        {
            printf("This item has been entered before.\n");
        }
    }
}