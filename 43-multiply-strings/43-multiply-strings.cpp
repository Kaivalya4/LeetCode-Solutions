class Solution {
public:
    string multiply(string num1, string num2) {
        
        reverse(num2.begin(),num2.end());
        reverse(num1.begin(),num1.end());
        if(num1.back() == '0' || num2.back() == '0')
            return "0";
        string fans(400,'0');
        for(int i=0;i<num1.size();i++){
            string ans ;
            int carry = 0;
            int n1 = num1[i] -'0';
            
            for(int j=0;j<i;j++){
                ans.push_back('0');
            }
            for(int j=0;j<num2.size();j++){
                int n2 = num2[j] - '0';
                if(j == num2.size() - 1){
                    carry = n1*n2 + carry;
                    while(carry){
                        ans.push_back(carry%10 + '0');
                        carry /=10;
                    }
                }
                else{
                    ans.push_back( (n1*n2 + carry)%10 + '0');
                    carry = (n1*n2 + carry)/10;
                    
                }
            }
            carry = 0;
            int j ;
            for(j=0;j<ans.length();j++){
                char c = fans[j];
                fans[j] = (fans[j] -'0'  + ans[j] - '0' + carry)%10 +'0'  ;
                carry = (c -'0'  + ans[j] - '0' + carry)/10;
            }
            
           
            while(carry){
                fans[j] = (fans[j] -'0'   + carry)%10 +'0';
                carry /=10;
                j++;
            }
            
             
        }
        int j = 399;
        while(fans[j] == '0'){
            fans.pop_back();
            j--;
        }
        reverse(fans.begin(),fans.end());
        return fans;
    }
};