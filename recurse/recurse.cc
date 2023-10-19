#include "recurse.hh"

namespace recurse{
	int factorial(int n){
		if(n<0){
			std::cout<<"input value invalid"<<std::endl;
			return -1;
		} else if(n==0){
			return 1;
		}else{
			return n*factorial(n-1);
		}
	}

	void drawRuler(int mainTickLength,int size){
		drawTick(mainTickLength,0);
		for(int i=1;i<=size;i++){
			drawInterval(mainTickLength-1);
			drawTick(mainTickLength,i);
		}
	}

	void drawTick(int size,int lable){
		for(int i=0;i<size;i++){
			std::cout<<"-";
		}
		if(lable>=0){
			std::cout<<lable;
		}
		std::cout<<std::endl;
	}

	void drawTick(int size){
		drawTick(size,-1);
	}

	void drawInterval(int mainTickLength){
		if(mainTickLength>0){
			drawInterval(mainTickLength-1);
			drawTick(mainTickLength);
			drawInterval(mainTickLength-1);
		}
	}

	bool binarySearch(int* pt,int target,int start,int end){
		if(start>end){
			return false;
		}
		int mid = start + (end-start)/2;
		if(target == pt[mid]){
			return true;
		}else if(target<pt[mid]){
			return binarySearch(pt,target,start,mid-1);
		}else{
			return binarySearch(pt,target,mid+1,end);
		}
	}

	int linearSum(int* pt,int n){
		if(n==0){
			return 0;
		}
		return pt[n-1]+linearSum(pt,n-1);
	}

	void reverseArray(int* pt,int low,int high){
		if(low<high){
			int temp = pt[low];
			pt[low]=pt[high];
			pt[high]=temp;
			reverseArray(pt,low+1,high-1);
		}
	}

	int power(int x,int n){
		if(n==0){
			return 1;
		}
		return x * power(x,n-1);
	}

	int morePower(int x,int n){
		if(n==0){
			return 1;
		}
		int temp = morePower(x,n/2);
		int result = temp*temp;
		if(n%2==1){
			result*=x;
		}
		return result;
	}

	int binarySum(int* pt,int low,int high){
		if(low>high){
			return 0;
		}
		if(low == high){
			return pt[low];
		}
		int mid = low+(high-low)/2;
		return binarySum(pt,low,mid)+binarySum(pt,mid+1,high);
	}

	bool unique3(int* pt,int low,int high){
		if(low>=high){
			return true;
		}else if(!unique3(pt,low+1,high)){
			return false;
		}else if(!unique3(pt,low,high-1)){
			return false;
		}else{
			return pt[low]!=pt[high];
		}
	}

	int fibonacciBad(int n){
		if(n<=1)
			return 1;
		return fibonacciBad(n-2)+fibonacciBad(n-1);
	}

	int* fibonacciGood(int n){
		if(n<=1){
			int* ret = new int[2];
			ret[0]=n;
			ret[1]=0;
			return ret;
		}else{
			int* temp=fibonacciGood(n-1);
			int* ret = new int[2];
			ret[0]=temp[0]+temp[1];
			ret[1]=temp[0];
			delete [] temp;
			return ret;
		}
	}
}