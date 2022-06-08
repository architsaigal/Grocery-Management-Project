#include<stdio.h>
#include<string.h>

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
        
        printf("Enter your username");
		char username[100];
		scanf("%s",username);
		usern(username);
	}
	if (a==2)
	{
		printf("Welcome Dear Customer!");
    }

}


void main()
{
    int priv;
    
    printf("Select 1 if you are an admin or 2 if you are a buyer\n");
    scanf("%d",&priv);
    privilege(priv);
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
