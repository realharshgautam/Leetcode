class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // An array to store the converted numbers
        vector<string> v;
        
        // Converting all the numbers into string format and storing in the array
        for(int i: nums){
            v.push_back(to_string(i));
        }
        
        // Custom Sorting based on the biggest of 2 when concatenated.
        sort(v.begin(), v.end(), [&](string a,  string b) {
            return a+b > b+a;
        });
        
        // result string to store the results
        string result = "";
        for(string c: v){
            result+=c;
        }
        
        // Checking if the result is 0
        if(result[0] == '0') return "0";
        
        // returning the result.
        return result;
    }
};