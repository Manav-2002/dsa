#include<bits/stdc++.h>
using namespace std;
vector<int> lps(string s){
    int n=s.size();
    vector<int> arr(n);
    arr[0]=0;
    int counter=0;
    for(int i=1;i<n;i++){
        if(s[counter]==s[i]){
            counter++;
            arr[i]=counter;
        }else{
            while(s[i]!=s[counter] && counter>0)
                counter=arr[counter-1];
            if(s[i]==s[counter]){
                counter++;
                arr[i]=counter;
            }else{
                arr[i]=0;
            } 
        }
    }
    return arr;
}
vector<int> patternMatching(string text,string pattern){
    vector<int> pre=lps(pattern);
    int i=0,j=0;
    int len=pattern.size();
    int n=text.size();
    vector<int> arr(n);
    while(j<n){
        if(text[j]==pattern[i]){
            i++;
            arr[j]=i;
            j++;
        }else{
            if(i==0){
                arr[j]=0;
                i=0;
                j++;
            }else{
                i=pre[i-1];
            }  
        }
    }
    return arr;
}

int main(){
    string s="acacabacacabacacac";
    vector<int> arr=lps(s);
    for(auto v:arr) cout<<v<<" ";
    cout<<endl;
    string text="abcxabcdabxabcdabcdabcy";
    string pattern="abcdabcy$";
    arr=patternMatching(text,pattern);
    for(auto v:arr) cout<<v<<" ";
    cout<<endl;
    return 0;
}