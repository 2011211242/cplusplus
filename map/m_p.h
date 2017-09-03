/****************************************
* File Name: m_p.h
* Created Time: 2017-09-03 10:21:22
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/

#include <vector>
using std::vector;

enum COLOR {WHITE, GRAY, BLACK};
struct edge{
    unsigned int e;
    unsigned int dist;
    bool visited;
    edge(): visited(false), e(0), dist(0){}
};

struct node{
    int val;                //val
    COLOR color;            //color
    unsigned int dist;      //dist
    unsigned int s_t, f_t;  //start time and finish time during dfs or bfs
    unsigned int fth;       //remember the father id of a node
    vector<edge> next;      //edges direct to its neighbors
    node():s_t(0), f_t(0), fth(-1), val(0), dist(0), color(WHITE){}
};

extern vector<node> mp;

