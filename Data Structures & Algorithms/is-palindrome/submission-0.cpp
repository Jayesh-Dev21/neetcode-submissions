class Solution {
public:
    bool isPalindrome(string s) {
       bool isPal{1};
    //    for(int i{0}; i<s.size()/2; i++){
    //     if(s[i]!=s[s.size()-1-i]) return 0;
    //    }
    //    return isPal;
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(!isalnum(s[l])){
                l++;
            }
            else if(!isalnum(s[r])){
                r--;
            }
            else if(tolower(s[l]) != tolower(s[r])){
                return 0;
            }
            else{
                l++;
                r--;
            }
        }
        return isPal;
    }
};
