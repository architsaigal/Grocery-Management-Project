#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int add_item()
{
    FILE* fp = fopen("grocerylist.csv", "a");
    int itemno, qty, price;
    char itemname[50];
    if (!fp)
	{
	//Error in opening file
        printf("Cannot open file");
        return 0;
	}

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
        fprintf(fp, "%d,%s,%d,%d\n", itemno, itemname, qty, price);
		fclose(fp);
        printf("New item added successfully");
    }
	
    return 0;   
}
int edit_item()
{
	FILE *fp1 = fopen("grocerylist.csv", "a+");
	int  qty, price,choice,count_lines;
	char itemno[20];
	int new_qty;
	char chr;
	if (!fp1)
	{
	//Error in opening file
        printf("Cannot open file");
        return 0;
	}
	else
	{
		printf("Enter item number: ");
		scanf("%s", &itemno);
		printf("Select 1 to change quantity or  2 to change price: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter the new quantity: ");
				scanf("%d",&new_qty);
				char line[50];
				
				char *ch;
				char *ch2;
				int x=0;
				while(fgets(line,50,fp1)!=NULL)
				{
					
						ch=strtok(line,",");
						
						if (strcmp(itemno,ch)==0)
						{
							printf("hi");
							ch2=strtok(NULL,",");
							ch2=strtok(NULL,",");
						}
						
					
					
				
						
					
					
					
					///ch=strtok(NULL,",");
					///printf("%s",ch);
				}
				break;
				
				
				}
		}
				
				
								
	}
		
	fclose(fp1);
	}
	

int view_items()
{

	FILE* fp = fopen("grocerylist.csv", "r");
	char str[50];
	if (fp == NULL)
		printf("Cannot open file\n");
	else 
	{
		while (fgets(str, 50, fp)) 
		{
			puts(str);
		}


		
	fclose(fp);
	return 0;
}
}
void passw_buyer(char []);
void usern_buyer(char id[])
{
	

	
		if (strcmp(id,"buyer")==0)
		{
				
                printf("Enter your password\n");
                char password[100];
                scanf("%s",password);
                passw_buyer(password);
            }
        else
		{
			printf("No such login id exists in the database.Please Re-Enter login id or enter 0 to go back to privilege selection page.\n");
			char c[100];
			scanf("%s",c);
			usern_buyer(c);
			
		}
}


void passw(char []);
void usern(char id[])
{
	

	
		if (strcmp(id,"admin")==0)
		{
				
                printf("Enter your password\n");
                char password[100];
                scanf("%s",password);
                passw(password);
            }
        else
		{
			printf("No such login id exists in the database.Please Re-Enter login id or enter 0 to go back to privilege selection page.\n");
			char c[100];
			scanf("%s",c);
			usern(c);
			
		}
}

void privilege(int a)
{
    
    if (a==1)
    {
        
        printf("Enter your username\n");
		char username[100];
		scanf("%s",username);
		usern(username);
	}
	else if (a==2)
	{
		printf("Enter your username\n");
		char username_buyer[100];
		scanf("%s",username_buyer);
		usern_buyer(username_buyer);
    }

}

void main()
{
    int priv;
    
    printf("Select 1 if you are an admin or 2 if you are a buyer\n");
    scanf("%d",&priv);
	privilege(priv);
	switch(priv)
	{
		case 1:
			printf("hello admin\n");
			printf("1. Add Item\n");
			printf("2. View items\n");
			printf("3. Edit Items\n");
			printf("Enter option\n");
			int x;
			scanf("%d",&x);
			switch(x)
			{
				case 1:
					add_item();
					break;
				case 2:
					view_items();
					break;
				case 3:
					edit_item();
					break;
			
			}
			break;
		
		case 2:
			printf("hello buyer");
			printf("1.View Item: ");
			int y;
			scanf("%d",&y);
			switch(y)
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
    if (strcmp(pass,"0")==0)
    {
        printf("Select 1 if you are an admin or 2 if you are a buyer\n");
        int b;
        scanf("%d",&b);
        privilege(b);

    }
    else if (strcmp(pass,"admin123")==0)
                {
                    printf("Access authorized!");
                }
				else
                {
                    printf("Access denied!Please Re-Enter your password or enter 0 to go back to the privilege selection page\n");
					char p[100];
					scanf("%s",p);
					passw(p);
					
                    

                }
}
void passw_buyer(char pass[100])
{
	
    if (strcmp(pass,"0")==0)
    {
        printf("Select 1 if you are an admin or 2 if you are a buyer\n");
        int b;
        scanf("%d",&b);
        privilege(b);

    }
    else if (strcmp(pass,"buyer123")==0)
                {
                    printf("Successfully logged in!");
                }
				else
                {
                    printf("Access denied!Please Re-Enter your password or enter 0 to go back to the privilege selection page\n");
					char p[100];
					scanf("%s",p);
					passw_buyer(p);
					
                    

                }

}