#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool stringToVector(string &str, vector<int> &vect){
    int i = 0;
    while(str[i] != '\0'){
        if(i == 0 && str[i] == '0'){
            cout<< "please input legic number"<<endl;
            return false;
        }
        int value = int(str[i] - 48);
        vect.push_back(value);
        ++i;
    }
    return true;
}

vector<int> calculateVectors(vector<int> & vect1, vector<int> &vect2){
    vector<int> vect_ret;
    int next_num = 0;
    for(auto iter1 = vect1.rbegin(), iter2 = vect2.rbegin();iter1 != vect1.rend() || iter2 != vect2.rend();){
        int v1 = 0,v2 = 0;
        if(iter1 != vect1.rend()){
            v1 = *iter1;
            ++iter1;
        }
        if(iter2 != vect2.rend()){
            v2 = *iter2;
            ++iter2;
        }

        int sum = v1 + v2 + next_num;
        vect_ret.push_back(sum % 10);
        next_num = sum /10;
    }
    if(next_num)
        vect_ret.push_back(next_num);
    return vect_ret;
}

int main(){
    vector<int> vect1,vect2;
    string str1 = "34", str2 = "456";
    // cin>> str1>>str2;
    
    bool legic = stringToVector(str1, vect1);
    if(!legic) return 0;
    legic = stringToVector(str2, vect2);
    if(!legic) return 0;

    vector<int> result = calculateVectors(vect1, vect2);
    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it){
        cout<<*it;
        if(it != result.end() -1)
            cout<< "->";
    }

    return 0;
}