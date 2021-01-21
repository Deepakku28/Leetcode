class Solution {
public:
    string addFunction(string &str,int &a){
        for(int i=1;i<str.size();i+=2){
            int val=str[i]-'0';
            val=(val+a)%10;
            str[i]=val+'0';
        }
        return str;
    }
    
    string rotateFunction(string &str,int &b){
        int n=str.size();
        b=b%n;
        string val1=str.substr(0,n-b);
        string val2=str.substr(n-b);
        return val2+val1;
    }
    
    string findLexSmallestString(string str, int a, int b) {
        unordered_set<string> s;
        s.insert(str);
        queue<string> q;
        q.push(str);
        string ans=str;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            ans=min(ans,curr);
            string add=addFunction(curr,a);
            if(s.find(add)==s.end()){
                s.insert(add);
                q.push(add);
            }
            string rotate=rotateFunction(curr,b);
            if(s.find(rotate)==s.end()){
                s.insert(rotate);
                q.push(rotate);
            }
        }
        return ans;
    }
};
