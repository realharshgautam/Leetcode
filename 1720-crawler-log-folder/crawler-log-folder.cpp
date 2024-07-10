class Solution {
public:
    static int minOperations(vector<string>& logs) {
        int level=0;
        for(auto& dir: logs){
            if (dir=="../") 
                level-=(level>0);
            else if (dir!="./")
                level++;
        //    cout<<level<<endl;
        }
        return level;
    }
};







auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();