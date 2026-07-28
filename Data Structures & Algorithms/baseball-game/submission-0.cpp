class Solution {
public:
    int calPoints(vector<string>& o) {
        int n = o.size();
        stack <int> s;
        for(int i{0}; i<n; i++){
            if(o[i]!="+" && o[i]!= "D" && o[i]!= "C"){
                int score = stoi(o[i]);
                s.push(score);
            }
            else if(o[i]=="C"){
                s.pop();
            }
            else if(o[i]=="D"){
                s.push(s.top()*2);
            }
            else if(o[i]=="+"){
                int temp = s.top();
                s.pop();
                int sum = temp + s.top();
                s.push(temp);
                s.push(sum);
            }
            else continue;
        }
        int T{0};
        while(!s.empty()){
            T += s.top();
            s.pop();
        }
        return T;
    }
};