class Solution {
public:
    vector<double> combine(double a, double b) {
        return {a / b, b / a, a + b, a - b, b - a, a * b};
    }
    
    bool helper(vector<double> &arr){
        if(arr.size()==1){
            return (abs(arr[0]-24)<((double)(1e-4)));
        }
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                vector<double> newArr(arr.size()-1);
                for(int k=0,index=0;k<arr.size();k++){
                    if(k!=i && k!=j){
                        newArr[index++]=arr[k];
                    }
                }
                for(auto it:combine(arr[i],arr[j])){
                    newArr[newArr.size()-1]=it;
                    if(helper(newArr)==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr;
        for(auto it:nums){
            arr.push_back(it*1.0);
        }
        return helper(arr);
    }
};
