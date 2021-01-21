class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0,left=0,right=height.size()-1;
        int min_height=0;
        while(left<right){
            min_height=min(height[left],height[right]);
            max_area=max(max_area,(min_height*(right-left)));
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};
