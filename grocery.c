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
void remove_item()
{
	FILE* fp = fopen("grocerylist.csv", "r+");
	
	if (!fp)
	{
		//Error in opening file
		printf("Cannot open file");
		
	}
	else
	{	
		int count=0;
		char line[50];
		char itemno[20];
		char* val;
		printf("Enter item number to delete: ");
		scanf("%s",&itemno);
		while(fgets(line,50,fp)!=NULL)
		{
			val = strtok(line, ",");
			///printf("%s ",val);
		
		if (strcmp(val,itemno) == 0)
		{
			fprintf(fp, "%d,%s,%d,%d\n", NULL,NULL,NULL,NULL);
		}
	
		else
		{
		///printf("Item number does not exist");
		val = strtok(NULL, ",");
		}
		}
	}
	fclose(fp);
}	
void bill()
{
	FILE* fp = fopen("grocerylist.csv", "r");
	char choice='y';
	char current_name[100];
	int total_sum=0;
	int quantity;
		if (!fp)
		{
			//Error in opening file
			printf("Cannot open file");
			
		}
		else
		{
			char line[50];
							
					char *ch;
					char *ch2;
					int x=0;
					int sum=0;
			while (choice=='y')
			{				
				
					
					sum=0;
					
					printf("Enter Item number you want to purchase");
					char item_no[20];
					scanf(" %s",item_no);
					fseek(fp,0,SEEK_SET);
							while(fgets(line,50,fp)!=NULL)
							{
								
									ch=strtok(line,",");
									
									
												
										if (strcmp(item_no,ch)==0)
											{
												printf("Enter quantity:\n");
												
												scanf("%d",&quantity);
												ch2=strtok(NULL,",");
												strcpy(current_name,ch2);
												ch2=strtok(NULL,",");
												if (quantity<=(atoi(ch2)))
												{
													ch2=strtok(NULL,",");
													sum=sum+(quantity*(atoi(ch2)));
													
												}
												else
												{
													printf("Quantity not available.Would you like to place another order?y or n\n");
													scanf(" %c",&choice);
												}
													
													
											}
													
										else
											{
												ch=strtok(NULL,",");
												///printf("Item number doesn't exist.Would you like to place another order?y or n\n");
												///scanf("%c",&choice);
												
											}
										
							}

					total_sum=total_sum+sum;
					printf("current cost of %d %ss: %d\n",quantity,current_name,sum);
					printf("Would you like to place an order?y or n\n");
					scanf(" %c",&choice);
					
					
			}
			printf("total sum: %d",total_sum);
			}
		
	fclose(fp);
}
	
int edit_item()
{
	FILE *fp = fopen("grocerylist.csv", "a+");
	FILE *fp2=fopen("grocerylist2.csv","w+");
	
	int  qty, price,choice,count_lines;
	char itemno[20];
	char new_qty[20];
	char chr;
	if (!fp)
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
				scanf("%s",&new_qty);
				char line[50];
				char line2[500];
				
				char *ch;
				char *ch2;
				int x=0;
				while(fgets(line,1,fp)!=NULL)
				{
						ch=strtok(line,",");
						
						if (strcmp(itemno,ch)==0)
						{
							
							ch2=strtok(NULL,",");
							ch2=strtok(NULL,",");
							ch2=strtok(NULL,",");
							
							
							
						}
						else
						{
							fprintf(fp2,"%s",line);
							ch2=strtok(NULL,",");
						}
						
							
						
					
					
				
						
					
					
					
					///ch=strtok(NULL,",");
					///printf("%s",ch);
				}
				break;
				
				
				}
		}
				
				
								
	}
		
	fclose(fp);
	}
	
void search_item()
{
	FILE *fp=fopen("grocerylist.csv","r");
	if (!fp)
	{
		//Error in opening file
        printf("Cannot open file");
        
	}
	else
	{
		printf("Enter Item Number you want to search for");
		char item_no[20];
		scanf("%s",&item_no);
		char line[50];
				
				char *ch;
				char *ch2;
				int x=0;
				while(fgets(line,50,fp)!=NULL)
				{
					
						ch=strtok(line,",");
						
						
									
							if (strcmp(item_no,ch)==0)
								{
										
									ch2=strtok(NULL,",");
									printf("item:%s\t",ch2);
									ch2=strtok(NULL,",");
									printf("quantity:%s\t",ch2);
									ch2=strtok(NULL,",");
									printf("price:%s\t",ch2);
										
										
								}
										
										
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
			printf("4. Remove Items\n");
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
				case 4:
					remove_item();
			}
			break;
		
		case 2:
			printf("hello buyer");
			printf("1.View Item: ");
			printf("2.Search Item:");
			printf("3.Buy Items:");
			int y;
			scanf("%d",&y);
			switch(y)
			{
				case 1:
				view_items();
				break;
				case 2:
				search_item();
				case 3:
				bill();
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