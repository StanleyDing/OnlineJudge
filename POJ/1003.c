#include<stdio.h>
float table[280] = {0};

int get(float);

int main()
{
	int i;
	float c;
	scanf("%f", &c);

	table[0] = 0.5;
	for(i = 1; i < 280; i++)
		table[i] = table[i-1] + (1.0/(i+2));

	while(c != 0.0)
	{
		for(i = 0; c > table[i] && i < 280; i++);
		scanf("%f", &c);
			printf("%d card(s)\n", i + 1);	
	}
printf("\n\n\n\n\n");
	return 0;
}