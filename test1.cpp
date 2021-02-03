#include <iostream>
#include <vector>
#include <new>
#include <list>
#include <array>
#include <string>
#include <memory.h>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <utility>
#include <map>


using namespace std;

template <class _Tp>
struct myCompare : binary_function<_Tp, _Tp, bool>
{
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x < __y;}
};


class myCompare2{
    public:
        bool operator()(int i, int j){
            return( i > j);
        }
};

double myPowXy(int x, int n){
    if(x == 0) return 0;

    int de = x;
    int _n = n < 0 ? n * -1 : n;
    double result = 1;
    while(_n){
        if(_n & 1) 
            result *= de;
        de *= de;
        _n = _n >> 1;
    }
    if(n < 0) result = 1.0 / result;
    return result;
}

int* rangeSum=nullptr;
vector<int> maxRange[6];
int* range;
int rangeNum;
int largeRange(int n){
    int maxSum = 0;
    // int* maxRange;
    // if(n < 0 ) return 0;
    // if(rangeSum[n] != -999)
    //     return rangeSum[n];
    //  else{
    //      int m = largeRange(n - 1);
    //      int mm = max(m + range[n], range[n]);
    //      cout<< "***:"<< mm<<":000";
    //      if(m + range[n] > range[n]){
    //          maxRange[n].push_back(range[n]);
    //      }
    //     return rangeSum[n] = mm;}

    if(n == 0){
         maxRange[n].push_back(range[0]);
        return range[0];
    }
    else{
        if(n-1 >= 0){
            int m = largeRange(n-1) + range[n];
            if(m > range[n]){
                maxRange[n] = maxRange[n -1];
                maxRange[n].push_back(range[n]);
            }
            maxSum += max(m, range[n]);}
        return maxSum;
    }

}

void dec_LargeRange(){
    rangeSum[0] = range[0];
    for(int i = 1; i < 6; ++i){
        rangeSum[i] = max(rangeSum[i-1]+ range[i] , range[i]);
    }
}

int main(){
    // int n = 6;
    rangeNum= 6;
    int temp[6] = {9,-18,3,2,7,1};
    range = temp;
    int temp1[6]={0};
    rangeSum = temp1;
//    for(int t = 0; t < rangeNum ;++t){
//        vector<int> v;
//         maxRange[t] = v;
//         rangeSum[t] = -999;
//     }
    int i = 0;
    int sum = 0;
    while (i < rangeNum)
    {
        sum = largeRange(i);
        cout<<i<<":"<<sum<<endl;
        ++i;
    }

    dec_LargeRange();
    i = 0;
    while(i < 6){
        cout<< *(rangeSum++)<<endl;
        ++i;

    }
    
    return 0;
}


//list vector map queue stack set deque algorithm
// int main(){
//     {
// //    vector<int> v(10);//{1,2,3,4,5,6,7,8,9,10};
// //    for(int l = 0; l < 10; ++l)
// //     v[l] = l;
   

// //    cout<<"first output:"<<endl;
// //    for(int i= 0; i < v.size(); ++i){
// //        cout<<v[i]<< " ";
      
// //    }
// //     cout<< endl<< "第二种遍历方法："<<endl;
// //    vector<int>::iterator i;
// //    for(i= v.begin(); i < v.end(); ++i){
// //        cout<<*i<<" ";
// //    }
// //     cout<< endl<< "第3种遍历方法："<<endl;

// //     for(i = v.begin(); i != v.end(); ++i)
// //         cout<< *i << " ";
    
// //     cout<<endl << "NO.4 output:"<<endl;

// //     i = v.begin();
// //     v.insert(i+4, 1);
// //     i = v.begin();
// //     while(i < v.end()){
// //         cout<< *i <<" ";
// //         i += 2;
// //     }
//     // i = v.begin();
    
//     // vector<int> v1{2,3};
//     // v.emplace(i+1, {2,3});
//     // v.emplace_back(12,2,3);
//     // v.erase(i+1);
//     // v.erase(i,i+5);
//     //swap()
//     // int* p = v.data();


//     // pair<int, string> pair1(0, "0");
//     // pair<int, string> pair2(make_pair(1, "1"));
//     // vector<pair<int, string>> vect;
//     // for(int i = 0; i<10; ++i){
//     //     // char str = char(i);
//     //     vect.push_back(make_pair(i, "i"));
//     // }

//     // pair<string, int> p = make_pair("a", 1);
//     // map<string, int, myCompare<string> > myMap;
//     // myMap.insert(make_pair("a", 3));
//     // myMap.insert(make_pair("z", 3));
//     // myMap["c"] = 2;
   
