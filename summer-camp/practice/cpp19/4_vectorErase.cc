#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

template <typename Container>

void display(const Container& con){
    for(auto &ele : con)
    {
        cout << ele << " ";
    }
    cout << endl;
}


void test0(){
    vector<int> vec = {1, 3, 5, 5, 5, 5, 9, 7, 5, 5, 6};
    display(vec);
    for(auto it = vec.begin(); it != vec.end(); ++it){
        if( *it == 5 ){
            vec.erase(it);
        }
    }
    display(vec);
}

void test1(){
    vector<int> vec = {1, 3, 5, 5, 5, 5, 9, 7, 5, 5, 6};
    display(vec);
    for(auto it = vec.begin(); it != vec.end(); ){
        if( *it == 5 ){
            vec.erase(it);
        }else{
            ++it;
        }
    }
    display(vec);
}
             
int main()   
{            
    test1(); 
    return 0;
}            
             
