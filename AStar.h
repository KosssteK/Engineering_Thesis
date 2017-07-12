#ifndef AStar_h
#define AStar_h
#include "naglowki.h"
#include "Vertex.h"

VertexList * aStarPathFinding(int startId, int endId, Vertex *& vertexTab, int ** valueTable, int vertexCount, sf::Image &imagePodkladu);

#endif