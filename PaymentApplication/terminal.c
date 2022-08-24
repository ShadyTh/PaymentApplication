#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	uint8_t local_transactionDate[11];
	uint8_t i;

	printf("Please enter transaction data\n");
	printf("Transaction Data format should be: \"DD/MM/YYYY\" ,e.g 25/06/2022\n");

	scanf_s("%s", local_transactionDate, (unsigned)_countof(local_transactionDate));

	if (local_transactionDate[0] == '\0')
		return WRONG_DATE;

	if (strlen(local_transactionDate) < 10)
		return WRONG_DATE;

	for (i = 0; i < (unsigned)_countof(local_transactionDate); i++)
	{
		// check slash characters
		if (i == 2 || i == 5)
		{
			if (local_transactionDate[i] != '/')
				return	WRONG_DATE;
		}
		// check all others are numbers
		else
		{
			if ((local_transactionDate[i] >= '0') && (local_transactionDate[i] <= '9'))
			{

			}
		}

	}
}