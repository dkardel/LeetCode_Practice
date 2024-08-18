#include"BitOps.h"
int SetNthBit(int number, int bitNumber)
{
	std::bitset<sizeof(int)*8> num(number);
	std::cout << "\nBefore bit Set : " << num << std::endl;
	int num2 = (1 << bitNumber) | number;
	std::bitset<sizeof(int) * 8> num3(num2);
	std::cout << "\After bit Set : " << num3 << std::endl;
	return num2;
}

int GetNthBit(int number, int bitNumber)
{
	std::bitset<sizeof(int) * 8> num(number);
	std::cout << "\nBinary of number : " << number  << " is " << num << std::endl;
	int num2 = (1 << bitNumber) & number;
	std::bitset<sizeof(int) * 8> num3(num2);
	std::cout << "\nBit at position " << bitNumber << " is " << num2 << std::endl;
	return num2;
}

int ClearNthBit(int number, int bitNumber)
{
	std::bitset<sizeof(int) * 8> num(number);
	std::cout << "\nBinary of number : " << number << " is " << num << std::endl;
	int num2 = (~(1 << bitNumber)) & number;
	std::bitset<sizeof(int) * 8> num3(num2);
	std::cout << "\nNumber After Clearing bit at position " << bitNumber << " is " << num3 << std::endl;
	return num2;
}

int DetectSignOfInt(int number)
{
	return -(int)((unsigned int)number >> (sizeof(int) * 8 - 1));
}

bool isIntegersHaveOppositeSign(int num1, int num2)
{
	return (num1 ^ num2) < 0;
}

int absoluteValue(int num)
{
	int mask = (num >> sizeof(int) * 8 - 1);
	int temp = (num + mask);
	int absNum = (num + mask) ^ mask;

	return absNum;
}

int min(int num1, int num2)
{
	return num2 ^ ((num1 ^ num2) & -(num1 < num2));
}

int max(int num1, int num2)
{
	return num1 ^ ((num1 ^ num2) & -(num1 < num2));
}

bool isIntegerPowerOfTwo(int number)
{
	return number && !(number & (number - 1));
}

int countSetBit(int number)
{
	unsigned int v = number; // count the number of bits set in v
	unsigned int c; // c accumulates the total bits set in v

	for (c = 0; v; v >>= 1)
	{
		c += v & 1;
	}
	return c;
}