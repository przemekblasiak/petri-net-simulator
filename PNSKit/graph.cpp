#include "graph.h"

Graph::Graph(QString name) {
    this->name = name;
}

Graph::~Graph() {
    for (Node *node: this->nodes) {
        delete node;
    }
    for (Edge *edge: this->edges) {
        delete edge;
    }
}

// TODO: Could be a template function
void Graph::addNode(const Node &nodeToAdd) {
    // Node names are unique
    bool alreadyExists = this->nodeNamed(nodeToAdd.name) != 0;
    if (alreadyExists) {
        return;
    }
    Node *newNode = new Node(nodeToAdd);
    this->nodes.append(newNode);
}

void Graph::addEdge(const Edge &edgeToAdd) {
    this->edges.append(new Edge(edgeToAdd));
}

void Graph::draw(QLabel *pixmapLabel) {
    // Graph
    QString graphString = "digraph ";
    graphString += this->name;

    // Nodes
    QString nodesString = "";
    for (int i = 0; i < this->nodes.count(); ++i) {
        // Node
        nodesString += QString::number(i);

        // Attributes
        nodesString += "[label=\"" + this->nodes[i]->name + "\"];";
    }

    // Edges
    QString edgesString = "";
    for (int i = 0; i < this->edges.count(); ++i) {
        // Edge
        Edge *edge = this->edges[i];
        int fromNodeIndex = this->nodes.indexOf(edge->fromNode);
        int toNodeIndex = this->nodes.indexOf(edge->toNode);
        QString edgeString = QString::number(fromNodeIndex) + "->" + QString::number(toNodeIndex);

        // Attributes
        QString labelAttribute = "label=\"" + edge->name + "\"";
        QString constraintAttribute = "";
        bool pointsUp = edge->toNode->level < edge->fromNode->level;
        if (pointsUp) {
            constraintAttribute += "constraint=false";
        }
        edgesString += edgeString + "[" + labelAttribute + " " + constraintAttribute + "]";
    }

    // Merge strings
    QString dotString = graphString + "{" + nodesString + edgesString + "}";

    // Export to DOT and then PNG
#if defined(Q_OS_OSX)
    system(QString("echo '" + dotString + "'>file.dot").toStdString().c_str());
    system("/usr/local/bin/dot -Tpng file.dot -o graph.png"); // TODO: Adjust the path
#elif defined(Q_OS_LINUX)
    system(QString("echo '" + dotString + "'>file.dot").toStdString().c_str());
    system("dot -Tpng file.dot -o graph.png"); // TODO: Adjust the path
#elif defined(Q_OS_WIN32)
    pixmapLabel->setText("Windows does not support the feature yet.");
    return;
#endif

    // Display
    QPixmap pixmap("graph.png");
    pixmapLabel->setPixmap(pixmap);
}

// TODO: Could be a template function
Graph::Node * Graph::nodeNamed(QString name) {
    for (Node *node: this->nodes) {
        if (node->name == name) {
            return node;
        }
    }
    return 0;
}

Graph::Edge * Graph::edgeNamed(QString name) {
    for (Edge *edge: this->edges) {
        if (edge->name == name) {
            return edge;
        }
    }
    return 0;
}
