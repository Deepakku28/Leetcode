class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int total=0;
        for(int i=0;i<arr.size()-1;i++){
            int check=arr[i];
            for(int j=i+1;j<arr.size();j++){
                check=(check^arr[j]);
                if(check==0){
                    total=total+j-i;
                }
            }
        }
        return total;
    }
};
