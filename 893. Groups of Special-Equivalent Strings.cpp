class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int n=A.size();
        unordered_set<string> s;
        for(int i=0;i<n;i++){
            string odd="";
            string even="";
            for(int j=0;j<A[i].size();j++){
                if(j%2==0)
                    even+=A[i][j];
                else
                    odd+=A[i][j];
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            s.insert(even+odd);
            
        }
        return s.size();
    }
};
