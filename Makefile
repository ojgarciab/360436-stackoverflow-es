all: pruebas

clean:
	rm -f pruebas.o pruebas

pruebas: pruebas.o
	g++ -o pruebas pruebas.o

pruebas.o: pruebas.cpp
	g++ -c pruebas.cpp
