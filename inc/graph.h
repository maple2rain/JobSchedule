#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <QByteArray>

class Graph
{
public:
    Graph(const std::string &_username = "",
          const std::string &_graphName = "",
          const std::string &_graphType = "",
          const QByteArray &_graph = NULL) :
          username(_username),
          graphName(_graphName),
          graphType(_graphType),
          graph(_graph) {}
    ~Graph() {}

    /* getter */
    void setUsername(const std::string &_username) { username = _username; }
    void setGraph(const QByteArray &byte) { graph = byte; }
    void setGraphName(const std::string &_graphName) { graphName = _graphName; }
    void setGraphTyep(const std::string &_graphType) { graphType = _graphType; }

    /* setter */
    const std::string getUsername() { return username; }
    const std::string getGraphName() { return graphName; }
    const std::string getGraphType() { return graphType; }
    const QByteArray& getGraph() { return graph; }
private:
    std::string username;
    std::string graphName;
    std::string graphType;
    QByteArray graph;
};

#endif // GRAPH_H
