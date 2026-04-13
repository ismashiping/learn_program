#include <memory>
#include<vector>
class GraphNode
{
private:
    int m_id;
    std::vector<std::weak_ptr<GraphNode>> m_edges;
    /* data */
public:
    GraphNode(int id):m_id(id){};
    void addEdge(const std::shared_ptr<GraphNode>& node);
    void printEdeges() const;
    // ~GraphNode();
};
void testGraphNode();