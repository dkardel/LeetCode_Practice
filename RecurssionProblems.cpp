#include"Recurssion.h"
void printNumberWithRecurssion(int bound)
{
	if (bound == 0)
		return;
	printNumberWithRecurssion(bound - 1);
	std::cout << bound << " ";
}

void fibbonacciSeries(int end)
{
	static int n1 = 0, n2 = 1, n3;
	if (end > 1)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		printf("%d ", n3);
		fibbonacciSeries(end - 1);
	}
}

int factorial(int number)
{
	if (number <= 1)
		return 1;
	return factorial(number - 1) * number;
}

int heightOfTree(dsa::BST* root)
{
	if (!root)
		return 0;
	int x = heightOfTree(root->left);
	int y = heightOfTree(root->right);
	return 1 + std::max(x , y);
}

void insert(std::vector<int>& vect, int data)
{
	if (vect.size() == 0 || vect[vect.size() - 1] <= data)
	{
		vect.push_back(data);
		return;
	}
	int temp = vect[vect.size() - 1];
	vect.pop_back();
	insert(vect, data);
	vect.push_back(temp);
}

void sort(std::vector<int>& vect)
{
	if (vect.size() == 1)
		return;
	int temp = vect[vect.size() - 1];
	vect.pop_back();
	sort(vect);
	insert(vect, temp);
}

void insert(std::stack<int>& vect, int data)
{
	if (vect.size() == 0 || vect.top() <= data)
	{
		vect.push(data);
		return;
	}
	int temp = vect.top();
	vect.pop();
	insert(vect, data);
	vect.push(temp);
}

void sort(std::stack<int>& vect)
{
	if (vect.size() == 1)
		return;
	int temp = vect.top();
	vect.pop();
	sort(vect);
	insert(vect, temp);
}

void deleteStackElement(std::stack<int>& stk, int index)
{
	if (index == 1)
	{
		stk.pop();
		return;
	}
	int temp = stk.top();
	stk.pop();
	deleteStackElement(stk, index - 1);
	stk.push(temp);
}

void insertAtStart(std::stack<int>& vect, int data)
{
	if (vect.empty())
	{
		vect.push(data);
		return;
	}
	int temp = vect.top();
	vect.pop();
	insertAtStart(vect, data);
	vect.push(temp);
}

void reverseStack(std::stack<int>& stk)
{
	if (stk.empty() || stk.size()==1)
		return;
	int temp = stk.top();
	stk.pop();
	reverseStack(stk);
	insertAtStart(stk, temp);	
}

int kthGrammer(int row, int index)
{
	if (row == 1 || index == 1)
	{
		int value = 0;
		return value;
	}
	int mid = pow(2, row-1) / 2;
	if (index <= mid)
	{	
		int value = kthGrammer(row - 1, index);
		return value;
	}
	else
	{
		int ret = kthGrammer(row - 1, index - mid);
		if (ret == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void towerOfHonoi(int n, int s, int d, int h)
{
	if (n == 1)
	{
		std::cout << "Moving plate from " << s << " to " << d << std::endl;
		return;
	}
	towerOfHonoi(n - 1, s, h, d);
	std::cout << "Moving plate from " << s << " to " << d << std::endl;
	towerOfHonoi(n - 1, h, d, s); 
}

void stringSubset(std::string ip, std::string op)
{
	if (ip.length() == 0)
	{
		std::cout << "{ " << op << " }, ";
		return;
	}
	std::string op1 = op;
	std::string op2 = op;
	op2.push_back(ip[0]);
	ip.erase(ip.begin() + 0);
	stringSubset(ip, op1);
	stringSubset(ip, op2); 
}

void stringSubsetWithSpace(std::string ip, std::string op)
{
	if (ip.length() == 0)
	{
		std::cout << "{ " << op << " }, ";
		return;
	}
	std::string op1 = op;
	std::string op2 = op;
	op2.push_back('_');
	op2.push_back(ip[0]);
	op1.push_back(ip[0]);
	ip.erase(ip.begin() + 0);
	stringSubsetWithSpace(ip, op1);
	stringSubsetWithSpace(ip, op2);
}

void stringSubsetWithCaseChange(std::string ip, std::string op)
{
	if (ip.length() == 0)
	{
		std::cout << "{ " << op << " }, ";
		return;
	}
	
	std::string op1 = op;
	std::string op2 = op;
	op2.push_back(toupper(ip[0]));
	op1.push_back(ip[0]);
	ip.erase(ip.begin() + 0);
	stringSubsetWithCaseChange(ip, op1);
	stringSubsetWithCaseChange(ip, op2);
}

void stringSubsetWithCaseChangeWithNum(std::string ip, std::string op)
{
	if (ip.length() == 0)
	{
		std::cout << "{ " << op << " }, ";
		return;
	}

	std::string op1 = op;
	std::string op2 = op;
	char ch = ip[0];
	ip.erase(ip.begin() + 0);
	if (isalpha(ch))
	{
		op2.push_back(tolower(ch));
		op1.push_back(toupper(ch));
		stringSubsetWithCaseChangeWithNum(ip, op1);
		stringSubsetWithCaseChangeWithNum(ip, op2);
	}
	else
	{
		op2.push_back(ch);
		stringSubsetWithCaseChangeWithNum(ip, op2);
	}
}

void balancedParanthesis(std::string op, int open, int close)
{
	if (open == 0 && close==0)
	{
		std::cout << "{ " << op << " }, ";
		return;
	}

	std::string op1 = op;
	std::string op2 = op;
	if (open == close)
	{
		op1.push_back('(');
		balancedParanthesis(op1, open-1, close);
	}
	else if (open == 0)
	{
		op1.push_back(')');
		balancedParanthesis(op1, open, close-1);
	}
	else
	{
		op1.push_back('(');
		op2.push_back(')');
		balancedParanthesis(op1, open-1, close);
		balancedParanthesis(op2, open, close-1);
	}
}

void binaryNumberWithPrefix(std::string op, int one, int zero, int n)
{
	if (n == 0)
	{
		std::cout << "{ " << op << " }, ";
		return;
	}

	std::string op1 = op;
	std::string op2 = op;
	if (one == 0)
	{
		op1.push_back('1');
		binaryNumberWithPrefix(op1, one + 1, zero, n-1);
	}
	else if (one >= zero)
	{
		op1.push_back('0');
		binaryNumberWithPrefix(op1, one, zero+1, n-1);

		op2.push_back('1');
		binaryNumberWithPrefix(op2, one +1, zero, n - 1);
	}
}

void JosephusProblem(std::vector<int>& totalPerson, int killIndex, int index)
{
	if (totalPerson.size() == 1)
	{
		std::cout << "\nPerson survived is " << totalPerson[0];
		return;
	}
	int newIndex = (killIndex + index) % totalPerson.size();
	int killedPerson = totalPerson[newIndex];
	totalPerson.erase(totalPerson.begin() + newIndex);
	std::cout << "\nPerson Killed at Index " << newIndex << " is " << killedPerson;
	JosephusProblem(totalPerson, killIndex, newIndex);
}