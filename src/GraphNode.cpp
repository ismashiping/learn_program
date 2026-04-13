#include<memory>
#include "GraphNode.h"
#include<iostream>
void GraphNode::addEdge(const std::shared_ptr<GraphNode>& node){
    std::weak_ptr<GraphNode> edge(node);
    m_edges.push_back(edge);
}
    void GraphNode::printEdeges() const{
        for(auto& edge:m_edges){
            std::cout<<edge.lock()->m_id<<" ";
        }
        std::cout<<std::endl;
    }

    void testGraphNode(){
        std::shared_ptr<GraphNode> node1(new GraphNode(1));
        std::shared_ptr<GraphNode> node2(new GraphNode(2));
        node1->addEdge(node2);
        node2->addEdge(node1);
        node1->printEdeges();
        node2->printEdeges();
    }