#include<iostream>
#include<cstring>
using namespace std;

class Time{
private:
    int minute;   //��
    int sec;    //��
public:
    Time(int mm = 0, int ss = 0) : minute(mm), sec(ss) {}
    // ʹ�ó�Ա���������ء�++�������
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
