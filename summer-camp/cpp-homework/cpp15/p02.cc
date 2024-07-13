#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

// define template 
template<typename T>
T add(T a, T b);


// define set<int> specialize version
template<>
set<int> add<set<int>> (set<int> a, set<int> b);


/* //  c++17's merge function, specialize template for set */
/* template<> */
/* set<int> add<set<int>>(set<int> a, set<int> b){ */
/*     a.merge(b); */
/*     return a; */
/* } */

//specialize

template<>
set<int> add<set<int>> (set<int> a, set<int> b)
{
    for(auto &ele : b){
        a.insert(ele);
    }
    return a;
}


void test0(){
    set<int> a{1, 3, 5, 7}, b{2, 4, 6, 8};
    set<int> result = add(a,b);
    for(auto & ele : result) cout << ele << " ";
    cout << endl;
    for(auto & ele : a) cout << ele << " ";
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

