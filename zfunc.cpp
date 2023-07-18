#include<bits/stdc++.h>
using namespace std;
vector<int> Zfunc(string s){
    int n=s.size();
    vector<int> z(n);
    z[0]=0;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=i;
            r=i;
            while(r<n && s[r-l]==s[r]) r++;
            z[i]=r-l;
            r--;
        }else{
            
            if(i+z[i-l]<=r){
                z[i]=z[i-l];
            }else{
                l=i;
                while(r<n && s[r-l]==s[r]) r++;
                z[i]=r-l;
                r--;
            }
        }
    }
    return z;
}
int32_t main(){
    string s="aabxaabxcaabxaabxay";
    vector<int> z_arr= Zfunc(s);
    for(auto v:z_arr) cout<<v<<" ";
    cout<<endl;
}