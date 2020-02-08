class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        if (len ==0) {
            return 0;
        }
        int i =0;
        // Find the occurance of the first digit or sign
        for (i=0; i<len; i++) {
            if (str[i] ==' ' && str[i] != '-' && str[i] != '+' ) {
                continue;
            } else if (str[i] == '-' || str[i] == '+' ) {
                if (str[i+1] > '/' && str[i+1] < ':') {
                    break;
                } else {
                    return 0;
                }
            } else if (str[i] <'0' || str[i] >'9')  {
                return 0;
            } else {
                break;
            }
        }
        int val=0;
        int sign =1;
        
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+'){
            i++;
        }
        
        while (i<len){
            if (str[i] > 47 && str[i] < 58) {
                // If the calculated number is greater than integer max return max values based on sign
                long temp =  ( (long) val*10) +  (str[i] - '0');
                if (temp > INT_MAX) {
                    return (sign == 1 ? INT_MAX : INT_MIN);
                } else {
                    val = (int)temp ;
                    i++;
                }
            } else {
                return (val * sign);
            }
        }
        return (val * sign);
    }
};

