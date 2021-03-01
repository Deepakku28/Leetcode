class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<A.size();i++){
            pq.push(A[i]);
        }
        for(int i=0;i<K;i++){
            int val=pq.top();
            pq.pop();
            pq.push(-1*val);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
