class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
 
        
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        
        for(auto it :st){
            if(st.find(it-1)== st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    x++;
                    cnt++;
                }
            longest = max(cnt,longest);
            }
        }
       return longest; 
    }
};