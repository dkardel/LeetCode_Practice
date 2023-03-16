#include<cstdio>
#include<cstdlib>
#include<iostream>
class string
{

private:
	char* m_Data;
	size_t m_Size;
public:
	string() { m_Data = nullptr; }
	string(const char* string)
	{
		puts("Created\n");
		m_Size = (strlen(string) + 1);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	string(const string& other)
	{
		puts("Copied\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}
	string(string&& other) noexcept
	{
		puts("Moved\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;
		other.m_Data = nullptr;
		other.m_Size = 0;
	}
	string& operator =(string&& other) noexcept
	{	
		
		if (this != &other)
		{
			delete m_Data;
			puts("Assigned\n");
			m_Size = other.m_Size;
			m_Data = other.m_Data;
			other.m_Data = nullptr;
			other.m_Size = 0;
			
		}
		return *this;
	}
	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
	}
	~string()
	{
		if(m_Data)
		delete m_Data;
	}
};

class Entity
{
public:
	Entity(const string& name):m_Name(name){}
	Entity(string&& name) :m_Name(name) {}
	void PrintName()
	{
		m_Name.Print();
	}
private:
	string m_Name;
};