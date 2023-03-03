#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define N 20
struct Node
{
	int x;
	int y;
	int direction;
}M[N*N];
int step=0;
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
	maze[0][1]=4;//入口
	maze[N-1][N-2]=0;//出口
	M[step].x=0;
	M[step].y=1;
	M[step].direction=4;
}
void Draw(int (*p)[N])
{
    int x,y;
	system("cls");//清屏
	cout<<endl;
	for(x=0;x<N;x++)
	{
		for(y=0;y<N;y++)
		{
			if(*(*(p+x)+y)==0){cout<<"  ";continue;}//通路
			if(*(*(p+x)+y)==1){cout<<"■";continue;}//墙
			if(*(*(p+x)+y)==2){cout<<"※";continue;}//当前站立位置
			if(*(*(p+x)+y)==3){cout<<"↑";continue;}//向上走
			if(*(*(p+x)+y)==4){cout<<"↓";continue;}//向下走
			if(*(*(p+x)+y)==5){cout<<"←";continue;}//向左走
			if(*(*(p+x)+y)==6){cout<<"→";continue;}//向右走
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
            if(maze[x][y-1]==0)
            {
                maze[x][y]=5;
                step++;
                M[step].x=x;
                M[step].y=y;
                M[step].direction=maze[x][y];
                y--;
            }
            else if(maze[x][y-1]==6)  //右
            {
                maze[x][y]=0;
                step--;
                y--;
            }
            else if(maze[x][y-1]==3||maze[x][y-1]==4){  // 上下
            	maze[x][y]=0;
            	y--;
            	while(1){
            		maze[M[step].x][M[step].y]=0;
            		step--;
            		if(M[step].x==x&&M[step].y==y){step--;break;}
				}
			}
            break;
        case 'R':
        case 'r':
            if(maze[x][y+1]==0)
            {
                maze[x][y]=6;
                step++;
                M[step].x=x;
                M[step].y=y;
                M[step].direction=maze[x][y];
                y++;
            }
            else if(maze[x][y+1]==5)  //左
            {
                maze[x][y]=0;
                step--;
                y++;
            }
            else if(maze[x][y+1]==3||maze[x][y+1]==4){  // 上下
            	maze[x][y]=0;
            	y++;
            	while(1){
            		maze[M[step].x][M[step].y]=0;
            		step--;
            		if(M[step].x==x&&M[step].y==y){step--;break;}
				}
			}
            break;
        case 'U':
        case 'u':
            if(maze[x-1][y]==0)
            {
                maze[x][y]=3;
                step++;
                M[step].x=x;
                M[step].y=y;
                M[step].direction=maze[x][y];
                x--;
            }
            else if(maze[x-1][y]==4)  //下
            {
                maze[x][y]=0;
                step--;
                x--;
            }
            else if(maze[x-1][y]==5||maze[x-1][y]==6){  // 左右
            	maze[x][y]=0;
            	x--;
            	while(1){
            		maze[M[step].x][M[step].y]=0;
            		step--;
            		if(M[step].x==x&&M[step].y==y){step--;break;}
				}
			}
            break;
        case 'D':
        case 'd':
            if(maze[x+1][y]==0)
            {
                maze[x][y]=4;
                step++;
                M[step].x=x;
                M[step].y=y;
                M[step].direction=maze[x][y];
                x++;
            }
            else if(maze[x+1][y]==3)  //上
            {
                maze[x][y]=0;
                step--;
                x++;
            }
            else if(maze[x+1][y]==5||maze[x+1][y]==6){  // 左右
            	maze[x][y]=0;
            	x++;
            	while(1){
            		maze[M[step].x][M[step].y]=0;
            		step--;
            		if(M[step].x==x&&M[step].y==y){step--;break;}
				}
			}
            break;
        }
    maze[x][y]=2;
}
int main()
{
    int maze[N][N];
    int mx=N-1,my=N-2;
    char ch;
    Ready(maze);
    while(1)
    {
        Draw(maze);
        cin>>ch;
        JudgeGo(maze,ch);
        if(mx==x && my==y) break;
    }
    cout<<"success!"<<endl;
    return 0;
}

