class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n=A.size();
        unordered_set<int> s(A.begin(),A.end());
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int start=A[j];
                int end=A[i];
                int val=start+end;
                int len=2;
                while(s.find(val)!=s.end()){
                    len++;
                    start=end;
                    end=val;
                    val=start+end;
                }
                if(len>2){
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};
