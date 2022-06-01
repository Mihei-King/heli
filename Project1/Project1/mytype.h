#pragma once

typedef struct KA_52_Allihator
{
	char* name;
	int fuel;
	int hp;
	int rockets;
	int bullets;
} Allihator;

Allihator* Constructor(char* name, int fuel, int hp, int rockets, int bullets);

void Attack_Enemy(Allihator heli);

void Destroy_Enemy_Base(Allihator heli);

void Refuel(Allihator heli);

void Load(Allihator heli);

void Airbattle(Allihator heli);

Allihator* Destructor(Allihator* heli);