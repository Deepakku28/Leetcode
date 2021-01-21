class Solution {
public:
    static bool comp(int a,int b){
        int len_a=(__builtin_popcount(a));
        int len_b=(__builtin_popcount(b));
        if(len_a==len_b){
            return a<b;
        }
        return len_a<len_b;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};
