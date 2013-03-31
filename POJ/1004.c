//Financial Management
#include<stdio.h>

int main()
{
	int month = 1;
	double money, total = 0;
	while(scanf("%lf", &money) != EOF)
	{
		total += money;
	}

	printf("$%.2f", total / 12);
}