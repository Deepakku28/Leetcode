class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0;
        int n=seats.size();
        int prevOneIndex=-1;
        for(int currIndex=0;currIndex<n;currIndex++){
            if(seats[currIndex]==1){
                ans=((prevOneIndex<0)?currIndex:max(ans,(currIndex-prevOneIndex)/2));
                prevOneIndex=currIndex;
            }
        }
        ans=max(ans,n-prevOneIndex-1);
        return ans;
    }
};
