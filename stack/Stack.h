#include <iostream>
#include <sstream>
namespace stack{
	template <typename T> class ArrayStack{
		public:
			static const int CAPACITY = 1000;
			ArrayStack(int cap):capacity(cap){
				data = new T*[cap];
				for(int i=0;i<capacity;i++){
					data[i]=nullptr;
				}
			}
			ArrayStack():ArrayStack(CAPACITY){}
			int size(){
				return this->top_index+1;
			}
			bool isEmpty(){
				return this->top_index<0;
			}
			~ArrayStack();
			std::string toString();
			void push(T* e);
			T* top();
			T* pop();
		private:
			T** data;
			int capacity;
			int top_index = -1;
	};
}