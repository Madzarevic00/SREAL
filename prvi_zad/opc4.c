#include <stdio.h>
#include <string.h>
#include "functions.h"

int palindrom (char *std_array)
{
	int i, length;
	int flag = 0;
	length = strlen(std_array);
	for (i = 0; i < length; i++)
	{
		if (std_array[i] != std_array[length - 1 - i])
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		printf("%s nije palindrom", std_array);
	}
	else
	{
		printf("%s jeste palindrom", std_array);
	}
	return 0;
}
