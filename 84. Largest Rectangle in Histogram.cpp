class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len =heights.size();
        stack<int> s;
        int max_area=0;
        int curr_area=0;
        int i=0;
        int curr_top=0;
        while(i<len){
            if(s.empty()){
                s.push(i);
                i++;
            }
            else if(heights[s.top()]<=heights[i]){
                s.push(i);
                i++;
            }
            else{
                curr_top=s.top();
                s.pop();
                if(s.empty()){
                    curr_area=heights[curr_top]*i;
                }
                else{
                    curr_area=heights[curr_top]*(i-s.top()-1);
                }
                if(curr_area>max_area){
                    max_area=curr_area;
                }
            }
        }
        while(!s.empty()){
            curr_top=s.top();
            s.pop();
            if(s.empty()){
                curr_area=heights[curr_top]*i;
            }
            else{
                curr_area=heights[curr_top]*(i-s.top()-1);
            }
            if(curr_area>max_area){
                max_area=curr_area;
            }
        }
        return max_area;
    }
};
