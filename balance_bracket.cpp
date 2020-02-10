class Solution {
public:
    bool isValid(string s) {
        stack <char> brackets;
        int len  = s.size();
        if (len == 0)    return true;
        else if (len ==1)  return false;
        char temp;
        for(int i =0; i<len; i++){
            if (s[i] == ')' || s[i] == ']' || s[i] == '}' ){
                if(i==0) return false;
                //comparisons for the same type of bracket after the pop
                else if (!brackets.empty()){
                   temp = brackets.top();
                   brackets.pop();
                   if (s[i] == ')' && temp == '(') {
                       continue; }
                   else if (s[i] == '}' && temp == '{') {
                       continue;  }
                   else if  (s[i] == ']' && temp == '[') {
                       continue; }
                   else {
                       return false; }
                }
                //to check if the stack is empty
                else if (brackets.empty()){
                    return false;
                }
            }
          else if (s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                   brackets.push(s[i]); 
                }
            
        }
         if (!brackets.empty()) {
                return false; }
          else{
                return true; }
    }
};
