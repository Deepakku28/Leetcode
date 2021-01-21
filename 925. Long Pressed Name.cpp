class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m=name.size();
        int n=typed.size();
        int i=0,j=0;
        while(i<m){
            if(name[i]!=typed[j]){
                return false;
            }
            i++;
            j++;
            if(name[i]!=name[i-1]){
                while(typed[j]==typed[j-1]){
                    j++;
                }
            }
        }
        while(j<n && typed[j]==typed[j-1]){
            j++;
        }
        return (i==m && j==n);
    }
};
