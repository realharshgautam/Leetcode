class Solution {
public:
    // Function to check the count of consecutive characters within a range
    int checkCnt(int idx, int k, vector<int>& cnts){
        int ans = 0, cnt=0;
        int currIdx = idx;
        // Count consecutive characters to the left
        while(currIdx >= 0 && cnt<=k){
            ans = max(ans, cnts[currIdx]);
            currIdx--;
            cnt++;
        }
        currIdx = idx;
        cnt = 0;
        // Count consecutive characters to the right
        while(currIdx<26 && cnt<=k){
            ans = max(ans, cnts[currIdx]);
            currIdx++;
            cnt++;
        }
        return ans;
    }

    // Function to find the length of the longest "ideal" string
    int longestIdealString(string s, int k) {
        // Array to store the count of characters
        vector<int> cnts(26, 0);
        int ans = 0;
        // Iterate through the string
        for(int i=0; i<s.size(); i++){
            int idx = s[i]-'a';
            // Update count of current character based on surrounding characters
            cnts[idx] = checkCnt(idx, k, cnts)+1;
        }
        // Find the maximum count in the count array
        for(int i=0; i<cnts.size(); i++){
            ans = max(ans, cnts[i]);
        }
        return ans;
    }
};