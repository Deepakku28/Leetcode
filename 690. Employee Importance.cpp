/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    void dfs(int id,int &sum,map<int,Employee*> &mp){
        sum+=mp[id]->importance;
        for(auto it:mp[id]->subordinates){
            dfs(it,sum,mp);
        }
    }

    int getImportance(vector<Employee*> employees, int id){
        map<int,Employee*> mp;
        for(auto it:employees){
            mp[it->id]=it;
        }
        int sum=0;
        dfs(id,sum,mp);
        return sum;
    }
};
