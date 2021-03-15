class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> val;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                val.pop_back();
            }
            else if(ops[i]=="D"){
                val.push_back(2*val.back());
            }
            else if(ops[i]=="+"){
                int val1=val.back();
                val.pop_back();
                int val2=val.back();
                val.push_back(val1);
                val.push_back(val1+val2);
            }
            else{
                val.push_back(stoi(ops[i]));
            }
        }
        int sum=accumulate(val.begin(),val.end(),0);
        return sum;
    }
};
