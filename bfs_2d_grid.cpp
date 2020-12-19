/*Author : Krishna*/
#include <bits/stdc++.h>
#define ll long long
// taken from code N code channel https://www.youtube.com/watch?v=M4xxztqh8rQ&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=35
using namespace std;

int dist[1001][1001];
int N, M;
int vis[1001][1001];


bool isValid(int x, int y)
{
  if(x<1 || x>N || y <1 || y>M)
    return false;

  if(vis[x][y])
    return false;

  return true;
}

int dx[]={-1, 0 , 1, 0};

int dy[]={0, 1, 0, -1};

 void bfs(int srcX, int srcY)
 {
    queue<pair<int,int>>q;

    q.push({srcX,srcY});
    vis[srcX][srcY]=1;
    dist[srcX][srcY]=0;
    

     while(!q.empty())
     {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

       for(int i=0;i<4;i++)
       {
           if(isValid(currX +dx[i], currY+dy[i]))
           {
             int newX = currX+dx[i];
             int newY = currY+dy[i];
             q.push({newX,newY});

             vis[newX][newY]=1;
             dist[newX][newY]=dist[currX][currY]+1;

           }
       }

     }
     
       cout<<"Distance array\n";
       for(int i=1;i<=N;i++)
       {
        for(int j=1;j<=M;j++)
        {
           cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
       }

 }


int main()
{

  int x,y;
  cin>>N>>M;
  cin>>x>>y;
  bfs(x,y);

}





/*
*Check for the edge cases(n=1)?
*Is there any another approach?
*check for data types
*Keep on thinking
*/
