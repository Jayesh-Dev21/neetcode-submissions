class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i{0}; i<strs.size(); i++){
            for(auto a : strs[i]){
                res += static_cast<char>(a ^ 0x20);
            }
            res += static_cast<char>('\0' ^ 0x20);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>strs;
        string temp{""};
        for (auto a: s){
            auto m = static_cast<char>(a^0x20);
            if(m!='\0'){
                temp += m;
            }
            else{
                // temp += m;
                strs.push_back(temp);
                temp = "";
            }
        }
        return strs;
    }
};
