class Solution {
public:
    bool solution(string src,string dest){
        int m=src.size();
        int n=dest.size();
        int srcStart=0;
        int destStart=0;
        while(srcStart<m && destStart<n){
            char srcChar=src[srcStart];
            char destChar=dest[destStart];
            if(srcChar!=destChar){
                return false;
            }
            int srcCount=0;
            int destCount=0;
            while(srcStart<m && srcChar==src[srcStart]){
                srcStart++;
                srcCount++;
            }
            while(destStart<n && destChar==dest[destStart]){
                destStart++;
                destCount++;
            }
            if(srcCount!=destCount && (srcCount>destCount || destCount<3)){
                return false;
            }
        }
        return ((srcStart==m && destStart==n)?true:false);
    }
    
    int expressiveWords(string S, vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(solution(words[i],S)){
                count++;
            }
        }
        return count;
    }
};
