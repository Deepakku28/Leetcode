class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(candyType[i]);
        }
        int val=min(n/2,(int)s.size());
        return val;
    }
};
