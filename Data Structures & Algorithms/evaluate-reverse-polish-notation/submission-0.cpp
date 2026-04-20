class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(string c: tokens) {
            int num1, num2, res;
            if(c == "+" || c == "-" || c == "*" || c == "/") {
                num1 = stk.top(); stk.pop();
                num2 = stk.top(); stk.pop();

                switch(c[0]) {
                    case '+':
                        res = num1 + num2;
                        break;
                    case '-':
                        res = num2 - num1;
                        break;
                    case '*':
                        res = num1 * num2;
                        break;
                    case '/':
                        res = num2 / num1;
                        break;
                }
                stk.push(res);
            } else { 
                stk.push(stoi(c));
            }
        }
        return stk.top();
    }
};
