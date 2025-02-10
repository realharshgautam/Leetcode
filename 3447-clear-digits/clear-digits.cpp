class Solution {
public:
    static string clearDigits(string& s) {
        int n=s.size(), j=0;
        for(int i=0; i<n; i++){
            if (isdigit(s[i]) && j>0) j--;
            else  s[j++]=s[i]; 
        }
        s.resize(j);
        return s;
    }
};