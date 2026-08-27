class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //building adjacency list and indegree array
        int V = numCourses;
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for(const auto& pair: prerequisites){
            int course = pair[0];
            int prereq = pair[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        //collecting all nodes w/ indegree 0
        queue<int> q;
        for(int u = 0; u < V; u++){
            if(indegree[u]==0) q.push(u);
        }

        //processing the queue for topoorder
        vector<int> topoorder;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            topoorder.push_back(u);
            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        if(topoorder.size() != V) return false;
        else return true;
    }
};