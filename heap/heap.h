#ifndef _HEAP_
#define _HEAP_

#include <vector>
#include <cstdio>

template <class T> class heap{
public:
    heap();
    heap(std::vector<T> &_ary);
    std::vector<T> sort();
    std::vector<T> top_k();
private:
    void adjust_down(unsigned long int i);
    void adjust_up(unsigned long int i);
    void init();
    inline unsigned long int father(unsigned long int i);
    std::vector<T> array;
};

template <class T> heap<T>::heap(){
    array.resize(1);
    printf("%lu\n", array.size());
}

template <class T> heap<T>::heap(std::vector<T> &_ary){
    array.resize(1);
    array.insert(array.end(), _ary.begin(), _ary.end());
    printf("%lu\n", array.size());
    init();
}

template<class T> inline unsigned long int heap<T>::father(unsigned long int i)
{
    return i >> 1;
}

template<class T> void heap<T>::init()
{
    for 
    while(i > 0){
    }
}

template<class T> void heap<T>::adjust_down(int i)
{
    while(i > 0){
        
    }
}

#endif
