#include <iostream>
#include <sstream>

namespace queue{
	template <typename T> class ArrayQueue{
		public:
			ArrayQueue():data(new T*[CAPACITY]){
				for(int i=0;i<CAPACITY;i++){
					data[i]=nullptr;
				}
			}
			ArrayQueue(int capacity):CAPACITY(capacity),data(new T*[CAPACITY]){
				for(int i=0;i<CAPACITY;i++){
					data[i]=nullptr;
				}
			}
			int size(){
				return _size;
			}
			bool isEmpty(){
				return _size<=0;
			}
			void enqueue(T* e);
			T* first();
			T* dequeue();
			~ArrayQueue();
			std::string toString();
		private:
			int CAPACITY = 1000;
			int f=0;
			int _size=0;
			std::unique_ptr<T*[]> data;
	};

	template<typename T> void ArrayQueue<T>::enqueue(T* e){
		if(_size >= CAPACITY){
			std::cout<<"the queue is full"<<std::endl;
			return;
		}
		int avail=(f+_size)%CAPACITY;
		data[avail] = e;
		_size++;
	}

	template<typename T> T* ArrayQueue<T>::first(){
		if(isEmpty()){
			return nullptr;
		}
		return data[f];
	}

	template<typename T> T* ArrayQueue<T>::dequeue(){
		if(isEmpty()){
			std::cout<<"the queue is empty, can't dequeue"<<std::endl;
			return nullptr;
		}
		T* temp = data[f];
		data[f]=nullptr;
		f=(f+1)%CAPACITY;
		_size--;
		return temp;
	}

	template<typename T> ArrayQueue<T>::~ArrayQueue(){
		for(int i=0;i<_size;i++){
			int cursor = (i+f)%CAPACITY;
			delete data[cursor];
			data[cursor]=nullptr;
		}
	}

	template<typename T> std::string ArrayQueue<T>::toString(){
		std::stringstream stream;
		stream<<"HEAD->";
		for(int i=0;i<_size;i++){
			int index = (f+i)%CAPACITY;
			stream<<*(data[index]);
			stream<<"->";
		}
		stream<<"TAIL";
		return stream.str();
	}
}