#include <stdio.h>

int acounter(void)
{
	char c;
	scanf("%c", &c);
	if (c == '.')
		return 0;
	return (c == 'a') + acounter();
}


int main()
{
	int c = acounter();
	printf("%d", c);
	return 0;
}

