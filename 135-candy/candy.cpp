class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        int sum = 1, up = 0, down = 0, peak = 0; 

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {  // Increasing sequence
                up++;
                peak = up;
                down = 0;
                sum += up + 1;
            } 
            else if (ratings[i] < ratings[i - 1]) {  // Decreasing sequence
                down++;
                up = 0;
                sum += down;
                if (down > peak) sum++;  // Extra candy needed if decreasing part is longer
            } 
            else {  // Equal ratings
                up = down = peak = 0;
                sum += 1;
            }
        }
        
        return sum;
    }
};
