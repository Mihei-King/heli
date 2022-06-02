#include "mybase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count = 0;

Base* Constructor(Allihator* heli)
{
	Base* baza = malloc(sizeof(Base));
	baza->heli = heli;
	baza->ID = 1000000000 + count;
	count++;

	return baza;
}

void Get_Data_From_Console()
{
	char* name = (char*)malloc(1024 * sizeof(char));
	gets(name);

	int fuel = 0;
	scanf("%d", fuel);

	int hp = 0;
	scanf("%d", hp);

	int rockets = 0;
	scanf("%d", rockets);

	int bullets;
	scanf("%d", bullets);

	Allihator* heli = Constructor(name, fuel, hp, rockets, bullets);

	Base* baza = B_Constructor(heli);
}

void Get_Data_From_File()
{
	char* file = malloc(1024 * sizeof(int));
	FILE* F = fopen_s(&F, file, "r");

	char* name = malloc(1024 * sizeof(char));
	fgets(name, 1024, F);

	int fuel = 0;
	fscanf("%d", fuel);

	int hp = 0;
	fscanf("%d", hp);

	int rockets = 0;
	fscanf("%d", rockets);

	int bullets;
	fscanf("%d", bullets);

	Allihator* heli = Constructor(name, fuel, hp, rockets, bullets);

	Base* baza = B_Constructor(heli);
}

