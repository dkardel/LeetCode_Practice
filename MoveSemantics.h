#pragma once
#include<cstdio>
#include<cstdlib>
#include<iostream>

class string
{
private:
	char* m_Data;
	size_t m_Size;
public:
	string(const char* string);
};

