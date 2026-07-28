class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        if(s.size()%2!=0) return 0;
        for(auto c:s){
            
            if(c=='{' || c=='[' || c=='(') ss.push(c);
            else{
                // if(c==')' && ss.peak()=='(') ss.pop();
                // else return false;
                // if
                if(ss.empty()) return false;
                auto g = ss.top();
                switch(c){
                    case ')':
                        if(g!='(') return false;
                        else ss.pop();
                        break;
                    case '}':
                        if(g!='{') return false;
                        else ss.pop();
                        break;
                    case ']':
                        if(g!='[') return false;
                        else ss.pop();
                        break;
                    default:
                        break;
                }
            }
        }
        return true;
    }
};
