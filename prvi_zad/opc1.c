#include<stdio.h>
#include<string.h>
#include "functions.h"

int all_caps (char *str_array)
{
	for (int i =0; str_array[i] != '\0'; i++)
	{	
		if(str_array[i] >= 'a' && str_array[i] <= 'z'){	
		str_array[i] = str_array[i] -32 ;
		}
	}
	printf("%s", str_array);
	return 0;
}
