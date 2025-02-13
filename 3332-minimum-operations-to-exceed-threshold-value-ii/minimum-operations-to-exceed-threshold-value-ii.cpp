class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(auto n : nums) pq.push(n); 
    int count = 0;
    for(;pq.top() < k; ++count){
        long minNum = pq.top();       pq.pop();
        pq.push(2*minNum + pq.top()); pq.pop();
    }
    return count;
}
};