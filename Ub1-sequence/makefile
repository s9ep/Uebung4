all: se

se: Main.o Sequence.o NucleicAcid.o Protein.o
	g++ Main.o Sequence.o NucleicAcid.o Protein.o -o se

Main.o: Main.cpp
	g++ -c Main.cpp
Sequence.o : Sequence.cpp
	g++ -c Sequence.cpp
NucleicAcid.o: NucleicAcid.cpp
	g++ -c NucleicAcid.cpp
Protein.o: Protein.cpp
	g++ -c Protein.cpp

clean:
	rm -rf *o se





