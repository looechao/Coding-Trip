
 #include<iostream>
 #include<vector>
 #include<list>

 using namespace std;

 int main(){
 	list<int> ilist(10,0);
 	vector<int> ivec(10,0);
 	vector<double> doublevec1(ilist.begin(),ilist.end());//��ʼ��
 	vector<double> doublevec2(ivec.begin(),ivec.end());//��ʼ��
    for(int i=0;i<doublevec1.size();i++)
    {
        cout<<doublevec1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<doublevec2.size();i++)
    {
        cout<<doublevec2[i]<<" ";
    }
    return 0;
 }
