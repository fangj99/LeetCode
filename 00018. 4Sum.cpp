
//Accepted	320 ms	cpp
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        vector<vector<int> > ans;
        if(num.size() < 4) return ans;
        sort(num.begin(),num.end());
        int len = num.size(),sum,fir,sec;
        for(int i=0;i<len;i++)
        {
            if(i!=0 && num[i] == num[i-1]) continue;
            for(int j=i+1;j<len;j++)
            {
                if(j!=i+1 && num[j] == num[j-1]) continue;

                fir = j+1,sec = len-1;
                while(fir < sec)
                {
                    sum = num[i]+num[j]+num[fir]+num[sec];
                    if(sum < target) fir++;
                    else if(sum > target) sec--;
                    else if(fir != j+1 && num[fir] == num[fir-1]) fir++;
                    else if(sec != len-1 && num[sec] == num[sec+1]) sec--;
                    else
                    {
                        vector<int> tmp(4);
                        tmp[0] = num[i],tmp[1] = num[j];
                        tmp[2] = num[fir],tmp[3] = num[sec];
                        ans.push_back(tmp);
                        fir++,sec--;
                    }
                }
            }
        }
        return ans;
    }
};

