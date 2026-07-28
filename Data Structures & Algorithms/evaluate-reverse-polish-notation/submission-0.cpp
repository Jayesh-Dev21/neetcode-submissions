class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        
        for (auto ss : t) {
            if (ss.size() == 1) {
                int a, b;
                switch (ss[0]) {
                    case '+':
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        s.push(b + a); 
                        continue;     
                    case '*':
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        s.push(b * a); 
                        continue;
                    case '-':
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        s.push(b - a); 
                        continue;
                    case '/':
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        s.push(b / a); 
                        continue;
                }
            }
            int x = stoi(ss);
            s.push(x);
        }

        return s.top();
    }
};
