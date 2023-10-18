VPATH = list other recurse sort
objects = main.o ArrayGame.o Sorting.o List.o recurse.o
maininclude = -Ilist -Iother -Irecurse -Isort
All: algo
algo: $(objects)
	g++ -Wall $(maininclude) $^ -o $@
main.o: main.cc
	g++ -Wall $(maininclude) -c $^ -o $@
ArrayGame.o: ArrayGame.hh
Sorting.o: Sorting.hh
List.o: List.hh
recurse.o: recurse.hh
distclean:
	rm -rf *.o && rm -rf algo
clean:
	rm -rf algo