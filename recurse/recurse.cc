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
}