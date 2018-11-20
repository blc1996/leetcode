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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        unordered_set<int> visited;
        map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        UndirectedGraphNode* output = new UndirectedGraphNode(node->label);
        m[node] = output;
        DFS(node, visited, output, m);
        return output;
    }

    void DFS(UndirectedGraphNode* node, unordered_set<int>& visited, UndirectedGraphNode* output, map<UndirectedGraphNode *, UndirectedGraphNode *>& m){
        visited.insert(node->label);
        for(UndirectedGraphNode* n : node->neighbors){
            if(m.count(n)){
                output->neighbors.push_back(m[n]);
            }else{
                UndirectedGraphNode* tempNode = new UndirectedGraphNode(n->label);
                m[n] = tempNode;
                output->neighbors.push_back(tempNode);
            }
            if(visited.count(n->label)){
                continue;
            }
            DFS(n, visited, m[n], m);
        }
    }
};
