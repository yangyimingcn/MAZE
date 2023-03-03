#include <iostream>
using namespace std;
int main()
{
    int x=1,y=2,mx=10,my=9;
    char ch;
    cout<<"ready!\n";
    while(true)
    {
        cout<<"draw!\n";
        cin>>ch;
        switch(ch)
        {
            case 'L':
            case 'l':
                y--;
                cout<<"turn left:"<<x<<" "<<y<<endl;
                break;
            case 'R':
            case 'r':
                y++;
                cout<<"turn right:"<<x<<" "<<y<<endl;
                break;
            case 'U':
            case 'u':
                x--;
                cout<<"turn up:"<<x<<" "<<y<<endl;
                break;
            case 'D':
            case 'd':
                x++;
                cout<<"turn down:"<<x<<" "<<y<<endl;
                break;
            default:
                cout<<"press error:"<<x<<" "<<y<<endl;
        }
        if(mx==x && my==y) break;
    }
    cout<<"success!";
    return 0;
}
