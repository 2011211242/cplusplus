/****************************************
* File Name: m_p.cpp
* Created Time: 2017-09-03 10:28:06
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/

#include "m_p.h"

static const int maxn = 100;
vector<node> mp(maxn);
static unsigned int time = 0;

void dfs(vector<node> &m_p, int start){
    node & nd = m_p[start];
    nd.color = GRAY;
    time = time + 1;
    nd.s_t = time;

    for(unsigned i = 0; i < nd.next.size(); i++){
        unsigned int n_id = nd.next[i].e;
        if (m_p[n_id].color == WHITE){
            m_p[n_id].fth = start;
            dfs(m_p, n_id);
        }
    }

    nd.color = BLACK;
    time = time + 1;
    nd.f_t = time;
}

