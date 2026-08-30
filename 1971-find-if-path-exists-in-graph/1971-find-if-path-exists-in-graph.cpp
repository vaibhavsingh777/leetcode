class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //construct the adjacency first
        vector<vector<int>> adj(n);
        for(const auto& edge : edges){
        int child = edge[0];
        int parent = edge[1];
        adj[parent].push_back(child);
        adj[child].push_back(parent);
        }
        if(n == 1 || source == destination)  return true;

        //start bfs on source, then just check if destination 
        //exists in it or not

        queue<int> q;
        vector<bool> vis(n, false);
        unordered_set<int> res;
        q.push(source);
        
        vis[source] = true;
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            for(const auto& neighbour : adj[parent]){
                if(!vis[neighbour]){
                    vis[neighbour] = true;
                    q.push(neighbour);
                    res.insert(neighbour);
                }
             }
        }
        return res.count(destination);
    }
};