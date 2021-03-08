class Solution {
private:
    struct info{
        int height;
        int row;
        int col;
        info(int a,int b,int c){
            height=a;
            row=b;
            col=c;
        }
    };
    
    struct mycompare{
        bool operator()(const info &a,const info &b){
            return (a.height>b.height);
        }
    };
    
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
public:
    int helper(vector<vector<int>> &forest,info &tree1,info &tree2,int &n,int &m){
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[tree1.row][tree1.col]=1;
        queue<info> q;
        q.push(tree1);
        int steps=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                info curr=q.front();
                q.pop();
                if(curr.row==tree2.row && curr.col==tree2.col){
                    forest[tree2.row][tree2.col]=1;
                    return steps;
                }
                for(int k=0;k<4;k++){
                    int x=curr.row+dir[k][0];
                    int y=curr.col+dir[k][1];
                    if(x<0 || x>=n || y<0 || y>=m || visited[x][y]==1 || forest[x][y]==0){
                        continue;
                    }
                    visited[x][y]=1;
                    q.push(info(forest[x][y],x,y));
                }
            }
            steps++;
        }
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        priority_queue<info,vector<info>,mycompare> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1){
                    pq.push(info(forest[i][j],i,j));
                }
            }
        }
        
        info tree1(1,0,0);
        int ans=0;
        while(!pq.empty()){
            info tree2=pq.top();
            pq.pop();
            int dist=helper(forest,tree1,tree2,n,m);
            if(dist==-1){
                return -1;
            }
            ans+=dist;
            tree1=tree2;
        }
        return ans;
    }
};
