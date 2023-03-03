#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define N 20
int x=1,y=1;
void Ready(int maze[][N])
{
    int i,j,x,y;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            maze[i][j]=1; //1代表墙
    srand((unsigned)time(NULL));//随机函数种子发生器（以时间做参数）
    for(int i=0;i<=N*N;i++)
    {
        x=rand()%(N-2)+1;
        y=rand()%(N-2)+1;
        maze[x][y]=0;  //0代表路
    }
    maze[1][1]=2;//2代表人站立的位置
    maze[N-2][N-2]=0;
    maze[0][1]=0;//入口
    maze[N-1][N-2]=0;//出口
}
void Draw(int maze[][N])
{
    int x,y;
    system("cls");//清屏
    cout<<endl;
    for(x=0;x<N;x++)
    {
        for(y=0;y<N;y++)
        {
            if(maze[x][y]==0){cout<<"  ";continue;}//通路
            if(maze[x][y]==1){cout<<"■";continue;}//墙
            if(maze[x][y]==2){cout<<"※";continue;}//当前站立位置
        }
        cout<<endl;
    }
}
void JudgeGo(int maze[][N],char ch)
{
    switch(ch)
    {
        case 'L':
        case 'l':
            if(maze[x][y-1]==0) y--;
            break;
        case 'R':
        case 'r':
            if(maze[x][y+1]==0) y++;
            break;
        case 'U':
        case 'u':
            if(maze[x-1][y]==0) x--;
            break;
        case 'D':
        case 'd':
            if(maze[x+1][y]==0) x++;
            break;
    }
    maze[x][y]=2;
}
int main()
{
    int maze[N][N],mx=N-1,my=N-2;
    char ch;
    Ready(maze);
    while(1)
    {
        Draw(maze);
        cin>>ch;
        JudgeGo(maze,ch);
        if(mx==x && my==y) break;
    }
    cout<<"success!";
    return 0;
}
