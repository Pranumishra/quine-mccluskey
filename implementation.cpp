#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <iomanip> //for input and output formatting


string convert_to_binary(int num,int length){
    string ans="";
    for(int i=length-1;i>=0;i--){
        int bit = num&1;
        if(bit){
            ans+='1';
        }
        else{
            ans+='0';
        }
        num=num>>1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int ones_count(string str){
    int count=0;
    for(auto ch:str){
        if(ch=='1'){
            count++;
        }
    }
    return count;
}


// "1-0" → A C'
string binary_to_boolean_expression(string str){
    string result="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='1'){
            result+=(char)('A' + i);
        }
        else if(str[i]=='0'){
            result+=(char)('A' + i);
            result+="'";
        }
    }
    return result;
}

int main(){

    int variables;   //number of variables such as (a,b,c,d)=>4.
    int m;           //to store number of min terms
    int d;           //to store number of dont care

    cout<<"Enter number of variables : ";
    cin>>variables;

    cout<<"Enter number of minTerms : ";
    cin>>m;  
    vector<int>minTerms(m);
    cout<<"Enter all minTerms seprated by space : ";
    for(int i=0;i<m;i++){
        cin>>minTerms[i];
    }

    cout<<"Enter number of don't cares : ";
    cin>>d;
    vector<int>dontCare(d);
    cout<<"Enter all don't cares seprated by space : ";
    for(int i=0;i<d;i++){
        cin>>dontCare[i];
    }
    cout<<endl;

    //Combining all min terms and dont cares in single array for processing
    vector<int>Terms(m+d);
    int i=0;
    for(;i<m;i++){
        Terms[i]=minTerms[i];
    }
    for(;i<m+d;i++){
        Terms[i]=dontCare[i-m];
    }

    //Forming groups according to number of one's
    map<int,vector<pair<int,string>>>groups;
    for(int num:Terms){
        string binaryForm = convert_to_binary(num,variables);
        int count=ones_count(binaryForm);
        groups[count].push_back({num,binaryForm});
    }

    for(auto grp : groups){
        cout<<"Group "<<grp.first<<":- ";
        cout<<endl;
        for(auto str:grp.second){
            cout<<str.first<<" : "<<str.second<<endl;
        }
        cout<<endl;
    }
}