//     // // myMap.emplace(make_pair("a", 1));
//     // map<string, int>::iterator iter = myMap.begin();
//     // for(; iter != myMap.end(); ++iter)
//     //     cout<<iter->first<<","<<iter->second<<endl;
//     }
    
//     // decltype(10.8) b = 0.1;
    
//     // vector<int> v2;
//     // for(int i = 0; i < 9 ;++i)
//     //     v2.push_back(i);
//     // sort(v2.begin(), v2.end(), myCompare2());
//     //  for(vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
//     //     cout<<*iter;

//     // // vector<string> v3;

//     // // string vv[3] = {"aaaa","bbbbb","cccccc"};
//     // // for(int i = 0; i <3; ++i){
//     // //     string s = vv[i];
//     // //     v3.push_back(s);
//     // // }
//     // //  for(auto t: v3){
//     // //      cout<<"t:->"<<t<<endl;
//     // //  }
//     // //  for(auto &t1 : v3){
//     // //      cout<< "t1->"<<t1<<endl;
//     // //  }

//     // const int a = 2;
//     // // constexpr int n = 1+1;
//     // int nn[a] = {1,2};
    
//     return 0;
// }




// void stringUsage(){
//     string str;
//     int i[100];
//     memset(&str, 0, 100);
//     memset(i, 0, 100);
// }

// //list 迭代器是双向迭代器
// void ListItarator(){
//     list<int> v;
    
//     list<int>::const_iterator it;
//     for(it = v.begin(); it != v.end(); ++it){
//         cout<< *it<< " ";
//     }
//     // cout<<endl<<"22:"<<endl;
//     // for(it = v.begin(); it < v.end(); ++it){
//     //     cout<< *it<< " ";
//     // }

//     // for(int i  = 0; i < v.size(); ++i){
//     //     cout<< v[i]<< " ";
//     // }
//     // it < v.end();   双向迭代器不知道 < 操作
//     // cout<< v[ii];  双向迭代器不支持随机访问
//      list<int> t;
//     v.sort();
//     it = v.begin();
//     v.splice(it, t, ++it);

// }

// ///随机访问迭代器
// void ArrayContariner(){
//     array<int, 10> values;
//     int h = 1;
//     auto first = values.begin();
//     auto last = values.end();
//     first = begin(values);
//     last = end(values);

//     while(first != last){
//         *first = h;
//         ++first;
//         ++h;
//     }

//     first = values.begin();
//     while(first != last){
//         cout<< *first<< " ";
//         ++first;
//     }

//     array<int, 5> values2{5,4,3,2,1};

//     auto first1 = values2.rbegin();
//     auto last1 = values2.rend();
//     while(first1 != last1){
//         cout<< *first << " ";
//         ++first1;
//     }

//     first1 = values2.rbegin();
//     last1 = values2.rend();
//     while(first1 != last1){
//         --last1;
//         cout<< *last1 << " ";
//     }
//     // values2.at(2);
// //    int e = get<3>(values);
//     // values2.data();
//     double total = 0;
//     for(size_t i = 0; i < values2.size(); ++i){
//         total + values2.at(i);
//     }

//     if(values.empty())
//         cout<< "the contrainer has no element.\n";
//     else
//         cout<< "the contrainer has "<< values.size() << "elements."<< endl;

//     for(auto&& value: values){
//         total += value;
//     }
// }


// void VectorContrainer(){
//     int array[] = {1,2,3,4,5};
//     vector<int> values{1,2,3,4,5};
//     vector<int> values1(array, array+2);
//     begin(values1);
//     vector<int> values2(values1.begin()+ 2, values1.end());
//     int capacity = values2.capacity();
//     values2.shrink_to_fit();
//     values2.insert(values2.begin()+ 3, 9);
//     values2.erase(values2.begin()+ 3);
//     values.swap(values1);
//     values2.emplace(values2.begin()+1, 99);
//     values2.front();
//     values2.back();

//     //insert() 函数的功能是在 vector 容器的指定位置插入一个或多个元素
//     vector<int> demo{1,2};
//     demo.insert(demo.begin()+1, 3);
//     demo.insert(demo.end(), 2,5);
//     vector<int> demo1{6,7,8,9};
//     demo.insert(demo.end(), demo1.begin(), demo1.end());
//     demo.insert(demo.end(),{11,22,33});

