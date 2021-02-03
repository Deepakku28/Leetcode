class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans=0;
        int count1=0;
        int count2=0;
        int n=light.size();
        for(int i=0;i<n;i++){
            count1+=light[i];
            count2+=i+1;
            if(count2>=count1){
                ans++;
            }
        }
        return ans;
    }
};
