/*
https://oj.leetcode.com/problems/clone-graph/

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
// first try, BFS
    UndirectedGraphNode *cloneGraph_1(UndirectedGraphNode *node) { 
        if (!node) {
            return NULL;
        }
        queue<UndirectedGraphNode *> q;
        q.push(node);
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            if (m.find(cur) == m.end()) { // not necessary since all the nodes in the queue haven't been visited (stored in map) when they were pushed into queue.
                m[cur] = new UndirectedGraphNode(cur->label);
            }
            for (int i = 0; i < cur->neighbors.size(); ++i) {
                UndirectedGraphNode *neighbor = cur->neighbors[i];
                if (m.find(neighbor) == m.end()) {
                    m[neighbor] = new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor); // pay attention here;
                }
                m[cur]->neighbors.push_back(m[neighbor]);
            }
        }
        return m[node];
    }
// optimized, BFS     
    UndirectedGraphNode *cloneGraph_2(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        queue<UndirectedGraphNode *> q;
        q.push(node);
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
        visited[node] = new UndirectedGraphNode(node->label);
        while (!q.empty()) {
            UndirectedGraphNode *origNode = q.front();
            q.pop();
            UndirectedGraphNode *newNode = visited[origNode];                                                                                    
            for (int i = 0; i < origNode->neighbors.size(); ++i) {
                 UndirectedGraphNode *oriNeighbor = origNode->neighbors[i];
                 if (visited.find(oriNeighbor) == visited.end()) {
                     visited[oriNeighbor] = new UndirectedGraphNode(oriNeighbor->label);
                     q.push(oriNeighbor);
                 }
                 newNode->neighbors.push_back(visited[oriNeighbor]);
            }
        }
        return visited[node];
    }

// DFS, first try
    UndirectedGraphNode *cloneGraph_3(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
        return cloneGraphRe_3(node, visited);
    }
    UndirectedGraphNode *cloneGraphRe_3(UndirectedGraphNode *node, 
                     unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &visited) {
        if (!node) {
            return NULL;
        }
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        visited[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            UndirectedGraphNode * origNeighbor = node->neighbors[i];
            if (visited.find(origNeighbor) == visited.end()) {
                cloneGraphRe_3(origNeighbor, visited);
            }
            newNode->neighbors.push_back(visited[origNeighbor]); // possible defect if there exist NULL pointers in the node->neighbors (these NULL pointers won't be cloned).
        }
        return newNode;
    }
    
    // DFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
        return cloneGraphRe(node, visited);
    }
    UndirectedGraphNode *cloneGraphRe(UndirectedGraphNode *node, 
                     unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &visited) {
        if (!node) {
            return NULL;
        }
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        visited[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            newNode->neighbors.push_back(cloneGraphRe(node->neighbors[i], visited));
        }
        return newNode;
    }
    
};
