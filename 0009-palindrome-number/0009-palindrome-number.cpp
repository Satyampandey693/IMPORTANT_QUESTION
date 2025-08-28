class Solution {
public:
    bool isPalindrome(int x) {
        string p=to_string(x);
        string q=p;
        reverse(p.begin(),p.end());
        return p==q;
    }
};