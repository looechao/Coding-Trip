#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//nonrmal case, only one arg;
template<class T>
T add(T t){
    return t;
}

//varidic args template

template<class T, typename... Args>
T add(T t, Args... args){
    return t + add(args...);
}

void test0(){
    int isum = add(1, 2, 3, 4, 5);  // integer add
    double dsum = add(1.1, 2.2, 3.3, 4.4, 5.5); // double add
    string strsum = add(string("hello"), string(",world"));

    cout << "isum:" << isum << endl;
    cout << "dsum:" << dsum << endl;
    cout << "strsum:" << strsum << endl;

}

int main()
{
    test0();
    return 0;
}

