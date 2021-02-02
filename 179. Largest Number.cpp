class Solution {
public:
    const static bool compare(string &a,string &b){
        return a+b>b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(to_string(nums[i]));
        }
        sort(ans.begin(),ans.end(),compare);
        string str="";
        for(int i=0;i<ans.size();i++){
            str+=ans[i];
        }
        
        return str[0]=='0'?"0":str;
    }
};
