class Solution{
  public:
    int lengthOfLongestSubstring(string& s){
        int n = s.size();

        int hash[256];
        for(int i =0; i<256; i++){
            hash[i]=-1;
        }
        int l =0, r=0, maxLen=0;
        while (r<n){
            if(hash[s[r]]!=-1){
                l=max(hash[s[r]]+1,l);
            }
            int len = r-l+1;
            maxLen = max(len,maxLen);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};