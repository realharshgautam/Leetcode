class Solution {
public:
    int n;
    vector<int> degreein;
    vector< vector<int> > rGraph;
    vector<int> ans;
    
    void init(vector<vector<int>>& G){
        n = G.size();
        degreein = vector<int>(n,0);
        rGraph.resize(n, vector<int>(0) );
        
        for (int u=0; u<n; u++){
            for (int v:G[u]){
                rGraph[v].push_back(u);
                degreein[u]++;
            }
        }
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        init(graph);
        queue<int> que;
        for (int i=0; i<n; i++){
            if (degreein[i]==0) que.push(i);
        }
        while (que.size()){
            int u = que.front(); que.pop();
            ans.push_back(u);
            for (int v:rGraph[u]){
                degreein[v]--;
                if (degreein[v]==0) que.push(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};