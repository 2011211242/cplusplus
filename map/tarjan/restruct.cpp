#include <vector>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

/*
Low(u)=Min
{
    DFN(u),
    Low(v),(u,v)为树枝边，u为v的父节点
    DFN(v),(u,v)为指向栈中节点的后向边(非横叉边)
}*/

enum COLOR{WHITE, GRAY, BLACK};

struct node{
    unsigned int dfn, low;
    unsigned int block;
    COLOR color;
    vector<unsigned int> next;
    node():dfn(0), low(0), color(WHITE), block(0){}
};

vector<node> m_p;
stack<unsigned int> stk;
unsigned int tm = 0;
unsigned int cnt = 0;

void tarjan(unsigned int u){
    m_p[u].dfn = m_p[u].low = ++tm;
    stk.push(u);
    m_p[u].color = GRAY;

    for(int i = 0; i < m_p[u].next.size(); i++){
        unsigned int v = m_p[u].next[i];
        if(m_p[v].color == WHITE){
            tarjan(v);
            m_p[u].low = min(m_p[u].low, m_p[v].low);
        }
        else if(m_p[v].color == GRAY){
            m_p[u].low = min(m_p[u].low, m_p[v].dfn);
        }
    }

    if(m_p[u].dfn == m_p[u].low)
    {
        unsigned int v;
        cnt ++;
        do {
            v = stk.top();
            //printf("%u ", v);
            stk.pop();
            m_p[v].color = BLACK;
            m_p[v].block = cnt;
        }
        while(u != v);
        //printf("\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    m_p = vector<node>(n + 1);

    for(unsigned int u = 1; u <= n; u++){
        unsigned int v;
        scanf("%d", &v);

        while(v != 0){
            m_p[u].next.push_back(v);
            scanf("%d", &v);
        }
    }

    for(int i = 1; i < m_p.size(); i++){
        if(m_p[i].color == WHITE){
            tarjan(i);
        }
    }

    if(cnt == 1){
        printf("1\n0\n");
        return 0;
    }

    vector<unsigned int> s(cnt + 1);
    vector<unsigned int> e(cnt + 1);
    for(int i = 1; i < m_p.size(); i++){
        for(int j = 0; j < m_p[i].next.size(); j++){
            unsigned int v = m_p[i].next[j];
            if(m_p[i].block != m_p[v].block){
                s[m_p[i].block] ++;
                e[m_p[v].block] ++;
            }
        }
    }

    int ans1 = 0, ans2 = 0;
    for(int i = 1; i < e.size(); i++){
        if(e[i] == 0) ans1 ++;
        if(s[i] == 0) ans2 ++;
    }

    printf("%d\n%d\n", ans1, max(ans1, ans2));
    return 0;
}
