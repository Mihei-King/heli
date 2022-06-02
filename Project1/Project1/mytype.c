#include "mytype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct KA_52_Allihator Allihator;

Allihator* Constructor(char* name, int fuel, int hp, int rockets, int bullets)
{
	Allihator* heli = malloc(sizeof(Allihator));
	if (!heli)
		return NULL;
	
	if (fuel > 1487)
		heli->fuel = 1487;
	else
		heli->fuel = fuel;

	if (hp > 300)
		heli->hp = 300;
	else
		heli->hp = hp;

	if (bullets > 960)
		heli->bullets = 960;
	else
		heli->bullets = bullets;

	if (rockets > 128)
		heli->rockets = 128;
	else
		heli->rockets = rockets;

	int len = strlen(name);
	heli->name = malloc(len * sizeof(char*));
	if (!heli->name)
	{
		perror("ERROR: NO NAME");
		free(heli);
		return NULL;
	}

	int i = 0;

	for (; i < len; i++)
		heli->name[i] = name[i];

	heli->name[i] = '\0';

	return heli;
}

void Attack_Enemy(Allihator heli)
{
	srand(time(NULL));

	int strikes = rand() % 100;
	heli.bullets -= strikes;
	
	printf("You are destroy %d enemies.\n", rand() % strikes);

	if (heli.bullets <= 0)
	{
		heli.bullets = 0;
		printf("Out of ammo. Need to reload.\n");
	}

	heli.fuel -= rand() % 10;
	if (heli.fuel <= 0)
	{
		heli.fuel = 0;
		printf("Out of fuel. Need to refuel.\n");
	}
}

void Destroy_Enemy_Base(Allihator heli)
{
	srand(time(NULL));
	heli.rockets -= rand() % 10;

	int Bool = rand() % 2;

	if (Bool == 1)
		printf("You succesfuly destroy base.\n");
	else
		printf("You don't destroy base.\n");

	if (heli.rockets <= 0)
	{
		heli.rockets = 0;
		printf("Out of ammo. Need to reload.\n");
	}

	heli.fuel -= rand() % 100;
	if (heli.fuel <= 0)
	{
		heli.fuel = 0;
		printf("Out of fuel. Need to refuel.\n");
	}
}

void Refuel(Allihator heli)
{
	heli.fuel = 1487;
	printf("Fuel is full.\n");
}

void Load(Allihator heli)
{
	heli.rockets = 128;
	heli.bullets = 960;
	printf("Ammo is full.\n");
}

