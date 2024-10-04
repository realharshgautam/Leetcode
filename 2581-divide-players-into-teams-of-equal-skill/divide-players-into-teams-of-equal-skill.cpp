class Solution {
public:
    static long long dividePlayers(vector<int>& skill) {
        const int n=skill.size(), n_2=n/2;
        long long sum=0;
        int freq[1001]={0}, xMax=1, xMin=1000;
        for(int x: skill){
            sum+=x;
            freq[x]++;
            xMax=max(x, xMax);
            xMin=min(x, xMin);
        }
        if (sum%n_2!=0) return -1;
        int team_skill=sum/n_2;
        
        long long chemi=0;
        int l, r;
        for(l=xMin, r=xMax; l<r; l++, r--){
            long long fL=freq[l], fR=freq[r];
            if (l+r!=team_skill || fL!=fR) return -1;
            chemi+=fL*l*r;
        }
        chemi+=(l==r && l*2==team_skill)?freq[l]/2LL*l*l:0LL;

        return chemi;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();