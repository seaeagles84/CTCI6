// A C++ program to Clone an Undirected Graph
#include<bits/stdc++.h>
using namespace std;

struct GraphNode
{
    int val;
    
    vector<GraphNode *> neighbours;
};

// A function which clones a Graph and
// returns the address to the cloned
// src node
GraphNode *cloneGraph(GraphNode *src)
{
    GraphNode *pnode;
    queue<GraphNode*> q_nodes;
    unordered_map<GraphNode*,GraphNode*> map;
    
    if (src == nullptr)
        return nullptr;
        
    q_nodes.push(src);
    pnode = new GraphNode();
    pnode->val = src->val;
    map[src] = pnode;
    
    while (!q_nodes.empty()) {
        pnode = q_nodes.front();
        q_nodes.pop();
        
        for (int i = 0; i < pnode->neighbours.size(); i++){
            if (map.count(pnode->neighbours[i]) == 0) {
                GraphNode *tmp = new GraphNode();
                tmp->val = pnode->neighbours[i]->val;
                map[pnode->neighbours[i]] = tmp;
                
                // only those we have not visited needs to be added.
                q_nodes.push(pnode->neighbours[i]);  
            }
            
            map[pnode]->neighbours.push_back(map[pnode->neighbours[i]]);
        }
    }
    
    return (map[src]);
}

// Build the desired graph
GraphNode *buildGraph()
{
	/*
		Note : All the edges are Undirected
		Given Graph:
		1--2
		| |
		4--3
	*/
	GraphNode *node1 = new GraphNode();
	node1->val = 1;
	GraphNode *node2 = new GraphNode();
	node2->val = 2;
	GraphNode *node3 = new GraphNode();
	node3->val = 3;
	GraphNode *node4 = new GraphNode();
	node4->val = 4;
	vector<GraphNode *> v;
	v.push_back(node2);
	v.push_back(node4);
	node1->neighbours = v;
	v.clear();
	v.push_back(node1);
	v.push_back(node3);
	node2->neighbours = v;
	v.clear();
	v.push_back(node2);
	v.push_back(node4);
	node3->neighbours = v;
	v.clear();
	v.push_back(node3);
	v.push_back(node1);
	node4->neighbours = v;
	return node1;
}

// A simple bfs traversal of a graph to
// check for proper cloning of the graph
void bfs(GraphNode *src)
{
	map<GraphNode*, bool> visit;
	queue<GraphNode*> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty())
	{
		GraphNode *u = q.front();
		cout << "Value of Node " << u->val << "\n";
		cout << "Address of Node " <<u << "\n";
		q.pop();
		vector<GraphNode *> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			if (!visit[v[i]])
			{
				visit[v[i]] = true;
				q.push(v[i]);
			}
		}
	}
	cout << endl;
}

// Driver program to test above function
int main()
{
	GraphNode *src = buildGraph();
	cout << "BFS Traversal before cloning\n";
	bfs(src);
	GraphNode *newsrc = cloneGraph(src);
	cout << "BFS Traversal after cloning\n";
	bfs(newsrc);
	return 0;
}
