class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> outDegree(N+1,0);
        vector<int> inDegree(N+1,0);
        for(auto it:trust){
            outDegree[it[0]]++;
            inDegree[it[1]]++;
        }
        for(int i=1;i<=N;i++){
            if(outDegree[i]==0 && inDegree[i]==N-1){
                return i;
            }
        }
        return -1;
    }
};
