#pragma once
class speedhack;
class ptr1class;
class ptr2class;

class speedhack
{
public:
	ptr1class* ptr1; //0x0000 
	char pad_0x0004[0x3C]; //0x0004
}; //Size=0x0040

class ptr1class
{
public:
	ptr2class* ptr2; //0x0000 
}; //Size=0x0004

class ptr2class
{
public:
	char pad_0x0000[0x244]; //0x0000
	float speed; //0x0244 
	char pad_0x0248[0x1BC]; //0x0248
}; //Size=0x0404