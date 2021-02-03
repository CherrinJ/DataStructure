#include <iostream>
#include<string>
#include <vector>
#include<map>

using namespace std;

void subStr(string &str, int index,  vector<char> &vect){
    int i = index;
    map<char, int> t_v;
    vector<char> t_v1;
    int t_count = 0;
    while(str[i] != '\0'){
        if(t_v.find(str[i]) != t_v.end()){
            if(vect.size() < t_v1.size()){
                vect = t_v1;
            }
           return subStr(str,i, vect);
        } else {
            t_v.insert(pair<char,int>(str[i],1));
            t_v1.push_back(str[i]);
        }
        ++i;
    }

    if(vect.size() < t_v1.size()){
        vect = t_v1;
    }
}

int lengthOfLongestSubNum( string s) {
    vector < int > m( 128 , - 1 );//方法二
        int res = 0 , left = - 1 ;
        for ( int i = 0 ; i < s.size(); ++ i) {
        left = max(left, m[s[i]]);
        m[s[i]] = i;
        res = max(res, i - left);
        // cout<<"left:"<<left<<",  i - left:"<< i - left<<", res:"<<res<< " ";
    }
    return res;
}

void longestSubString(string &s, vector<char> vect){
    vector<bool> charMap(256, false);
    for(int i = 0; i < s.size(); ++i){
        if(!charMap[s[i]]){
            
        }
    }
}

int main(){
    string input;
    // cin>>input;
    input = "bbbb";
    int count = 0;
    vector<char> vect;

    // // map<char, int> map1;
    // subStr(input, 0, vect);
    // for( auto it : vect){
    //     cout<< it;
    // }
    // cout<<endl;
    // cout<< vect.size() <<endl;
    int r = lengthOfLongestSubNum("aaaaaaaaaaaatbgrbrabsasdfrhtysvsrhvsg");
    cout<< r << ",str: "<<endl;
    for( auto it : vect){
        cout<< it;
    }
    return 0;
}