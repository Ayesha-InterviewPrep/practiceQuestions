class Solution {
public:
    int climbStairs(int n) {
        stack <int> climbs_for_stack_index;
        if(1==n) return (1);
        else if (2==n) return (2);
        int var_n_1=0, var_n_2=0;
        for (int i=0; i<n; i++){
            //push initial step values 
            if (0==i) climbs_for_stack_index.push(0);
            else if(1==i) climbs_for_stack_index.push(1);
            else if (2==i) climbs_for_stack_index.push(2);
            //For the climbs greater than two the result is = f(n-1) +f(n-2)
            else if (i>2){
                //pop index accordingly and add 
                var_n_1 = climbs_for_stack_index.top();
                climbs_for_stack_index.pop();
                var_n_2 = climbs_for_stack_index.top();
                climbs_for_stack_index.pop();
                //push in the right order after the pop
                climbs_for_stack_index.push(var_n_2);
                climbs_for_stack_index.push(var_n_1);
                climbs_for_stack_index.push(var_n_1+var_n_2);
            }
        }
        
        var_n_1 = climbs_for_stack_index.top();
        climbs_for_stack_index.pop();
        var_n_2 = climbs_for_stack_index.top();
        climbs_for_stack_index.pop();
        return (var_n_1+var_n_2);
    }
    
};
