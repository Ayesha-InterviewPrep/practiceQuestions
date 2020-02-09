class Solution {
public:
    string addStrings(string num1, string num2) {
        
        char * result ;
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 == 0) {
            return len2==0? "0\0":num2;
        }
        else if (len2 == 0) {
            return len1==0? "0\0":num1;
        }
        int carry =0, sum=0;
        int result_len = len1>len2 ? len1: len2;
        result = (char *) malloc((result_len+1)*sizeof(char));
        result[result_len]='\0';
        while(len1>0 && len2>0) {
            sum = ((int)num1[len1-1] - '0') + ((int)num2[len2-1] - '0') +carry;
            carry = sum/10;
            sum = sum %10;
            result[result_len-1] = '0'+sum;
            result_len--;
            len1--;
            len2--;
        }
        if (len1==0 && len2!=0) {
            for(int i=len2; i>0;i--){
                sum = ((int)num2[len2-1] - '0')  +carry;
                carry = sum/10;
                sum = sum %10;
                result[result_len-1] = '0'+sum;
                result_len--;
                len2--;
            }
        } else if(len2==0 && len1!=0) {
            for(int i=len1; i>0;i--){
                sum =  ((int)num1[len1-1] - '0') +carry;
                carry = sum/10;
                sum = sum %10;
                result[result_len-1] = '0'+sum;
                result_len--;
                len1--;
            }
        }
        
        if(carry==0) {
            string res(result);
            return (res);
        } else {
            char *s = (char *)malloc((strlen(result)+ 2) * sizeof(char) );
            char val = '0'+carry;
            char  temp[2] = {val, '\0'};
            strcpy(s, temp);
            strcat(s, result);
            string res(s);
            return (res); 
        }

    }
};

