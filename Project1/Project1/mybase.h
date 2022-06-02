#pragma once
#include "mytype.h"

typedef struct Data_Base
{
	Allihator* heli;
	int ID;
} Base;

Base* B_Constructor(Allihator* heli);

void Get_Data_From_Console();

void Get_Data_From_File();

void Clear_Last_Element(Base baza);

void Clear_ID_Element(Base baza);

void Clear_Some_Elements(Base baza);

void Print_Element(Base baza);

void Print_Some_Elements(Base baza);

void Printf_Element(Base baza);

void Printf_Some_Elements(Base baza);

void Print_Base(Base baza);

void Printf_Base(Base baza);

void Sort(Base baza);

Base* B_Destructor(Base* baza);