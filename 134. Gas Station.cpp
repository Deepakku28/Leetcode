class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int temp=0;
        int total=0;
        int index=0;
        for(int i=0;i<n;i++){
            int curr=gas[i]-cost[i];
            temp+=curr;
            total+=curr;
            if(temp<0){
                temp=0;
                index=i+1;
            }
        }
        return total<0?-1:index;
    }
};
