class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack <int> operands;
        int var1=0, var2=0;
        for (int i=0;i<tokens.size();i++){
            //Locating operators in the string provided
            if (tokens.at(i) =="+" || tokens.at(i) =="-"||tokens.at(i) =="*"||tokens.at(i) =="/"){
                if (i ==0)
                    continue;
                //Popping the operands to perform the operation
                else if (operands.size() > 1){
                    var1 = operands.top();
                    operands.pop();
                    var2 = operands.top();
                    operands.pop();
                }
                if (tokens.at(i) =="+") operands.push(var1+var2);
                else if (tokens.at(i) =="*") operands.push(var1*var2);
                else if (tokens.at(i) =="/") operands.push(var2/var1);
                else operands.push(((-1)*var1)+var2);
            }
            else {
                //Converting string into interger
                const char * temp = tokens.at(i).c_str();
                int val = atoi(temp);
                operands.push(val);
            }
        }
        
        if (operands.size() == 1){
            return operands.top();
        }
        else return -111;
            
        }
    };
