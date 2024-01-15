/* Given an input stream A of n characters consisting only of lower case alphabets.
While reading characters from the stream, you have to tell which character has appeared
only once in the stream upto that point. If there are many characters that have 
appeared only once, you have to tell which one of them was the first one to appear.
If there is no such character then append '#' to the answer. 
You start changing the string where first repeated character comes. 

TestCases:

input : abcbad
output: abcacc

input ab
output: ab

input aba
output: abb

input : abcbadcd
output: abcaccd#
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    queue<char>q;
    string ans = "";
    map<char,int>mymap;
    int j=0;
    bool flag = false;
    for(int i=0;i<s.size();i++){
        j=i;
        if(mymap[s[i]]){
            flag = true;
            break;
        }else{
            ans+=s[i];
            q.push(s[i]);
            mymap[s[i]]+=1;
        }
    }
    if(flag){
    for(int k=j;k<s.size();k++){
        mymap[s[k]]+=1;
        q.push(s[k]);
        while(!q.empty()){
            if(mymap[q.front()]>1){
                q.pop();
            }else{
                ans+=q.front();
                break;
            }
        }
        if(q.empty()){
            ans+="#";
        }
    }
    }
    cout<<ans<<"\n";
}

