#include <stdio.h>
#include <string.h>
#include "functions.h"

int sort_letters(char *str_array)
{
	int i, j;
	char temp;
	int stringLength = strlen(str_array);
	for (i = 0; i < stringLength - 1; i++)
	{
		for (j = i + 1; j < stringLength; j++)
		{
			if (str_array[i] > str_array[j])
			{
				temp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = temp;
			}
		}
	}
	printf("%s ", str_array);
	return 1;
}
