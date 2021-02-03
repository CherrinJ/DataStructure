#include<iostream>
#include <math.h>
#include <vector>
#include <string>
#include <array>
#include <deque>

using namespace std;

void main(){
    // int score;
    // char result = (score >= 90) ? 'A' : ((score >= 60 && score < 90) ? 'B' : 'C')
    return;
}

int RabitsQuestions(int month){
    if(month < 3) return 1;
    else return RabitsQuestions(month - 1) + RabitsQuestions(month - 2);
}

bool IsSingleNum(int m){
    int _t = sqrt(m);
    for(int i = 2; i <= _t; ++i){
        if(m / i == 0) return true;
    }
    return false;
}

vector<int> getFlowerNums(int min, int max){
    vector<int> nums;
    for(int i = min; i <= max; ++i){
        if(IsFlowerNum(i)){
            nums.push_back(i);
        }
    }
    return nums;
}

bool IsFlowerNum(int m){
    int _t = 0, _m = m;
    while(_m % 10 != 0){
        int _a = _m % 10;
        _t += _a*_a* _a;
        _m = _m / 10;
    }
    if(_t == m) return true;
    else return false;
}

void PrintAllPrimeNum(int m){
    int _m = m;
    int _ms = sqrt(_m);
    cout<<"prime num is: ";
    for(int i = 2; i <= _ms; ++i){
        if(IsSingleNum(i)){
            while(_m / i == 0){
                cout<< i << " ";
                _m = _m /i;
            }
        }
    }
    cout<< endl;
}

int getMaxDivisor(int m, int n){
    int _m = max(m,n);
    int _n = min(m,n);
    int _t = _m % _n;
    while(_t != 0){
        _m = _n;
        _n = _t;
        _t = _m % _n;
    }

    return _t;
}

int getMinMultiple(int m, int n){
    int divisor = getMaxDivisor(m, n);
    return m * n / divisor;
}

void rangeString(string c){
    int charNum = 0, spaceNum = 0, numberNim = 0, otherNum = 0;
    for(int i = 0; i < c.size(); ++i){
        if((c[i] >= ' a' && c[i]<= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
            ++charNum;
    }
}

int sumNAndNNumber(int n){
    int _n = n;
    int sum = 0;
    int i = 0;
    while(i < _n ){
        sum += sum * 10 + _n;
        ++i;
    }

    return sum;
}

bool IsPerferNumber(int m){
    int sum = 0;
    for(int i = 1; i < m ; ++i){
        if(m % i == 0)
            sum += i;
    }
    if(sum == m) return true;
    return false;
}
void printYanhuiTrangle(int n){
    int i = n;
    // int numFlag = 1;
    vector<int> colunm;
    vector<int> temp;
    while(i > 0){
        // colunm.clear();
        colunm = temp;
        temp.clear();
        for(int l = 1; l <= i + (n - i) * 2; ++l){
            if(l < i) cout<< " ";
            else {
                if(l == i || l == i + (n - i) * 2){
                     cout<< 1;
                     temp.push_back(1);
                } else if((l - i) % 2 == 0) {
                    int index = (l - i) / 2;
                    int result = colunm[index - 1] + colunm[index];
                    temp.push_back(result);
                    cout<<  result;
                    // ++numFlag;
                } else {
                    cout<< " ";
                }
            }
        }
        cout<< endl;
        --i;
    }

    // vector<int> a = {1,2,3,4};
    // a.erase(find(a.begin(), a.end(), 3));
}

int getNumber(int flag){
    if(flag == 1 || flag == 2)  return 1;
    else {
        return getNumber(flag - 1) + getNumber(flag - 2);
    }
}

void output9And9(){
    int i = 1;
    while(i < 10){
        for(int j = 1; j <= i; ++j){
            cout<< i << "x" << j << "=" << i *j;
        }
        cout<<endl;
        ++i;
    }
}

void HannoiTower(int n){
    deque<int> d1, d2,d3;
    for(int i = 0; i < n; ++i){
        d1.emplace_front(i + 1);
    }

    
}