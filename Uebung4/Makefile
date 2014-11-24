all: Uebung4

Uebung4: main.o Sequence.o NucleicAcid.o Alignment.o
	g++ main.o Sequence.o NucleicAcid.o Alignment.o -o Uebung4

main.o: main.cpp
	g++ -c main.cpp

Sequence.o: Sequence.cpp
	g++ -c Sequence.cpp

NucleicAcid.o: NucleicAcid.cpp
	g++ -c NucleicAcid.cpp

Alignment.o: Alignment.o
	g++ -c Alignment.cpp




clean:
	rm -rf *.o  Uebung4