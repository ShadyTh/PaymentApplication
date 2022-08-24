// app
// .c
//

#include "app.h"

int main()
{
	EN_cardError_t x;
	ST_cardData_t y;
	x = getCardHolderName(&y);
	printf("%d\n", x);
	printf("%s\n", y.cardHolderName);

	return 0;
}
