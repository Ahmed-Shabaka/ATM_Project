#include "API.h"
account_t arr[MAX_ACCOUNTS]={ {11,111,1000} ,
							  {22,222,2000} ,
							  {33,333,3000} };
uint32_t accountID=0;
/*####################################################*/
return_status_t loginToSystem(void)
{
	return_status_t ret=FALSE;
	uint32_t password=0;
	uint32_t counter=0;
	
	printf("Enter ID : ");
	scanf("%i",&accountID);
	
	printf("Enter PASSWORd : ");
	scanf("%d",&password);
	
	for(counter=0;counter<MAX_ACCOUNTS;counter++)
	{
		if( (accountID==arr[counter].id) && (password==arr[counter].password) )
		{
			ret=TRUE;
			printf("Successfully Logged in \n");
			printf("****************************************\n");
			break;
		}
		else
		{
			ret=FALSE;
		}
	}
	
	return ret;
}
/*####################################################*/
void PrintBalance(uint32_t accountID)
{
	uint32_t counter=0;
	
	while(arr[counter].id!=accountID)
	{
		counter++;
	}
	printf("Cash amount in your Bank Account = %i \n",arr[counter].cash_amount);
	printf("****************************************\n");
}
/*####################################################*/
void Deposit(uint32_t accountID,uint32_t cash_amount)
{
	uint32_t counter=0;
	
	while(arr[counter].id!=accountID)
	{
		counter++;
	}
	arr[counter].cash_amount+=cash_amount;
	printf("Operation Done Successfully \n");
	printf("****************************************\n");
}
/*####################################################*/
void Transfer(uint32_t accountID_1)
{
	uint32_t accountID_2=0;
	uint32_t cash_amount=0;
	uint32_t id1_index=0;
	uint32_t id2_index=0;
	uint8_t flag=0;
	
	
	while(arr[id1_index].id!=accountID)
	{
		id1_index++;
	}
	/*******************/
	printf("Please Enter The Second account ID : ");
	scanf("%i",&accountID_2);
	
	while(id2_index<MAX_ACCOUNTS)
	{
		if(arr[id2_index].id==accountID_2)
		{
			flag=1;
			break;
		}
		else
		{
			id2_index++;
		}
	}
	
	if( (id1_index==id2_index) || (0==flag) )
	{
		printf("ID is Invalid! \n");
	}
	else
	{
		printf("Please Enter Cash amount : ");
		scanf("%i",&cash_amount);
		
		if(arr[id1_index].cash_amount<cash_amount)
		{
			printf("Cash amount in your Bank Account isn't enough!\n");
		}
		else
		{
			arr[id1_index].cash_amount-=cash_amount;
			arr[id2_index].cash_amount+=cash_amount;
			printf("Operation Done Successfully \n");
		}
	}
	printf("****************************************\n");
	
}
/*####################################################*/
return_status_t withdraw(uint32_t accountID,uint32_t cash_amount)
{
	return_status_t ret=FALSE;	
	uint32_t counter=0;
	
	while(arr[counter].id!=accountID)
	{
		counter++;
	}
	
	if(arr[counter].cash_amount<cash_amount)
	{
		ret=FALSE;
		printf("Cash amount in your Bank Account isn't enough!\n");
	}
	else
	{
		ret=TRUE;
		arr[counter].cash_amount-=cash_amount;
		printf("Operation Done Successfully \n");
	}
	printf("****************************************\n");
	
	return ret;
}
/*####################################################*/















