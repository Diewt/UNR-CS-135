//Name: disp_inventory.c
//Purpose: To further understanding of file I/O
//Author: Chris Diewtragulchai

#include <stdio.h>

#define FILE_NAME "inventory.txt"

int main(void)
{
    int part_number, quanity, count;
    float price;
    FILE *fp;

    fp = fopen(FILE_NAME, "rb");

    printf("Below are the items in your invenotry.\n");
    printf("Part#\tQuantity\tItem Price\n");
    
    for(;;)
    {
        fread(&part_number, sizeof(int), 1, fp);
        fread(&quanity, sizeof(int), 1, fp);
        fread(&price, sizeof(float), 2, fp);

        if(part_number != 0)
        {
            printf("%5d %8d %9.2f\n", part_number, quanity, price);
        }
        else
        {
            break;
        }
    }

    fclose(fp);

    return 0;
}