class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        if (tokens.size() < 1) 
            return -1;
        
        stack<int> mystack;
        int i = 0;
        while (i < tokens.size()) {
            if (tokens[i] == "+") {
                int op2 = mystack.top();
                mystack.pop();
                int op1 = mystack.top();
                mystack.pop();
                mystack.push(op1 + op2);
            } else if (tokens[i] == "-") {
                int op2 = mystack.top();
                mystack.pop();
                int op1 = mystack.top();
                mystack.pop();
                mystack.push(op1 - op2);
            } else if (tokens[i] == "*") {
                int op2 = mystack.top();
                mystack.pop();
                int op1 = mystack.top();
                mystack.pop();
                mystack.push(op1 * op2);
            } else if (tokens[i] == "/") {
                int op2 = mystack.top();
                mystack.pop();
                int op1 = mystack.top();
                mystack.pop();
                mystack.push(op1/op2);
                
            } else {
                mystack.push(stoi(tokens[i]));
            }
            i++;
        }
        
        return mystack.top();
    }
};
