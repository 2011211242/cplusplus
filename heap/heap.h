#ifndef _HEAP_
#define _HEAP_

#include <algorithm>
#include <vector>
#include <cstdio>
#include <assert.h>

template <class T> class heap{
public:
    heap();
    heap(std::vector<T> &_ary);
    std::vector<T> sort();
    std::vector<T> top_k(unsigned long int k);
    unsigned long int size();
    void push(T a);
    T pop();
    bool empty();

private:
    void init();
    void adjust_down(unsigned long int i);
    void adjust_up(unsigned long int i);
    inline unsigned long int father(unsigned long int i);
    inline unsigned long int left_child(unsigned long int i);
    inline unsigned long int right_child(unsigned long int i);
    void swap(unsigned long int i, unsigned long int j);

    std::vector<T> array;
    unsigned long int _size;
};

template <class T> heap<T>::heap(){
    array.resize(1);
    printf("%lu\n", array.size());
    _size = 0;
}

template <class T> heap<T>::heap(std::vector<T> &_ary){
    array.resize(1);
    array.insert(array.end(), _ary.begin(), _ary.end());
    _size = _ary.size();

    printf("%lu\n", array.size());
    init();
}

template<class T> unsigned long int heap<T>::size(){
    return _size;
}

template<class T> inline unsigned long int heap<T>::father(unsigned long int i)
{
    return i >> 1;
}

template<class T> inline unsigned long int heap<T>::left_child(unsigned long int i)
{
    unsigned int long left = i << 1;
    if(left <= _size) return left;
    else return 0;
}

template<class T> inline unsigned long int heap<T>::right_child(unsigned long int i)
{
    unsigned int long right = left_child(i) + 1;
    if(right <= _size) return right;
    else return 0;
}


template<class T> void heap<T>::swap(unsigned long int i, \
            unsigned long int j)
{
    assert(i <= _size && j <= _size);
    std::swap(array[i], array[j]);
}

template<class T> void heap<T>::init()
{
    unsigned int long idx = father(_size);
    while(idx > 0)
    {
        printf("idx=%lu\n", idx);
        adjust_down(idx);
        idx --;
    }
}

template<class T> void heap<T>::adjust_down(unsigned long int idx)
{
    while(idx <= father(_size)){
        unsigned long int min_idx = left_child(idx);
        unsigned long int right = right_child(idx);

        if(right !=0 )
        {
            if(array[right] < array[min_idx]) min_idx=right;
        }

        if(array[min_idx] < array[idx])
        {
            swap(min_idx, idx);
            idx = min_idx;
        }
        else
        {
            idx = _size;
        }
    }
}


template<class T> std::vector<T> heap<T>::top_k(unsigned long int k){
    std::vector<T> tmp = array;
    std::vector<T> top;
    unsigned int size = _size;

    for(int i = 0; i < k && i < size; i++){
        top.push_back(array[1]);
        swap(1, _size);
        _size--;
        adjust_down(1);
    }
    array.swap(tmp);

    _size = size;
    return top;
}

template<class T> std::vector<T> heap<T>::sort()
{
    return top_k(_size);
}

template<class T> void heap<T>::adjust_up(unsigned long int i){
    unsigned long int f = father(i);
    while(f > 0 && array[i] < array[f]){
        swap(i, f);
        i = f;
        f = father(i);
    }
}

template<class T> void heap<T>::push(T a){
    array.push_back(a);
    _size++;
    adjust_up(_size);
}

template<class T> T heap<T>::pop(){
    assert(_size > 0);

    T ret = array[1];
    swap(1, _size);
    _size--;

    adjust_down(1);
    return ret;
}

template<class T> bool heap<T>::empty(){
    return _size <= 0;
}

#endif
