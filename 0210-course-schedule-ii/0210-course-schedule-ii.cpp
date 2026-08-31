class Solution {
private:
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        //building adjacency and indegree
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(const auto& edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        vector<int> topoorder;
        //process all nodes with zero indegree inside q
        for(int i =0; i< V;i++){
            if(indegree[i] == 0) q.push(i);
        }

        //apply bfs
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topoorder.push_back(curr);

            for(const auto& neighbour : adj[curr]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        return topoorder.size() == V ? topoorder : vector<int>{};
    }
};