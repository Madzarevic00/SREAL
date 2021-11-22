#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "functions.h"

int main(int argc, char **argv)
{
	int opcija = atoi(argv[argc - 1]);
	for(int i = 1; i < argc -1; i++)
	{
		if (opcija == 1)
		{
			all_caps(argv[i]);
		}
		else if (opcija == 2)
		{
			sort_letters(argv[i]);
		}
		else if  (opcija == 3)
		{
			no_numbers(argv[i]);
		}
		else if (opcija == 4)
		{
			palindrom(argv[i]);
			printf("\n");
		}
	}
}
