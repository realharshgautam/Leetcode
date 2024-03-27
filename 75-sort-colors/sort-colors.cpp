class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        //count method
//         class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//      int zero=count(nums.begin(),nums.end(),0);
//       int one=count(nums.begin(),nums.end(),1);
//       int two=count(nums.begin(),nums.end(),2); 
//       for(int i=0;i<zero;i++){
//         nums[i]=0;
//       }
//       for(int i=zero;i<zero+one;i++){
//         nums[i]=1;
//       } 
//       for(int i=zero+one;i<zero+one+two;i++){
//         nums[i]=2;
//       }  
//     }
// };
int l=0,m=0,h=nums.size()-1;
while(m<=h){
    if(nums[m]==0){
        swap(nums[l],nums[m]);
        l++,m++;
    }
    else if(nums[m]==1)
    {
        m++;
    }

    else
    {
        swap(nums[h],nums[m]);
        h--;
        
    }
}

}
};