void Airbattle(Allihator heli)
{
	srand(time(NULL));
	printf("You see the old Mi-2. Let's annihilate it.\n");

	Allihator* OG_Mi_2 = Constructor("O_Mi", 200, 190, 16, 120);

	while (heli.hp > 0 && OG_Mi_2->hp > 0)
	{
		printf("Would you like to do. Print '1' to attack. Print '0' to dodge.\n");

		char action = '\0';
		scanf_s("%d", &action);
		if (action == 1)
		{
			printf("Choose ammo. Print '2' to use rocket launcher. Print '3' to use machine gun.\n");
			scanf_s("%d", &action);

			int G_action = rand() % 3;

			if (G_action == 1)
			{
				if (action == 2)
				{
					int strikes = rand() % 5;
					if (strikes > heli.rockets)
						strikes = heli.rockets;

					int hits = strikes - rand() % 2;
					OG_Mi_2->hp -= 95 * hits;
					heli.fuel -= rand() % 10;

					printf("You cause %d damage. Left %d fuel, %d rockets, %d bullets.\n", 95*hits, heli.fuel, heli.rockets, heli.bullets);
				}

				if (action == 3)
				{
					int strikes = rand() % 50;
					if (strikes > heli.bullets)
						strikes = heli.bullets;

					int hits = strikes - rand() % 10;
					OG_Mi_2->hp -= 7 * hits;
					heli.fuel -= rand() % 10;

					printf("You cause %d damage. Left %d fuel, %d rockets, %d bullets.\n", 7 * hits, heli.fuel, heli.rockets, heli.bullets);
				}

				int G_strikes = rand() % 5;

				if (G_strikes > OG_Mi_2->rockets)
					G_strikes = OG_Mi_2->rockets;

				int G_hits = G_strikes - rand() % 2;
				heli.hp -= 95 * G_hits;
				OG_Mi_2->fuel -= rand() % 10;

				printf("You take %d damage.\n", 95 * G_hits);
			}

			if (G_action == 2)
			{
				if (action == 2)
				{
					int strikes = rand() % 5;
					if (strikes > heli.rockets)
						strikes = heli.rockets;

					int hits = strikes - rand() % 2;
					OG_Mi_2->hp -= 95 * hits;
					heli.fuel -= rand() % 10;

					printf("You cause %d damage. Left %d fuel, %d rockets, %d bullets.\n", 95 * hits, heli.fuel, heli.rockets, heli.bullets);
				}

				if (action == 3)
				{
					int strikes = rand() % 50;
					if (strikes > heli.bullets)
						strikes = heli.bullets;

					int hits = strikes - rand() % 10;
					OG_Mi_2->hp -= 7 * hits;
					heli.fuel -= rand() % 10;

					printf("You cause %d damage. Left %d fuel, %d rockets, %d bullets.\n", 7 * hits, heli.fuel, heli.rockets, heli.bullets);
				}

				int G_strikes = rand() % 50;

				if (G_strikes > OG_Mi_2->bullets)
					G_strikes = OG_Mi_2->bullets;

				int G_hits = G_strikes - rand() % 10;
				heli.hp -= 7 * G_hits;
				OG_Mi_2->fuel -= rand() % 10;

				printf("You take %d damage.\n", 7 * G_hits);
			}

			if (G_action == 0)
			{
				if (action == 2)
				{
					int strikes = rand() % 5;
					if (strikes > heli.rockets)
						strikes = heli.rockets;

					int hits = strikes - rand() % 3;
					OG_Mi_2->hp -= 95 * hits;
					heli.fuel -= rand() % 10;

					printf("You cause %d damage. Left %d fuel, %d rockets, %d bullets.\n", 95 * hits, heli.fuel, heli.rockets, heli.bullets);
				}

				if (action == 3)
				{
					int strikes = rand() % 50;
					if (strikes > heli.bullets)
						strikes = heli.bullets;

					int hits = strikes - rand() % 25;
					OG_Mi_2->hp -= 7 * hits;
					heli.fuel -= rand() % 10;

					printf("You cause %d damage. Left %d fuel, %d rockets, %d bullets.\n", 7 * hits, heli.fuel, heli.rockets, heli.bullets);
				}

				OG_Mi_2->fuel -= rand() % 20;
			}
		}

		if (action == 0)
		{
			int G_action = rand() % 3;
			if (G_action == 1)
			{
				int G_strikes = rand() % 5;
				if (G_strikes > OG_Mi_2->rockets)
					G_strikes = OG_Mi_2->rockets;

				int G_hits = G_strikes - rand() % 3;
				heli.hp -= 95 * G_hits;
				OG_Mi_2->fuel -= rand() % 10;
				printf("You take %d damage.\n", 95 * G_hits);
			}

			if (G_action == 2)
			{
				int G_strikes = rand() % 50;
				if (G_strikes > OG_Mi_2->bullets)
					G_strikes = OG_Mi_2->bullets;

				int G_hits = G_strikes - rand() % 25;
				heli.hp -= 7 * G_hits;
				OG_Mi_2->fuel -= rand() % 10;
				printf("You take %d damage.\n", 7 * G_hits);
			}

			if (G_action == 0)
				OG_Mi_2->fuel -= rand() % 20;
			heli.fuel -= rand() % 20;

			printf("Left %d fuel, %d rockets, %d bullets.\n", heli.fuel, heli.rockets, heli.bullets);
		}

		if (action != 1 && action != 2 && action != 3 && action != 0)
			printf("Print 1 to attack. Print 0 to dodge.\n");

		if (OG_Mi_2->fuel <= 0)
		{
			OG_Mi_2->hp = 0;
			printf("Old Mi-2 crashed.\n");
		}

		if (heli.fuel <= 0)
		{
			heli.hp = 0;
			printf("You crashed.\n");
		}

		if (OG_Mi_2->hp <= 0)

			printf("You destroy old Mi-2.\n");

		if (heli.hp <= 0)
			printf("You destroyed.\n");
	}
}

Allihator* Destructor(Allihator* heli)
{
	free(heli->bullets);
	free(heli->fuel);
	free(heli->hp);
	free(heli->rockets);
	free(heli->name);
	free(heli);
	return NULL;
}
