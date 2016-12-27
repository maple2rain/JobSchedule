#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <QByteArray>
#include "app_cfg.h"

class Graph
{
public:
    Graph(const std::string &_id = "",
          const std::string &_graphType = "",
          const QByteArray &_graph = NULL) :
          id(_id),
          graphType(_graphType),
          graph(_graph) {}
    ~Graph() {}

    /* setter */
    void setGraph(const QByteArray &byte) { graph = byte; }
    void setGraphType(const std::string &_graphType) { graphType = _graphType; }
    void setGraphID(const std::string &_id) { id = _id; }

    /* getter */
    const std::string& getGraphType() { return graphType; }
    const QByteArray& getGraph() { return graph; }
    std::string& getGraphID() { return id; }
private:
    std::string id;
    std::string graphType;
    QByteArray graph;
};

#endif // GRAPH_H
