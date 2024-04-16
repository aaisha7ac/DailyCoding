/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    // TC : O(V + E)
    // SC : O(V)

public:

    unordered_map<Node*,Node*>mp;

    void bfs_Traversal(Node* node) {

        queue<Node*>q;
        q.push(node);

        while(!q.empty()) {

            Node* node = q.front();
            Node* clone_node = mp[node];
            q.pop();

            for(Node* n : node->neighbors) {

                // if neighbours are not cloned
                if(mp.find(n) == mp.end()) {
                    Node* clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);
                    q.push(n);
                }
                // if neighbours are already cloned
                else {
                    clone_node->neighbors.push_back(mp[n]);
                }
            }
        }
    }


    Node* cloneGraph(Node* node) {
        
        if(node == NULL) {
            return node;
        }

        Node* clone_node = new Node(node->val);

        // mapping old node with new node
        mp[node] = clone_node;

        bfs_Traversal(node);

        return clone_node;

        
    }
};