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
	int binarySum(int* pt,int low,int high);
	bool unique3(int* pt,int low,int high);
	int fibonacciBad(int n);
	int* fibonacciGood(int n);
	template <unsigned N> bool binarySearchIterative(int (&data)[N],int target){
		unsigned low=0,high=N-1;
		while(low<=high){
			unsigned mid = low+(high-low)/2;
			if(data[mid]==target){
				return true;
			}else if(data[mid]>target){
				high=mid-1;
			}else{
				low=mid+1;
			}
		}
		return false;
	}
	template<unsigned N> void reverseIterative(int (&arr)[N]){
		unsigned low=0,high = N-1;
		while(low<high){
			int temp=arr[low];
			arr[low]=arr[high];
			arr[high]=temp;
			low++;
			high--;
		}
	}
}