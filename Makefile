All: algo
algo: main.o ArrayGame.o Sorting.o List.o recurse.o
	g++ -Wall $^ -o $@
main.o: main.cc
	g++ -Wall -c $<
ArrayGame.o: other/ArrayGame.cc other/ArrayGame.hh
	g++ -Wall -c $<
Sorting.o: sort/Sorting.cc sort/Sorting.hh
	g++ -Wall -c $<
List.o: list/List.cc list/List.hh
	g++ -Wall -c $<
recurse.o: recurse/recurse.cc recurse/recurse.hh
	g++ -Wall -c $<
distclean:
	rm -rf *.o && rm -rf algo
clean:
	rm -rf algo