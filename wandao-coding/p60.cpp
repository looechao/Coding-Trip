#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vec(10,0);
    for(int i=0;i<vec.size();i++){
        cin>>vec[i];
    }

    for(int i=0;i<vec.size()-1;i++){    //Ã°ÅÝ·¨ÅÅÐò
        for(int j=0;j<vec.size()-i-1;j++){
            if(vec[j] > vec[j+1]){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }

    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}
