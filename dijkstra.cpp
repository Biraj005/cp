class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int>dist(V,1e9);
        vector<vector<pair<int,int>>>adj(V);
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            
            
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int Node = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            
            for(auto &it:adj[Node]){
                
                int adjNode = it.first;
                int edWt = it.second;
                
                if(edWt + w < dist[adjNode]){
                    
                    dist[adjNode] = w + edWt;
                    pq.push({dist[adjNode],adjNode});
                }
                
                
                
            }
            
            
        }
          return dist;
    }
};
