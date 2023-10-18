#include <iostream>

namespace recurse{
	int factorial(int n);

	void drawRuler(int mainTickLength,int size);
	void drawTick(int size,int lable);
	void drawTick(int size);
	void drawInterval(int mainTickLength);
	bool binarySearch(int* pt,int target,int start,int end);
	int linearSum(int* pt,int n);
	void reverseArray(int* pt,int low,int high);
	int power(int x,int n);
	int morePower(int x,int n);
}