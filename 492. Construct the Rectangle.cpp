class Solution {
public:
    vector<int> constructRectangle(int area) {
        int len=sqrt(area);
        for(int width=len;width>0;width--){
            if(area%width==0){
                return {area/width,width};
            }
        }
        return {area,1};
    }
};
