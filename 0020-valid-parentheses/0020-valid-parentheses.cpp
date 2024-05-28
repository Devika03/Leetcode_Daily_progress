class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>stack;
        for(char c : s)
        {
            if(c == '(' || c == '[' || c == '{' )
            {
                stack.push(c);
            }
            else 
            {
                if(stack.empty()) return false;
                
                char stack_top_Ele = stack.top();
                if(c == ')' && stack_top_Ele == '(' || c == ']' && stack_top_Ele == '[' || c == '}' && stack_top_Ele == '{' ) stack.pop();
                else return false;                
            }
                   
        }
        return stack.empty();
    }
        
};
















/*
{stack<char> s;
        for (char c : s) //Iterating through string. 
        {
            if (c == '(' || c == '{' || c == '[') s.push(c);
            else 
            {
                if (stk.empty()) 
                {
                    return false; //It means it does not have an opp. bracket
                }
                //If it does have an opp. bracket then 3 cases - 
                if (c == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (c == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (c == ']' && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
    */