class Solution {
public:
    float myAtoi(string str) {
        int len = str.length();
        if (len ==0) {
            return 0;
        }
        int i =0;
        // Find the occurance of the first digit or sign
        for (i=0; i<len; i++) {
            if (str[i] ==' ' && str[i] != '-' && str[i] != '+' && str[i] != '.') {
                continue;
            } else if (str[i] == '-' || str[i] == '+' ) {
                if ((str[i+1] > '/' && str[i+1] < ':') || str[i+1] == '.') {
                    break;
                } else {
                    return 0;
                }
            } else if ((str[i] <'0' || str[i] >'9') && str[i] != '.')  {
                return 0;
            } else {
                break;
            }
        }
        int val1=0, val2=0,  flag=0;
        float count=0.0f;
        int sign =1;
        float result=0.0f;
        //sign calculation
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+'){
            i++;
        }
        
        while (i<len){
            if (str[i] == '.'){
                if (flag==0) flag++;
                else {
                    result = (float)val1 + ((float) val2/(float)pow(10,count));
                    return (result * sign);
                }
                i++;
            }
            else if (str[i] > 47 && str[i] < 58) {
                if (flag ==0){
                // If the calculated number is greater than integer max return max values based on sign
                long temp =  ( (long) val1*10) +  (str[i] - '0');
                if (temp > INT_MAX) {
                    return (sign == 1 ? INT_MAX : INT_MIN);
                } else {
                    val1 = (int)temp ;
                    i++;
                }
                }
                else if(flag ==1){
                    val2 = val2*10 +  (str[i] - '0');
                    count++;
                    i++;
                }
            } else {
                  result = (float)val1 + ((float) val2/(float)pow(10,count));
                return (result * sign);
            }
        }
        result = (float)val1 + ((float) val2/(float)pow(10,count));
        return (result * sign);
    }
};

