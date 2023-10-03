algo: main.o ArrayGame.o Sorting.o
	g++ -Wall main.o ArrayGame.o Sorting.o -o algo
main.o: main.cc
	g++ -Wall -c main.cc
ArrayGame.o: other/ArrayGame.cc
	g++ -Wall -c other/ArrayGame.cc
Sorting.o: sort/Sorting.cc
	g++ -Wall -c sort/Sorting.cc
clean:
	rm -rf *.o && rm -rf algo