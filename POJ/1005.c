#include<stdio.h>
#include<math.h>

int main()
{
	int property = 1, area, maxData, i;
	double x, y;

	scanf("%d", &maxData);
	
	for(i = 0; i < maxData; i++)
	{
		scanf("%lf %lf", &x, &y);
		area = (pow(x, 2) + pow(y, 2))*3.1415926/2;
		printf("Property %d: This property will begin eroding in year %d.\n", i + 1, (int)(area/50)+1);
	}
	printf("END OF OUTPUT.");
	return 0;
}