class Solution {
public:

    bool isVowel(char ch){
        ch = tolower(ch);
        char arr[5] = {'a','e','i','o','u'};
        for(int i =0; i<5; i++){
            if(arr[i]==ch)return true;
        }
        return false;

    }
    string reverseVowels(string s) {

        int i =0, j=s.size()-1;
        while(i<j){
            if(isVowel(s[i])&&isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(isVowel(s[i])==0){
                i++;
            }
            else
            j--;

        }
        return s;
    }
};