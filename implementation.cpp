#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <iomanip>


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

int main(){
    int num=5;
    cout<<num<<endl;
    cout<<"Binary Representation :"<<convert_to_binary(num,4)<<endl;
}
