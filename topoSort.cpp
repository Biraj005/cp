class Solution {
  private:
    void dfs(int Node,vector<bool>&visited,vector<vector<int>>&adj,
    vector<int>&ans){
        
        visited[Node] = true;
        for(auto &it:adj[Node]){
            if(!visited[it]) dfs(it,visited,adj,ans);
        }
        ans.push_back(Node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {        
        vector<bool>visited(V,false);
         vector<int>ans;
        for(int i = 0 ; i < V;i++){
            if(!visited[i]) dfs(i,visited,adj,ans);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
