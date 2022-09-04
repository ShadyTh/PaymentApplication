#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	uint8_t local_transactionDate[11];
	uint8_t i, month, day;

	printf("Please enter transaction data\n");
	printf("Transaction Data format should be: \"DD/MM/YYYY\" ,e.g 25/06/2022\n");

	scanf_s("%s", local_transactionDate, (unsigned)_countof(local_transactionDate));

	if (local_transactionDate[0] == '\0')
		return WRONG_DATE;

	if (strlen(local_transactionDate) != 10)
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
			if (!((local_transactionDate[i] >= '0') && (local_transactionDate[i] <= '9')))
			{
				return WRONG_DATE;
			}
		}
	}
	// check MM is a real month number
	// calculate month from ascii to decimal
	month = ((local_transactionDate[3] - 48) * 10) + (local_transactionDate[4] - 48);
	if ((month <= 0) || (month > 12))
		return WRONG_EXP_DATE;

	// check DD is a real day number
	// calculate month from ascii to decimal
	day = ((local_transactionDate[0] - 48) * 10) + (local_transactionDate[1] - 48);
	if ((day <= 0) || (day > 31))
		return WRONG_EXP_DATE;

	// if all checks pass, return OK
	strcpy_s(termData->transactionDate, 10, local_transactionDate);
	return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	// cardData expiry date format: MM/YY 
	// termData transaction date format: DD/MM/YYYY

	// variables to store month and year in decimal (instead of string)
	uint8_t transaction_M, transaction_Y, expiry_M, expiry_Y, transaction_Total, expiry_Total;
	transaction_M = ((termData->transactionDate[3] - 48) * 10) + (termData->transactionDate[4] - 48);
	transaction_Y = ((termData->transactionDate[8] - 48) * 10) + (termData->transactionDate[9] - 48);
	expiry_M = ((cardData->cardExpirationDate[0] - 48) * 10) + (cardData->cardExpirationDate[1] - 48);
	expiry_Y = ((cardData->cardExpirationDate[3] - 48) * 10) + (cardData->cardExpirationDate[4] - 48);

	// convert years to months and add to total
	transaction_Total = transaction_M + (transaction_Y * 12);
	expiry_Total = expiry_M + (expiry_Y * 12);

	// compare dates
	if (expiry_Total > transaction_Total)
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	float local_TransactionAmount = 0;

	printf("Please enter transaction amount\n");
	scanf_s("%f", &local_TransactionAmount);

	if (local_TransactionAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		termData->transAmount = local_TransactionAmount;
		return TERMINAL_OK;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	float local_MaxAmount = 0;

	printf("Please enter terminal maximum allowed amount\n");
	scanf_s("%f", &local_MaxAmount);

	if (local_MaxAmount <= 0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}