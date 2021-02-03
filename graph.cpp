#include <iostream>
#include <list>
#include <queue>

using namespace std;

class GNode{
    private:
        int* degree;
        queue<int> nodes;
        list<int>* front;


    private:
        GNode(){
            
        };
        ~GNode(){};

        void addEdge(int _node, int _to){

        }
};