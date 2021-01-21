class Solution {
public:
    bool isPerfectSquare(int num) {
        return (sqrt(num)==floor(sqrt(num)));
    }
};
