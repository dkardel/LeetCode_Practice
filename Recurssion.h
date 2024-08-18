#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<unordered_map>
#include"BSTCpp14.h"
void printNumberWithRecurssion(int bound);
void fibbonacciSeries(int end);
int factorial(int number);
int heightOfTree(dsa::BST* root);
void sort(std::vector<int>& vect);
void sort(std::stack<int>& vect);
void deleteStackElement(std::stack<int>& stk, int index);
void reverseStack(std::stack<int>& stk);
int kthGrammer(int row, int index);

void towerOfHonoi(int n, int s, int d, int h);
void stringSubset(std::string ip, std::string op);

void stringSubsetWithSpace(std::string ip, std::string op);

void stringSubsetWithCaseChange(std::string ip, std::string op);

void stringSubsetWithCaseChangeWithNum(std::string ip, std::string op);

void balancedParanthesis(std::string op, int open, int close);

void binaryNumberWithPrefix(std::string op, int one, int zero, int n);


void JosephusProblem(std::vector<int>& totalPerson, int killIndex, int index);

