CFLAGS = -Wall -g -Iinclude
all: programma

programma: main.o graph.o vertexList.o adjlist.o binary_heap.o
	gcc ${CFLAGS} main.o graph.o vertexList.o adjlist.o binary_heap.o -o programma

main.o: src/main.c include/graph.h include/vertex_edge.h
	gcc ${CFLAGS} -c src/main.c -o main.o

binary_heap.o: src/binary_heap.c include/binary_heap.h
	gcc ${CFLAGS} -c src/binary_heap.c -o binary_heap.o

graph.o: src/graph.c include/graph.h
	gcc ${CFLAGS} -c src/graph.c -o graph.o

vertexList.o: src/vertexList.c include/vertexList.h
	gcc ${CFLAGS} -c src/vertexList.c -o vertexList.o

adjlist.o: src/adjlist.c include/adjlist.h
	gcc ${CFLAGS} -c src/adjlist.c -o adjlist.o

clean:
	rm -f *.o