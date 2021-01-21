class Solution {
public:
    int findComplement(int num) {
        unsigned int mask=1;
        unsigned int bitCount=floor(log2(num))+1;
        mask=(mask<<bitCount)-1;
        return (mask^num);
    }
};
