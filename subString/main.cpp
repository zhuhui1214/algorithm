class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){return 0;}
        int bigresult = 1;
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                string tmp1 = s.substr(i,j-i);//从第一个循环的第一个点开始，找到j-i个
                string tmp2 = s.substr(j,1);//从第二个循环开始只要找1个
                std::size_t found = tmp1.find(tmp2);
                if (found!=std::string::npos){//找到了,马上要执行一个break
                    if(j-i>bigresult)
                    {bigresult =  j-i;}
                    break;//break 跳出第2个循环，然后继续第一个循环
                }//if
                else
            }//for second
        }//for first
        return bigresult;
    }
};
