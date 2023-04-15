#include<stdio.h>
int main(void)
{
	int ch1;
	printf("\n0.Sign Out\n1.All Quotes\n2.My Quotes\n3.My Favorite Quotes\n4.Like/Unlike Quotes\n5.New Quote\n6.New Quote\n7.Delete Quote\n8.Change Password\n9.New Profile\n");
	printf("\nEnter Choice=");
	scanf("%d",&ch1);
	do{
		switch(ch1)
			{
				case 0:printf("\nSign out");
					   break;
				case 1:printf("\nAll Quotes");
					   break;
				case 2:printf("\nMy Quotes");
				       break;
				case 3:printf("\nMy Favorite Quote");
				       break;
				case 4:printf("\nLike/Unlike Quote");
				       break;
				case 5:printf("\nNew Quote");
				       break;
				case 6:printf("\nEdit Quote");
				       break;
				case 7:printf("\nDelete Quote"); 
				       break;
				case 8:printf("\nChange Password");
				       break;
				case 9:printf("\nEdit Profile");
				       break;
				default:printf("\nInvalid Choice");
				       break;
			}
	}while(ch1!=0);
	return 0;
}
