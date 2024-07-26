#include<iostream>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
    list<int> ilist{1,2,3,4,5,6,7,8,9,10};
    deque<int> deq1,deq2;
    for(auto i=ilist.begin();i!=ilist.end();i++)
    {
        if(*i%2==0)
        {
            deq2.push_back(*i);
        }
        else
            deq1.push_back(*i);
    }
    for(auto i=deq1.begin();i<deq1.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i=deq2.begin();i<deq2.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}
