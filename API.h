#ifndef _API_H_
#define _API_H_

#include "std.h"

#define MAX_CHARACTERS 	20

#define MAX_ACCOUNTS 	3

#define ZERO 	0

typedef enum 
{
	TRUE=0,
	FALSE=1
}return_status_t;

typedef struct
{
	uint32_t id;
	uint32_t password;
	uint32_t cash_amount;
}account_t;

return_status_t loginToSystem(void);
void PrintBalance(uint32_t accountID);
void Deposit(uint32_t accountID,uint32_t cash_amount);
void Transfer(uint32_t accountID_1);
return_status_t withdraw(uint32_t accountID,uint32_t cash_amount);

#endif