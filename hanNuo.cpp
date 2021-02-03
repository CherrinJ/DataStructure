#include <iostream>

using namespace std;

void hanNuo(int value, char a, char b, char c){
    if(value <= 0){
        cout<<"->"<< a << "->"<< b;
        return;
    }
    else{
        cout<<"->"<< a << "->"<< b;
        hanNuo(value - 1, a,c,b);
        hanNuo(value - 1, b,c,a);
       
    }
}

int main(){
    hanNuo(3,'A','B','C');
    return 0;
}