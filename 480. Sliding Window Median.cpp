class Solution {
public:
    double calMedian(double val1, double val2, multiset<int> &s){
        s.insert(val1);
        s.erase(s.find(val2));
        int n=s.size();
        double med1=*next(s.begin(),n/2-1);
        double med2=*next(s.begin(),n/2);
        if(n%2==1){
            return med2;
        }
        else{
            return ((med1+med2)/2);
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> s;
        for(int i=0;i<k;i++){
            s.insert(nums[i]);
        }
        vector<double> ans;
        double med1=*next(s.begin(),k/2-1);
        double med2=*next(s.begin(),k/2);
        if(k%2==1){
            ans.push_back(med2);
        }
        else{
            double med=((med1+med2)/2);
            ans.push_back(med);
        }
        for(int i=k;i<n;i++){
            ans.push_back(calMedian(nums[i],nums[i-k],s));
        }
        return ans;
    }
};
