class Solution {
public:
    void helper(string tiles,int &count,int start,int &end){
        count++;
        for(int i=start;i<=end;i++){
            if(i!=start && tiles[i]==tiles[start]){
                continue;
            }
            swap(tiles[i],tiles[start]);
            helper(tiles,count,start+1,end);
        }
    }
    
    int numTilePossibilities(string tiles) {
        int count=0;
        int n=tiles.size()-1;
        sort(tiles.begin(),tiles.end());
        helper(tiles,count,0,n);
        return count-1;
    }
};
