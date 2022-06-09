#include<stdio.h>
#include<string.h>

int add_item()
{
    FILE* fp = fopen("grocerylist.csv", "a+");
    int itemno, qty, price;
    char itemname[50];
    if (!fp)
        //Error in opening file
        printf("Cannot open file");
        return 0;

    else
    {
        printf("Enter item number: ");
        scanf("%d", &itemno);
        printf("Enter item name: ");
        scanf("%s", &itemname);
        printf("Enter quantity: ");
        scanf("%d", &qty);
        printf("Enter price: ");
        scanf("%d", &price);
        fprintf(fp, "%d, %s, %d, %d\n", itemno, itemname, qty, price);
        printf("New item added successfully");
    }

    return 0;   
}
