All: algo
algo: main.o ArrayGame.o Sorting.o List.o
	g++ -Wall main.o ArrayGame.o Sorting.o List.o -o algo
main.o: main.cc
	g++ -Wall -c main.cc
ArrayGame.o: other/ArrayGame.cc other/ArrayGame.hh
	g++ -Wall -c other/ArrayGame.cc
Sorting.o: sort/Sorting.cc sort/Sorting.hh
	g++ -Wall -c sort/Sorting.cc
List.o: list/List.cc list/List.hh
	g++ -Wall -c list/List.cc
distclean:
	rm -rf *.o && rm -rf algo
clean:
	rm -rf algo