class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;

        //step 1 : convert hours strings to minutes integer
        for(int i=0; i<timePoints.size();i++){
            string curr = timePoints[i];
            int hours = stoi(curr.substr(0,2));
            int mins = stoi(curr.substr(3,2));
            int totalMin = 60 * hours + mins ;
            minutes.push_back(totalMin);
        }

        // step 2: sort
        sort(minutes.begin(),minutes.end());

        //caluclate diff

       int n = minutes.size();
        int mini = INT_MAX;

        for(int i; i<n-1;i++){
            int diff = minutes[i+1]-minutes[i];
            mini = min(mini, diff);
        }

        //round difference

        int lastdiff = minutes[0]+1440 - minutes[n-1];
        mini = min(mini, lastdiff);
    
    return mini;
    }
};