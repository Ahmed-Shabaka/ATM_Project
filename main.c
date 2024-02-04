#include "API.h"

extern uint32_t accountID;

int main()
{
	uint8_t choice=0;
	uint32_t cash_amount=0;
	return_status_t log_retVAL=FALSE,ret=FALSE;	
	
	
	printf("\n\t	<<< ATM Login >>> \n\n");
	label :
	printf("1)Login\n0)Exit\n");
	printf("****************************************\n");
	scanf("%d",&choice);
	
	if(0==choice)	return ZERO;
	else if (1==choice)		log_retVAL=loginToSystem();
	else
	{
		printf("Invalid! \n");
		printf("****************************************\n");
		goto label;
	}		

	if(log_retVAL==TRUE)
	{
		while(1)
		{
			printf("1)Print Balance \n");
			printf("2)Deposit \n");
			printf("3)Transfer \n");
			printf("4)WithDraw \n");
			printf("0)Exit \n");
			printf("****************************************\n");
			fflush(stdin);
			scanf("%d",&choice);
			switch(choice)
			{
				case 1 :
				
				PrintBalance(accountID);
				break;
				
				case 2 : 
				
				printf("Please Enter Cash amount : ");
				scanf("%i",&cash_amount);
				Deposit(accountID,cash_amount);
				break;
				
				case 3 : 
				
				Transfer(accountID);
				break;
				
				case 4 : 
				
				printf("Please Enter Cash amount : ");
				scanf("%i",&cash_amount);
				ret= withdraw(accountID,cash_amount);
				break;
				
				case 0 : 
				
				goto label;
				break;
				
				default : 
				
				printf("Invalid Value! \n");
				printf("****************************************\n");
				break;
			}
		}
	}
	else if(log_retVAL==FALSE)
	{
		printf("Wrong ID or PASSWORD ! \n");
		printf("****************************************\n");
		goto label;
	}
	return ZERO;
}