algo: main.o ArrayGame.o Sorting.o List.o
	g++ -Wall main.o ArrayGame.o Sorting.o List.o -o algo
main.o: main.cc
	g++ -Wall -c main.cc
ArrayGame.o: other/ArrayGame.cc
	g++ -Wall -c other/ArrayGame.cc
Sorting.o: sort/Sorting.cc
	g++ -Wall -c sort/Sorting.cc
List.o: list/List.cc
	g++ -Wall -c list/List.cc
clean:
	rm -rf *.o && rm -rf algo