// app
// .c
//

#include "app.h"

int main()
{
	EN_cardError_t x;
	ST_terminalData_t y;
	x = getTransactionDate(&y);
	printf("%d\n", x);	// 1 is WRONG_DATE, 0 is TERMINAL_OK
	printf("%s\n", y.transactionDate);

	return 0;
}
