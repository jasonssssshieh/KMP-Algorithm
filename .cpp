//
//  main.cpp
//  KMP Algorithm
//
//  Created by Zijian Xie on 2016/11/6.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KMP{
private:
    vector<int> next;
    string t;
    string s;
public:
    KMP(string& ss, string& tt){
        s = ss;
        t = tt;
    }
    
    void NEXT(){
        int n = (int)t.size();
        next.resize(n,0);
        int j = 0;
        for(int i = 1; i < n; i++){
            if(t[i] == t[j]){
                next[i] = j + 1;
                j++;
            }else if(j != 0){
                j = next[j - 1];
                while(j != 0){
                    if(t[i] == t[j]){
                        next[i] = j + 1;
                        break;
                    }
                    j = next[j - 1];//每一次失配，都需要把j指针往前跳一位！！！！再查看next表！
                }
            }
        }
        //for(int i = 0; i < n; ++i){
        //    cout<<next[i]<<endl;
        //}
    }
    
    bool compare(){
        NEXT();
        int ps = 0, pt = 0;
        while(ps < s.size()){
            while(ps < s.size() && pt < t.size() && s[ps] == t[pt]){
                ps++;
                pt++;
            }
            if(pt == t.size()){
                cout << "Result is True" <<endl;
                return true;
            }
            if(ps < s.size() && pt < t.size() && s[ps] != t[pt]){
                while(pt != 0){
                    pt = next[pt];
                    if(s[ps] == t[pt]){
                        break;
                    }
                }
                //cout<<pt<<" ";
                if(s[ps] != t[pt]){
                    ps++;
                }else{
                    ps++;
                    pt++;
                }
                //cout<< "("<<pt<<")"<<" ";
            }
        }
        //cout<<endl;
        cout << "Result is False" <<endl;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    string s = "cacacacccccccbacacacaacbacacabacccccccacacabacccacaaacacabacacccccabacacaccacabacacccccabacaccccacbacacacabaccaccabcccacaccacacacabaccacacbaccccacacacacabacacabacacac";
    string t = "acacabacacabacacac";
    KMP* test = new KMP(s,t);
    test->compare();
    return 0;
}
