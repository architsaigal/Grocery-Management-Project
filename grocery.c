#include<stdio.h>
#include<string.h>

struct item
{
	int itemno, qty, price;
	char itemname[50];
};

int add_item()
{
	FILE* fp = fopen("grocerylist.csv", "a");
	struct item access_item;
	if (!fp)
	{
		//Error in opening file
		printf("Cannot open file");
		return 0;
	}

	else
	{
		printf("Enter item number: ");
		scanf("%d", &access_item.itemno);
		printf("Enter item name: ");
		scanf("%s", &access_item.itemname);
		printf("Enter quantity: ");
		scanf("%d", &access_item.qty);
		printf("Enter price: ");
		scanf("%d", &access_item.price);
		fprintf(fp, "%d,%s,%d,%d\n", access_item.itemno, access_item.itemname, access_item.qty, access_item.price);
		fclose(fp);
		printf("New item added successfully");
	}

	return 0;
}
int edit_item()
{
	FILE* fp = fopen("grocerylist.csv", "a");
	struct item access_item;
	int new_qty,choice,count_lines;
	char line[50],chr;
	if (!fp)
	{
		//Error in opening file
		printf("Cannot open file");
		return 0;
	}
	else
	{
		printf("Enter item number: ");
		scanf("%d", &access_item.itemno);
		printf("Select 1 to change quantity or  2 to change price: ");
		scanf("%d", &choice);
		//printf("%d",fp[5][0]);
		switch (choice)
		{
		case 1:

			printf("Enter the new quantity: ");
			scanf("%d", &new_qty);
			chr = getc(fp);
			while (chr != EOF)
			{
				if (chr == '\n')
				{
					count_lines = count_lines + 1;
				}
				chr = getc(fp);
			}
			printf("no of rows \n %d", count_lines);
			break;

		}


	}
	fclose(fp);
}

int view_items()
{
	FILE* fp = fopen("grocerylist.csv", "r");
	char str[50];
	if (fp == NULL)
		printf("Cannot open file\n");
	else {
		while (fgets(str, 50, fp)) {
			puts(str);
		}

		}
	fclose(fp);
	return 0;
}

void passw(char[]);
void usern(char id[])
{



	if (strcmp(id, "admin") == 0)
	{

		printf("Enter your password\n");
		char password[100];
		scanf("%s", password);
		passw(password);
	}
	else
	{
		printf("No such login id exists in the database.Please Re-Enter login id or enter 0 to go back to privilege selection page.\n");
		char c[100];
		scanf("%s", c);
		usern(c);

	}
}


void privilege(int a)
{

	if (a == 1)
	{

		printf("Enter your username\n");
		char username[100];
		scanf("%s", username);
		usern(username);
	}
	if (a == 2)
	{
		printf("Welcome Dear Customer!\n");
	}

}


void main()
{
	int priv;

	printf("Select 1 if you are an admin or 2 if you are a buyer\n");
	scanf("%d", &priv);
	privilege(priv);
	switch (priv)
	{
	case 1:
		printf("Hello Admin\n");
		printf("1. Add Item\n");
		printf("2. Edit Item\n");
		printf("Enter option\n");
		int x;
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			add_item();
			break;
		case 2:
			edit_item();
			break;

		}
		break;

	case 2:
		printf("Hello Buyer\n");
		printf("1. View All Items\n");
		int y;
		scanf("%d", &y);
		switch (y)
		{
		case 1:
			view_items();
			break;
		}
		break;
	}


}

void passw(char pass[100])
{


	if (strcmp(pass, "0") == 0)
	{
		printf("Select 1 if you are an admin or 2 if you are a buyer\n");
		int b;
		scanf("%d", &b);
		privilege(b);

	}
	else if (strcmp(pass, "admin123") == 0)
	{
		printf("Access authorized!");
	}
	else
	{
		printf("Access denied!Please Re-Enter your password or enter 0 to go back to the privilege selection page\n");
		char p[100];
		scanf("%s", p);
		passw(p);
	}
}
