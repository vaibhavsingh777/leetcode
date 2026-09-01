class Solution {
private:

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(n==0) return 0;
        vector<vector<int>> adj(n);
        //adjacency
        for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1)
            {
                adj[i].push_back(j);
            }
            } 
        }

        
        int provinces = 0;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++){
            if(!vis[i]) provinces++;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int neighbor : adj[curr]){
                    if(!vis[neighbor]){
                        vis[neighbor] = true
                        ;
                        q.push(neighbor);
                    }
                }
            }
        }
        return provinces;
    }
};