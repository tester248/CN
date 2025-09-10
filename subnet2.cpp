#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int cidr;
    int mask[4];
    cout<<"Enter CIDR prefix length: ";
    cin>>cidr;
    int nBits=cidr;
    int hBits=32-cidr;
    for(int i=0;i<4;i++){
        if(cidr>=8){
            mask[i]=255;
            cidr-=8;
        }
        else{
            mask[i]=256-pow(2,8-cidr);
            cidr=0;
        }
    }
    cout<<"Subnet Mask: ";
    for(int i=0;i<4;i++){
        cout<<mask[i];
        if(i<3)
            cout<<".";
    }
    cout<<endl;
}