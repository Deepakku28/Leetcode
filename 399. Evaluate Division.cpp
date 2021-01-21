class Solution {
public:
    
    double bfs(vector<string> a, map<string, vector<pair<string, double>>> m)
    {
        string s = a[0];
        string d = a[1];
        if(m.find(s) == m.end())
        {
            return -1.00000;
        }
        queue<pair<string, double> > q;
        q.push(make_pair(s, 1));
        map<string, bool> vis;
        
        vis[s] = true;
        
        while(!q.empty())
        {
            string c = q.front().first;
            double f = q.front().second;
            
            q.pop();
            
            if(c == d)
            {
                return f;
            }
            
            for(int i = 0; i < m[c].size(); i++)
            {
                
            string g = m[c][i].first;
            double k = m[c][i].second;
            
            if(!vis[g])
            {
                q.push(make_pair(g, f*k));
                vis[g] = true;
            }  
                
            }
        }
        
        return -1.00000;
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        map<string, vector<pair<string, double> > > m;
        
        for(int i = 0; i < n; i++)
        {
            string x = equations[i][0];
            string y = equations[i][1];
            double z = values[i];
            double l = 1/z;
            m[x].push_back(make_pair(y, z));
            m[y].push_back(make_pair(x, l));
            
        } 
        
        vector<double> ans;
        for(int i = 0; i < queries.size(); i++)
        {
            double temp = bfs(queries[i], m);
            ans.push_back(temp);
        }
        return ans;
    }
};
