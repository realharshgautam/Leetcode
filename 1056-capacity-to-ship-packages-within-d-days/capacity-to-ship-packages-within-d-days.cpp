class Solution {
public:
int max(vector<int>&weights){
    int ans=INT_MIN;
    for(int i=0;i<weights.size();i++){
        if(weights[i]>ans){
            ans=weights[i];
        }
    }
    return ans;
    }
    int sum(vector<int>& weights){
        int add=0;
        for(int i=0;i<weights.size();i++){
            add+=weights[i];
        }
        return add;
    }
    int func(vector<int>&weights,int mid){
        int sum=0,count=1;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                count++;
               sum=weights[i];
            }else{
                sum+=weights[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=max(weights);
        int high=sum(weights),ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int req=func(weights,mid);
            if(req<=days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};