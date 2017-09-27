class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        if (tokens.size() < 1) 
            return -1;
        
        int i = 0;
        vector<string>::iterator it;
        string newstr;
        while (i < tokens.size()) {
            bool executed = true;
            if (tokens[i] == "+") {
                newstr = to_string(stoi(tokens[i-2]) + stoi(tokens[i-1]));
            } else if (tokens[i] == "-") {
                newstr = to_string(stoi(tokens[i-2]) - stoi(tokens[i-1]));
            } else if (tokens[i] == "*") {
                newstr = to_string(stoi(tokens[i-2]) * stoi(tokens[i-1]));
            } else if (tokens[i] == "/") {
                newstr = to_string(stoi(tokens[i-2]) / stoi(tokens[i-1]));
            } else {
                executed = false;
                i++;
            }
            
            if (executed) {
                it = tokens.begin() + i - 2; 
                tokens.erase(it, it + 3);
                tokens.insert(it, newstr);
                i = i - 2;
            }
        }
        
        return stoi(tokens[0]);
    }
};
