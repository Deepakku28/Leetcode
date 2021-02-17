struct compare{
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        if(a.first<b.first){
            return true;
        }
        if(a.first==b.first){
            return a.second<b.second;
        }
        return false;
    }
};

class Solution {
public:
    int calculateNoOfSoilders(vector<int> &val){
        int left=0;
        int right=val.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(val[mid]==0){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<m;i++){
            pq.push({calculateNoOfSoilders(mat[i]),i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
