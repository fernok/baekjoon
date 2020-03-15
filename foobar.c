#include <stdio.h>

int main(void)
{
	FILE *fp;
	fp = fopen("foobar.txt", "w");

	const char *foo = "Hello";
	const char *bar = "World!";
	fprintf(fp, "%s %s\n", foo, bar);

	fclose(fp);

	return 0;
}
