CFLAGS = -Wall -g -Iinclude
all: programma

programma: main.o graph.o vertexList.o adjlist.o
	gcc ${CFLAGS} main.o graph.o vertexList.o adjlist.o -o programma

main.o: src/main.c include/graph.h include/vertex_edge.h
	gcc ${CFLAGS} -c src/main.c -o main.o

graph.o: src/graph.c include/graph.h
	gcc ${CFLAGS} -c src/graph.c -o graph.o

vertexList.o: src/vertexList.c include/vertexList.h
	gcc ${CFLAGS} -c src/vertexList.c -o vertexList.o

adjlist.o: src/adjlist.c include/adjlist.h
	gcc ${CFLAGS} -c src/adjlist.c -o adjlist.o

clean:
	rm -f *.o