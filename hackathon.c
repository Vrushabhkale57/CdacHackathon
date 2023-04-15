#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 

typedef struct quote{
	
	char author[20];
	char quote[100];
}quote_t;

void accept_quote(quote_t *aq);
void display_quote(quote_t *dq);

void new_quote();
void all_quote();
int main(void)
{
	quote_t q;
	int ch1;
	do{
		
	printf("\n0.Sign Out\n1.All Quotes\n2.My Quotes\n3.My Favorite Quotes\n4.Like/Unlike Quotes\n5.New Quote\n6.New Quote\n7.Delete Quote\n8.Change Password\n9.New Profile\n");
	printf("\nEnter Choice=");
	scanf("%d",&ch1);
		switch(ch1)
			{
				case 0:printf("===Sign out===\n");
					   break;
				case 1:printf("===All Quotes===\n");
						all_quote();		
					   break;
				case 2:printf("===My Quotes===\n");
				       break;
				case 3:printf("===My Favorite Quote===\n");
				       break;
				case 4:printf("===Like/Unlike Quote===\n");
				       break;
				case 5:printf("===New Quote===\n");
						new_quote(&q);
				       break;
				case 6:printf("===Edit Quote===\n");
				       break;
				case 7:printf("===Delete Quote===\n"); 
				       break;
				case 8:printf("===Change Password===\n");
				       break;
				case 9:printf("===Edit Profile===\n");
				       break;
				default:printf("===Invalid Choice===\n");
				       break;
			}
	}while(ch1!=0);
	return 0;
}
void accept_quote(quote_t *aq)
{
	printf("\nEnter Author=");
	scanf("%*c%[^\n]s",aq->author);
	printf("\n Enter Quote=");
	scanf("%*c%[^\n]s",aq->quote);
}

void display_quote(quote_t *dq)
{
	int quoteno=1;
	printf("%-2d",quoteno++);
	printf("\nAuthor=%s   Quote=%s",dq->author,dq->quote);
}

void new_quote()
{
	int cnt;
	quote_t q;
	FILE *fp=fopen("quote.db","ab");
	if(fp==NULL)
	{
		perror("Failed to open quote file\n");
		exit(1);
	}
	accept_quote(&q);
	cnt=fwrite(&q,sizeof(quote_t),1,fp);
	fclose(fp);
}

void all_quote()
{
	int cnt,quoteno=1;
	quote_t q;
	FILE *fp=fopen("quote.db","rb");
	if(fp==NULL)
	{
		perror("Failed to open quote file\n");
		exit(1);
	}
	while(fread(&q,sizeof(quote_t),1,fp)>0)
			display_quote(&q);
	fclose(fp);	
}


