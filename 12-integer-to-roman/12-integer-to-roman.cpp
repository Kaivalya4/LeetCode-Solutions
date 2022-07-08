class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int index[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5, 4 , 1};
        string value[] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
        
        int i = 0;
        while(num){
            if(num>=index[i]){
                num -= index[i];
                ans += (value[i]);
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};