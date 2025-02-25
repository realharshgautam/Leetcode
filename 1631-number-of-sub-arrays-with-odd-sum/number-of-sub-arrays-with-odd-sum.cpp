class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {    
      int odd=0,even=0,answer=0,modulus=(int)1e9+7;
        for(auto number:arr){
            if(number%2==0)even++;
            else{
                swap(odd,even);
                odd++;
            }
            answer=(answer%modulus+odd%modulus)%modulus;
        }
        return answer;
    }
};