//     //再次强调，emplace() 每次只能插入一个元素，而不是多个。
//     demo.emplace(demo.end(),44);

//     vector<int> temp{1,2,3,4,5,3,6,3,4};
//     auto iter = remove(temp.begin(), temp.end(), 3);
//     temp.erase(iter, temp.end());
//     for(int i= 0; i < temp.size(); ++i){
//         cout<< temp[i] << " ";
//     }


//     vector<int> temp1;
//     temp1.reserve(1000);
//     temp1 = {1,2,3,4,5,6};
//     vector<int>(temp1).swap(temp1);

//    //尽量不使用 vector<bool> ，应为vector<bool> 不完全满足c++标准中对容器的需求，可以使用deque<bool>或者biset 来代替 bitset<2> temp3;
    
// }

// //deque 是 double-ended queue 的缩写，又称双端队列容器。
// //deque 容器迭代器的类型为随机访问迭代器
// void DequeContrainer(){
//     deque<int> demo1;
//     deque<int> demo2(10); //创建10个int
//     deque<int> demo3(2,3); //创建2个3
//     deque<int> demo4(demo1);
//     deque<int> demo5{1,2,3,4,5,6,7};

//     deque<int> d1;
//     d1.push_back(1);
//     d1.push_back(2);
//     d1.push_back(3);
//     d1.push_front(0);

//     cout<< "元素个数： "<< d1.size()<<endl;
//     for(auto it = d1.begin(); it != d1.end(); ++it){
//         cout<< *it << " ";
//     }

//     //需要注意的是，在使用反向迭代器进行 ++ 或 -- 运算时，++ 指的是迭代器向左移动一位，-- 指的是迭代器向右移动一位，即这两个运算符的功能也“互换”了。
//     for(auto it = d1.rbegin(); it != d1.rend(); ++it){
//         cout<< *it << " ";
//     }
//     //首先需要注意的一点是，迭代器的功能是遍历容器，在遍历的同时可以访问（甚至修改）容器中的元素，但迭代器不能用来初始化空的 deque 容器。

//     deque<int> d;
//     d.push_back(2);
//     d.pop_back();

//     d.push_front(2);
//     d.pop_front();

//     d.emplace_back(2);
//     d.emplace_front(3);
//     d.emplace(d.begin(), 4);

//     for(auto i: d){
//         cout<< i << " ";
//     }

//     d.erase(d.begin());
//     d.erase(d.begin() + 1);
    
// }

// void stringReverse(char* str){
//     char c;
//     char * begin= nullptr;
//     char* end = nullptr;
//     *begin++ = '\0';
//     while(cin>> c){
//         if(c == '\n') break;
//         *begin++= c;
//         *begin = '\0';
//     }
//     while(*begin-- != '\0'){
//         *end++ = *begin--;
//     }
//     *end = '\0';
//     cout<< end;
// }
//  void strCopy(char* src, char* dest){
//      while(*src != '\0'){
//          *dest++ = *src++;
//      }
//      *dest = '\0';
//  }

// double Pi(){
//     //pi/2 = 1+1/3*2/5+1/3*2/5*3/7+1/3*2/5*3/7*4/9
//     double pi = 0.0, _p = 2;
//     int i = 1;
//     while(_p > 1e-16){
//         _p = _p * (i / (2*i +1));
//         pi += _p;
//         ++i;
//     }
//     cout<<setprecision(18)<< pi<<endl; //iomanip
// }

// void CombineNumbers(){
//     int count = 0;
//     vector<int> vect;
//     for(int i = 1; i < 5; ++i){
//         for(int j = 1; j < 5; ++j){
//             for(int l = 1; l < 5; ++l){
//                 if(j != j && j != l && l != i){
//                     vect.push_back(i * 100 + j * 10+ l);
//                     ++count;
//                 }
//             }
//         }
//     }
// }

// struct Jose1
// {
//     int flag;
//     int index;
// };


// void JosephusCircle(int n){
//     vector<int> vect1;
//     for(int i = 1; i <= n; ++i){
//         vector.push_back(i);
//     }
//     int chosenum = 9, count =1;
//     vector<int> temp;
//     vector<int>::iterator it = vect1.begin();
//     while(vect1.size() > 1){
//         for(; it != vect1.end(); ++it){
//             if(count == chosenum){
//                 count = 0;
//                 cout<< *it << " ";
//             } else {
//                 temp.push_back(*it);
//             }
//             ++count;
//         }
//         vect1 = temp;
//         temp.clear();
//         it = vect1.begin();
//     }
// }