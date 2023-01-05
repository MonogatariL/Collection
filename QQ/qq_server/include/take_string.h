#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<string> Split_string(char *msg)
{   
    string str=msg;
    string s;
    vector<string>res;
    for(auto x:str)
    {
        if(x==' '&&res.size()<2)
        {
            res.push_back(s);
            s="";
        }
        else
        {
            s+=x;
        }
    }
    if(s.size())
        res.push_back(s);
    return res;
}
