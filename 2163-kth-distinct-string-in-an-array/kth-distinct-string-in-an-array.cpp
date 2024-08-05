// struct Trie for N alphabets
const int N=26;
struct Trie {
    Trie* next[N];
    int count=0;

    Trie() {
    //    cout<<"Create a trie object!\n";
        memset(next, 0, sizeof(next));
    }

    void insert(string& s) {
        Trie* Node=this;
        for(char c: s){
            int i=c-'a';
            if (Node->next[i]==NULL) Node->next[i]=new Trie();
            Node=Node->next[i];
        }
        Node->count++;
    }
    bool findcnt1(string& s) {
        Trie* Node=this;
        for(char c: s){
            int i=c-'a';
            if (Node->next[i]==NULL) return 0;
            Node=Node->next[i];
        }
        return Node->count==1;
    }
};


class Solution {
public:
    static string kthDistinct(vector<string>& arr, int k) {
        Trie trie;
        for(string& s: arr)
            trie.insert(s);

        for(string& s: arr){
            if (trie.findcnt1(s)==1) k--;
            if (k==0)  return s;
        }
        return "";  
    }
};
