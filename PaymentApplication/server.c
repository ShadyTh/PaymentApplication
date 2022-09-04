//
// server.c
//

#include "server.h"

// Initialize Accounts Database
 ST_accountsDB_t ArrayDatabase[255] =
{
	{ 2000.0,	RUNNING, "8989374615436851" },
	{ 100000.0,	BLOCKED, "5807007076043875" },
	{ 500.0,	RUNNING, "1231231231231231" },
	{ 2500.0,	RUNNING, "8785898785898785" },
	{ 12500.0,	RUNNING, "4567891324569872" },
	{ 878984.0,	BLOCKED, "1213141516171819" },
	{ 750005.0,	RUNNING, "9999999999999999" },
	{ 125.0,	BLOCKED, "1111111999999999" },
	{ 4000.0,	RUNNING, "7519391357913579" },
	{ 35000.0,	RUNNING, "2486068420268408" },
};

// Initialize Transaction Database
 ST_transaction_t TransState[255] = { 0 };


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{

}