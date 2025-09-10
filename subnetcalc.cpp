#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
    string IP;
    int cidr;
    cout << "\nEnter CIDR prefix length: ";
    cin>>cidr;

    cout << "Network Bits: " << cidr <<endl;
    cout<<"Host Bits: " << 32-cidr << endl;

    vector<int> subnetOctets(4,0);

    int remainingCidrBits = cidr;
    //int subnetMaskValues[8] = {128,192,224,240,248,252,254,255};

    for(int i = 0; i < 4; i++)
    {
        if(remainingCidrBits >= 8)
        {
            subnetOctets[i] = 255;
            remainingCidrBits -= 8;
        }           

        else if (remainingCidrBits > 0)
        {
            //subnetOctets[i] = subnetMaskValues[remainingCidrBits-1];
            subnetOctets[i] = 256 - pow(2,8 -remainingCidrBits);
            remainingCidrBits = 0;
        }
    }

    cout << "Subnet Mask: ";
    for (int i = 0; i < 4; i++)
    {
        cout << subnetOctets[i];
        if(i<3)
            cout <<".";
    }
    cout <<endl;

    return 0;

}