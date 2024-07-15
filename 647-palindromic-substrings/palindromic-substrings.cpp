class Solution {
public:

    int expandaround(string s ,int i,int j){
        int count =0;
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {

        int n = s.length();
        int count =0;

        for(int i = 0; i<n;i++){
            int oddans = expandaround(s,i,i);
            int evenans = expandaround(s,i,i+1);
            count += oddans+evenans;
        }

        return count;
        
    }
};