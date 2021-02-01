class Solution {
public:
    void helper(string &s,int start,vector<string> &curr,vector<string> &ans){
        if(start==s.size() && curr.size()==4){
            string temp="";
            int i=0;
            for(auto it:curr){
                if(i==0){
                    temp+=it;
                    i++;
                }
                else{
                    temp+=("."+it);
                }
            }
            ans.push_back(temp);
            return ;
        }
        if(start>s.size() || curr.size()>4){
            return ;
        }
        for(int i=1;i<=3 && start+i<=s.size();i++){
            string temp=s.substr(start,i);
            int val=stoi(temp);
            string str=to_string(val);
            if(val<=255 && temp.size()==str.size()){
                curr.push_back(temp);
                helper(s,start+i,curr,ans);
                curr.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 || s.size()>12){
            return {};
        }
        vector<string> ans,curr;
        helper(s,0,curr,ans);
        return ans;
    }
};
