// https://blog.csdn.net/u011831771/article/details/77284676
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    // while (1)
    // {
        map<long long, long long> data;
        map<long long, int> out, dlog;
        string s;

        while (getline(cin, s))
        {
            long long a = 0, b = 0;
            int i = 3;
            for (; s[i] != ','; i++)
                a += a * 16 + s[i] - '0';

            i += 4;
            for (; s[i] != '}'; i++)
                b += b * 16 + s[i] - '0';

            data[a] = b;
            dlog[a] = 1;
            out[a] = 0;
            out[b] = 0;
            if (i == s.length() - 1)
                break;
        }

        map<long long, long long>::iterator it = data.begin();
        for (; it != data.end(); it++)
        {
            if (0 == out[it->first])
            {
                vector<long long> tmp;
                long long t = it->first;
                while (1 == dlog[t])
                {
                    tmp.push_back(t);
                    if (find(tmp.begin(), tmp.end(), data[t]) != tmp.end())
                    {
                        for (vector<long long>::iterator k = tmp.begin(); k != tmp.end(); k++)
                            out[*k] = 1;
                        break;
                    }
                    t = data[t];
                }
            }
        }
        int sum=out.size();
        for (map<long long, int>::iterator kk = out.begin(); kk != out.end(); kk++)
        {
            sum--;
            cout<<"{0x"<<hex<<kk->first<<", ";
            if(kk->second==1)
                cout<<"ture}";
            else
                cout<<"false}";

            if(sum==0)
                cout<<endl;
            else
                cout<<","<<endl;
        }
    //}

    return 0;
}
