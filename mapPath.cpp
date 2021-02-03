#include<iostream>
// #include<conio.h>
#include <vector>
#include <math.h>

using namespace std;

struct Point
{
   int x;
   int y;

   Point(int value1, int value2){
       x = value1;
       y = value2;
   }
};

int g_n,g_m;
int min_path = 0;

typedef vector<Point> PathVect;
vector<PathVect> path;

void printPath(vector<Point> &vect){
    vector<Point>::iterator i = vect.begin();
    for(; i != vect.end(); ++i){
        Point p = *i;
        cout<<"("<< p.x<<"," << p.y<<")"<<"->";
    }
    cout<<endl;
}

void walkPath(vector<Point> vect, int x, int y){
    if( x > g_n || y > g_m){
        return;
    }
    Point p(x,y);
    vect.push_back(p);
    if(x == g_n && y== g_m ){
        if(min_path == 0)
            min_path = vect.size();
        int size = vect.size();
        min_path = min(min_path, size);
        path.push_back(vect);
        printPath(vect);

    }
    else{
         walkPath(vect, x+1, y);
         walkPath(vect, x, y+1);   
    }
}

int main(){
    cout<<"input chess clounm and row :"<<endl;
    // cin>> g_n>>g_m;
    g_n = 2;
    g_m = 3;
    vector<Point> vect;
    walkPath(vect, 0,0);

    vector<PathVect>::iterator i = path.begin();
    int count = 0;
    for(; i != path.end(); ++i){
        // PathVect p = *i;
        // if(min_path == p.size()){
        //     cout<<"min path is: "<<endl;
        //     printPath(p);
        // }
        ++count;
    }
    cout<<"total path is "<< count<<endl;
    return 0;
}