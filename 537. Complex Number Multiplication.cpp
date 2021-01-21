class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int pos=a.find('+');
        int m=a.size();
        string firstReal=a.substr(0,pos);
        string firstImaginary=a.substr(pos+1,m-1);
        
        pos=b.find('+');
        int n=b.size();
        string secondReal=b.substr(0,pos);
        string secondImaginary=b.substr(pos+1,n-1);
        
        int real=((stoi(firstReal)*stoi(secondReal))-(stoi(firstImaginary)*stoi(secondImaginary)));
        int imaginary=((stoi(firstReal)*stoi(secondImaginary))+(stoi(firstImaginary)*stoi(secondReal)));
        
        return to_string(real)+"+"+to_string(imaginary)+"i";
    }
};
