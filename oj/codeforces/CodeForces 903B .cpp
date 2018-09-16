#include <stdio.h>
int main()
{
	int h1,a1,c,h2,a2;
	while(~scanf("%d%d%d%d%d",&h1,&a1,&c,&h2,&a2))
	{
		int att = h2 / a1;
		if(h2 % a1 != 0)
            att++;
		int fall = a2 * (att - 1);
		int heal = 0;
		while(heal * c + h1 <= fall)
		{
			fall = fall+a2;
			heal++;
		}
		printf("%d\n",heal + att);
		while(heal--)
		printf("HEAL\n");
		while(att--)
		printf("STRIKE\n");
	}
	return 0;
}
