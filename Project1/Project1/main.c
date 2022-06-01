#include "mytype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	Allihator* heli = Constructor("heli", 1500, 1500, 1500, 1500);

	Attack_Enemy(*heli);

	Destroy_Enemy_Base(*heli);

	Refuel(*heli);

	Load(*heli);

	Airbattle(*heli);

	Destructor(heli);
}