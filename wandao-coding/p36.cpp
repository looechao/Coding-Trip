#include<iostream>
#include<cstring>
using namespace std;

class Time{
private:
    int minute;   //分
    int sec;    //秒
public:
    Time(int mm = 0, int ss = 0) : minute(mm), sec(ss) {}
    // 使用成员函数来重载‘++’运算符
    Time& operator++ ();
    void showtime()
    {
        cout<<minute<<":"<<sec;
    }
};


Time& Time::operator++ ()
{
    if(sec!=59)
    {
        sec++;
    }
    else
    {
        sec=0;
        minute++;
    }
    return *this;
}

int main()
{
    Time t1(10,59);
    ++t1;
    t1.showtime();
    return 0;
}
