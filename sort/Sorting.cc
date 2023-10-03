#include "Sorting.hh"

template<unsigned long N> void sorting::insertSort(char (&arr)[N]){
	for(size_t i=1;i<N;i++){
		char temp = arr[i];
		size_t cursor = i-1;
		while(cursor>=0 && arr[cursor]>temp){
			arr[cursor+1]=arr[cursor];
			cursor--;
		}
		arr[cursor+1]=temp;
	}
}

template void sorting::insertSort(char (&arr)[5]);