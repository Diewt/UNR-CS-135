//Name: collection.c
//Purpose: Determining what Bob can buy with his budget
//Author: Chris Diewtragulchai

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int collection_volume1, collection_volume2, collection_volume3, volume_price1, volume_price2,
    volume_price3, budget, collection_price1, collection_price2, collection_price3, 
    total_collection_price;

    printf("Enter volumes and price per volume for collection 1: ");
    scanf("%1d %2d", &collection_volume1, &volume_price1);

    printf("Enter volumes and price per volume for collection 2: ");
    scanf("%1d %2d", &collection_volume2, &volume_price2);

    printf("Enter volumes and price per volume for collection 3: ");
    scanf("%1d %2d", &collection_volume3, &volume_price3);

    printf("Enter Bob's budget: ");
    scanf("%d", &budget);

    collection_price1 = collection_volume1 * volume_price1;
    collection_price2 = collection_volume2 * volume_price2;
    collection_price3 = collection_volume3 * volume_price3;
    total_collection_price = collection_price1 + collection_price2 + collection_price3;

    if ( budget > 0 )
        {
            printf("(1) Bob has some money to buy collections.\n");
        }
    else 
        {
           printf("(1) Bob does not have money to buy anything.\n");
        }


    if ( budget > total_collection_price )
        {
            printf("(2) Bob has enough money to buy all three collections.\n");
        }
    else
        {
            printf("(2) Bob does not have enough money to buy all three collections.\n");
        }


    if ( (collection_price1 > budget) + (collection_price2 > budget) + (collection_price3 > budget) >= 2 )
        {
            printf("(3) At least two collections are more expensive than Bob’s budget.\n");
        }
   else
        {
            printf("(3) At least two collections are cheaper than or equal to Bob’s budget.\n");
        }


    if ( (collection_price1 == collection_price2) + (collection_price2 == collection_price3) + (collection_price3 == collection_price1) >= 1 )
        {
            printf("(4) At least two collections cost the same amount of money.\n");
        }
    else
        {
            printf("(4) No two collections have the same price.\n");
        }
        

    if ( (collection_price1 <= budget) + (collection_price2 <= budget) + (collection_price3 <= budget) == 1)
        {
            printf("(5) Only one collection is cheaper than or equal to Bob’s budget\n");
        }
    else    
        {
            printf("(5) More than one collection is cheaper than or equal to Bob’s budget or they are all more expensive.\n");
        } 

    return 0;
}