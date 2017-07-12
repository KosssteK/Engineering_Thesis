#ifndef Dikstra_h
#define Dikstra_h
#include "naglowki.h"
#include "Vertex.h"

VertexList * dikstraPathFinding(int startId, int endId, Vertex *& vertexTab, int ** valueTable, int vertexCount, sf::Image &imagePodkladu);

#endif