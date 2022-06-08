#include<stdio.h>
#include<string.h>
void main()
{
    int priv;
    char id[100],password[100];
    printf("Select 1 if you are an admin or 2 if you are a buyer");
    scanf("%d",&priv);
    if (priv==1)
    {
        printf("Enter your username:");
        scanf("%s",&id);
        if (strcmp((id,"admin")==1)
            {
                printf("HI ARCHIT");

    }
}

int add_item()
{
    FILE* fp = fopen("grocerylist.csv", "w");
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
