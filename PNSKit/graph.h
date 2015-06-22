#ifndef GRAPH_H
#define GRAPH_H

#include "pnsglobal.h"

class Graph
{
public:
    struct Node;
    struct Edge;

    Graph(QString name);
    ~Graph();
    void addNode(const Node &nodeToAdd);
    void addEdge(const Edge &edgeToAdd);
    void draw(QLabel *pixmapLabel);
    Node * nodeNamed(QString name);
    Edge * edgeNamed(QString name);

    QString name;
    QList<Node *> nodes;
    QList<Edge *> edges;
};

struct Graph::Node {
    Node(QString name, unsigned level) {
        this->name = name;
        this->level = level;
    }
    QString name;
    unsigned level;
};

struct Graph::Edge {
    Edge(QString name, Graph::Node *fromNode, Graph::Node *toNode) {
        this->name = name;
        this->fromNode = fromNode;
        this->toNode = toNode;
    }
    QString name;
    Graph::Node *fromNode;
    Graph::Node *toNode;
};

#endif // GRAPH_H
