
void dfs(Node* old, vector<Node*>& vis, Node* cloned){
        
        for(auto x : old->neighbors){
            if(vis[x->val]){ // if the node is already available, just push it to the neighbors.
                cloned->neighbors.push_back(vis[x->val]);
            }
            else{
                Node* newNode = new Node(x -> val);
                cloned->neighbors.push_back(newNode);
                vis[x->val] = newNode;
                dfs(x, vis, newNode);
            }
        }
    }
    
    
    
    
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        
        vector<Node* > vis(101, NULL);
        
        Node* cloned = new Node(node->val);
        
        vis[cloned->val] = cloned;
        
        dfs(node, vis, cloned);
        
        return cloned;
    }
