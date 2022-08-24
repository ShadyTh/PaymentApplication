// card.c

#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t local_CardHolderName[25];	//variable to store user input and do prechecks before storing it in structure
	uint8_t name_length = 0;			// to loop and find string length

	printf("\nPlease enter Card Holder Name:\n");
	printf("(The name should be 20 characters minimum and 24 characters maximum)\n");

	fgets(local_CardHolderName, (unsigned)_countof(local_CardHolderName), stdin);
	// commented scanf_s as it does not accept spaces without complicating the format specifier
	// scanf_s("%s", local_CardHolderName, (unsigned)_countof(local_CardHolderName));

	if (local_CardHolderName[0] == '\0')	// if name is NULL, return error
	{
		return WRONG_NAME;
	}

	// loop to get string length
	while (local_CardHolderName[name_length] != '\0')
	{
		name_length++;
	}
	
	if ((name_length >= 20) && (name_length <= 24))
	{
		strcpy_s(cardData->cardHolderName, 25,local_CardHolderName);
		return CARD_OK;
	}
	else
	{
		return WRONG_NAME;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t local_ExpiryDate[6];
	uint8_t string_length = 0;
	uint8_t	i = 0;

	printf("\nPlease enter Card Expiry Date:\n");
	printf("(Should be in the following format: \"MM/YY\" )\n");
	scanf_s("%s", local_ExpiryDate, (unsigned)_countof(local_ExpiryDate));

	if (local_ExpiryDate[0] == '\0')	// if string is empty, return error
	{
		return WRONG_EXP_DATE;
	}

	// loop to get string length
	while (local_ExpiryDate[string_length] != '\0')
	{
		string_length++;
	}
	// if length not equal to 5, throw error
	if (string_length != 5)
	{
		return	WRONG_EXP_DATE;
	}

	// loop to check format
	for (i; i < 5; i++)
	{
		// check that third character is slash
		if (i == 2)
		{
			if (local_ExpiryDate[i] != '/')
			{
				return WRONG_EXP_DATE;
			}
		}
		// check that other characters are numbers
		else
		{
			if (!((local_ExpiryDate[i] >= '0') && (local_ExpiryDate[i] <= '9')))
			{
				return WRONG_EXP_DATE;
			}
		}
	}
	// check MM is a real month number
	if ((local_ExpiryDate[0] != '0') && (local_ExpiryDate[0] != '1'))
		return WRONG_EXP_DATE;

	strcpy_s(cardData->cardExpirationDate, 6,local_ExpiryDate);
	return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t local_PAN[20];
	uint8_t string_length = 0;

	printf("Please enter your Primary Account Number (PAN)\n");
	printf("(It should be between 16 and 19 characters long)\n");

	scanf_s("%s", local_PAN, (unsigned)_countof(local_PAN));

	if (local_PAN[0] == '\0')
	{
		return WRONG_PAN;
	}

	while (local_PAN[string_length] != '\0')
	{
		string_length++;
	}

	if ((string_length >= 16) && (string_length <= 19))
	{
		strcpy_s(cardData->primaryAccountNumber,20, local_PAN);
		return CARD_OK;
	}

	return WRONG_PAN;
}