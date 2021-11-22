#include<stdio.h>
#include "functions.h"

int no_numbers (char *str_array)
{
	int i, j;
	for (i = 0; str_array[i] != '\0'; i++)
	{
		while (str_array[i] >= '0' && str_array[i] <= '9')
		{
			for (j = i; str_array[j] != '\0'; j++)
			{
				str_array[j] = str_array[j + 1];
			}
		}
	}
	printf("%s", str_array);
	return 1;

}
