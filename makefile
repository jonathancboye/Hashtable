all: main.o
	g++ main.o -o p4
main.o: main.cpp hashtable.h hashtable.cpp entry.h
	g++ -c main.cpp
clean:
	rm -f *.o *~ *#
