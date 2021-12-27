#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
	int opcija;
	ucitaj_podatke();
	do
	{
		printf("\nIzaberite opcije od 1 do 5 za rad sa fudbalskom tablicom\n");
		printf("Opcaija 1 je unos tima u tabelu\n");
		printf("Opcija 2 je pretraga klubova u tabeli po parametrima\n");
		printf("Opcija 3 je ispis trenutnog stanja na tabeli\n");
		printf("Opcija 4 je korigovanje parametarakluba\n");
		printf("Opcija 5 je izlaz iz programa\n");
		printf("Izabrali ste opciju: ");
		scanf("%d", &opcija);

		switch (opcija)
		{
			case 1:
			unos();
			break;
			case 2:
			pretraga();
			break;
			case 3:
			prikaziTabelu();
			break;
			case 4:
			igrajMec();
			break;
			case 5:
			izlaz();
			break;
			default:
				printf("pogresan izbor\n");
				break;
		}
	}while(opcija > 0 && opcija < 6);
}

static struct tim {
	char ime[20];
	int odigrane_utakmice;
	int broj_golova;
	int broj_prgolova;
	int broj_bodova;
};

FILE *my_stream;
FILE *read_stream;
struct tim tabela[30];

int dodaj_ekipu(struct tim upis)
{
	for (int i = 0; i < sizeof(tabela)/sizeof(struct tim); i++)
	{
		if (strlen(tabela[i].ime) == 0)
		{
			tabela[i] = upis;
			return 0;
		}
	}
	printf("Maksimalan broj ekipa  je dostignut, nije moguce dodati!");
}

void ucitaj_podatke(){
	my_stream = fopen("tabela", "r");
	if (my_stream)
	{
		fread(tabela, sizeof(struct tim), 30, my_stream);
		fclose(my_stream);
	}
}

void sacuvaj_podatke()
{
	my_stream = fopen("tabela", "w");
	fwrite(tabela, sizeof(struct tim), 30, my_stream);
	fclose(my_stream);
}


void unos ()
{
	struct tim novi_tim;
	printf("unesi ime kluba: ");
	scanf("%s", novi_tim.ime);
	novi_tim.odigrane_utakmice=0;
	novi_tim.broj_golova=0;
	novi_tim.broj_prgolova=0;
	novi_tim.broj_bodova=0;
	dodaj_ekipu(novi_tim);
	printf("\ntim\t\tos\t\tG\t\tB\n");

	for (int i = 0; i < sizeof(tabela)/sizeof(struct tim) ; i++)
	{
		if (strlen(tabela[i].ime) == 0){
		   break;
		}
		printf("\n%-10s\t%-10d\t%d:%-10d\t%d", tabela[i].ime, tabela[i].odigrane_utakmice, tabela[i].broj_golova, tabela[i].broj_prgolova, tabela[i].broj_bodova);
		
	}

}


void pretraga()
{
	printf("Unesite podesavanje pretrage:\n");
	printf("x, < ili x, >\n");
	char unos[3];
	scanf("%s", unos);
	for(int i = 0; i<30; i++)
	{
		if(strlen(tabela[i].ime) == 0)
			break;
		if (unos[2] == '<')
		{
			if ((char)tabela[i].broj_bodova > unos[0])
			{
				continue;
			}
		}
		else if (unos[2] == '>')
		{
			if ((char)tabela[i].broj_bodova < unos[0])
			{
				continue;
			}
		}
		else
		{
			break;
		}
		printf("\n%s", tabela[i].ime);
	}
}

int izracunajRazlikuGolova(struct tim ekipa)
{
	return ekipa.broj_golova - ekipa.broj_prgolova;
}

void sortiraj(struct tim *tabela)
{
	int i, j;
	struct tim temp;
	for (i = 0; i < 30 - 1; i++)
	{
		if(strlen(tabela[i].ime) == 0)
			break;
		for (j = i + 1; j < 30; j++)
		{
			if(strlen(tabela[i].ime) == 0)
			break;

			if(tabela[i].broj_bodova < tabela[j].broj_bodova || (tabela[i].broj_bodova == tabela[j].broj_bodova && izracunajRazlikuGolova(tabela[i]) > izracunajRazlikuGolova(tabela[j])))
			{
				temp = tabela[i];
				tabela[j] = tabela[i];
				tabela[j] = temp;
			}
		}
	}
}

void prikaziTabelu()
{
	struct tim tabelaCopy[30];
	struct tim *pointer = tabelaCopy;
	for (int i = 0; i < 30; i++)
	{
		tabelaCopy[i] = tabela[i];
	}
	sortiraj(pointer);
	printf("\ntim\t\tos\t\tG\t\tB");

	for(int i = 0; i < sizeof(tabela)/sizeof(struct tim); i++)
	{
		if(strlen(tabelaCopy[i].ime) == 0){
			break;
		}
		printf("\n%-10s\t%-10d\t%d:%-10d\t%d", tabelaCopy[i].ime,tabelaCopy[i].odigrane_utakmice, tabelaCopy[i].broj_golova, tabelaCopy[i].broj_prgolova, tabelaCopy[i].broj_bodova);
	}
}


struct tim *pronadji_klub(char naziv[30])
{
	for (int i = 0; i < sizeof(tabela) / sizeof(struct tim); i++)
	{
		if (strcmp(tabela[i].ime, naziv) == 0)
		{
			return &tabela[i];
		}
	}
}

void igrajMec()
{
	char domacin[30];
	char gost[30];
	char rezultat[30];
	printf("\nUnesi domaci tim:\n");
	scanf("%s", domacin);
	printf("Unesi gostojuci tim:\n");
	scanf("%s", gost);
	printf("Unesi rezultat:\n");
	scanf("%s", rezultat);

	struct tim *domacinStruct = pronadji_klub(domacin);
	struct tim *gostStruct = pronadji_klub(gost);

	domacinStruct->broj_golova += rezultat[0] - '0';
	domacinStruct->broj_prgolova += rezultat[2] - '0';
	domacinStruct->odigrane_utakmice++;
	gostStruct->broj_prgolova += rezultat[0] - '0';
	gostStruct->broj_golova += rezultat[2] - '0';
	gostStruct->odigrane_utakmice++;

	if (rezultat[0] > rezultat[2])
	{
		domacinStruct->broj_bodova += 3;
	}
	else if (rezultat[0] == rezultat[2])
	{
		domacinStruct->broj_bodova += 1;
		gostStruct->broj_bodova += 1;
	}
	else
	{
		gostStruct->broj_bodova += 3;
	}
}


void izlaz()
{
	sacuvaj_podatke();
	printf("KRAJ");
	exit(1);
}




