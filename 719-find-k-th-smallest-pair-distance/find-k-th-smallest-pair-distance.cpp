class Solution {
public:
    static int cntPairs(int x, vector<int>& nums){//sliding window
        const int n=nums.size();
        int cnt=0;
        for(int l=0, r=1; r<n; r++){
            while(r>l && nums[r]-nums[l]>x)
                l++;
            cnt+=r-l;
        }
        return cnt;
    }

    static int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int M=nums.back();
        
        //Binary search
        int l=0, r=M, m;
        while(l<r){
            m=(r+l)/2;
            if (cntPairs(m, nums)<k)
                l=m+1;
            else r=m;
        }
        return l;
    }
};


 
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();