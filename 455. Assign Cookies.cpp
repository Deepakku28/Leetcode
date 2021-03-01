class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int j=0;
        int i=0;
        int count=0;
        while(i<n && j<m){
            if(g[i]<=s[j]){
                i++;
                j++;
                count++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};
