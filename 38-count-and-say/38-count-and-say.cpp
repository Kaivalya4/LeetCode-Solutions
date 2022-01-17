class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i=2;i<=n;i++)
        {
            string temp= "";
            int ctr =1;
            if(i == 2){
                str = "11";
                continue;
            }
            for(int j=0;j<str.length();j++)
            {
                if(j == str.length() -1)
                {
                    if(str[j] != str[j-1])
                    {
                        ctr=1;
                        temp += to_string(ctr);
                        temp.push_back(str[j]);
                    }
                    else{
                        temp += to_string(ctr);
                        temp.push_back(str[j]);
                        ctr=1;
                    }
                    break;
                }
                if(str[j] != str[j+1])
                {
                    temp += to_string(ctr);
                    temp.push_back(str[j]);
                    ctr=1;
                }
                else{
                    ctr++;
                }
            }
            str = temp;
        }
        return str;
    }
};