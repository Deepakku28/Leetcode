class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int cycle=0;
        vector<int> firstCell,nextCell(cells.size(),0);
        while(N-->0){
            for(int i=1;i<cells.size()-1;i++){
                nextCell[i]=cells[i-1]==cells[i+1]?1:0;
            }
            if(cycle==0){
                firstCell=nextCell;
            }
            else if(nextCell==firstCell){
                N=N%cycle;
            }
            cells=nextCell;
            cycle++;
        }
        return cells;
    }
};
