class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> val(n,0);
        val[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                val[i]=val[i-1]+1;
            }
            else{
                val[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                val[i]=max(val[i],val[i+1]+1);
            }
        }
        int sum=accumulate(val.begin(),val.end(),0);
        return sum;
    }
};
