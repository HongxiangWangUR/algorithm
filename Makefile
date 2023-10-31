VPATH = list other recurse sort stack
objects = main.o ArrayGame.o Sorting.o List.o recurse.o Stack.o
maininclude = -Ilist -Iother -Irecurse -Isort -Istack
CXX = g++
CXXFLAGS = $(maininclude) -std=c++11 -stdlib=libc++
All: algo
algo: $(objects)
	g++ $(objects) -o algo
ArrayGame.o: ArrayGame.hh
Sorting.o: Sorting.hh
List.o: List.hh
recurse.o: recurse.hh
Stack.o: Stack.h
distclean:
	rm -rf *.o && rm -rf algo
clean:
	rm -rf algo