class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;
        int i=0;
        while(i<n){
            if(ans.empty() || asteroids[i]>0){
                ans.push_back(asteroids[i]);
                i++;
            }
            else{
                if(ans.empty() || ans.back()<0){
                    ans.push_back(asteroids[i]);
                    i++;
                }
                else{
                    if(ans.back()>0 && asteroids[i]<0 && abs(ans.back())==abs(asteroids[i])){
                        ans.pop_back();
                        i++;
                    }
                    else if(ans.back()>0 && asteroids[i]<0 && abs(ans.back())>abs(asteroids[i])){
                        i++;
                    }
                    else if(ans.back()>0 && asteroids[i]<0 && abs(ans.back())<abs(asteroids[i])){
                        ans.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};
