class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string,vector<string>> graph;
        int n = rec.size();
        unordered_set<string> s;
        for(auto x : sup) s.insert(x);            //store all the supplies in unordered set
		
        unordered_map<string,int> indegree;   //to store the indegree of all recipes
        for(auto x : rec)indegree[x] = 0;                      //initially take the indegree of all recipes to be 0
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int)ing[i].size(); j++){
                if(s.find(ing[i][j]) == s.end()){     
                    graph[ing[i][j]].push_back(rec[i]);    //if the ingredient required to make a recipe is not in supplies then  
                    indegree[rec[i]]++;                     //we need to make a directed edge from that ingredient to recipe
                }
            }
        }
        
        //KAHN'S ALGORITHM
        queue<string> q;
        for(auto x : indegree){
            if(x.second == 0){
                q.push(x.first);
            }
        }
       vector<string> ans;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto nbr : graph[tmp]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return ans;
    }
};