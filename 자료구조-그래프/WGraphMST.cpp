#include "WGraphMST.h"

void main() {
	WGraphMST g;
	g.load("Wgraph.txt");
	g.display();
	printf("MST by Kruskal's Algorithm\n");
	g.Kruskal();
	printf("MST by Prim Algorithm\n");
	g.Prim(0);
}