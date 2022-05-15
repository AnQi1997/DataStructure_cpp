#define _CRT_SECURE_NO_WARNINGS
#include"iostream"
#include"cstring"
#include"cstdio"

using namespace std;
#define INF 0x7f7f7f7f

const int N = 5; //��ĸ�������

int maze[N][N];
int dis[N];
bool vis[N];

//��ĸ����ͱߵ�����
int n, m;

void init()
{
    memset(maze, INF, sizeof(maze));
    memset(dis, INF, sizeof(dis));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++)
    {
        maze[i][i] = 0;
    }
}

void dijkstra(int st)
{
    dis[st] = 0;
    for (int i = 0; i < n; i++)
    {
        //�ҵ�����������̵ĵ�
        int minx = INF;
        int minmark;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && dis[j] <= minx)
            {
                minx = dis[j];
                minmark = j;
            }
        }
        //�����
        vis[minmark] = true;
        //�������к������ӵĵ�ľ���
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && dis[j] > dis[minmark] + maze[minmark][j])
                dis[j] = dis[minmark] + maze[minmark][j];
        }
    }
}


int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0) break;
        //ÿ�����ݶ�Ҫ��ʼ��
        init();
        for (int i = 1; i <= m; i++)
        {
            int x, y, len;
            scanf("%d %d %d", &x, &y, &len);
            if (x != y && maze[x][y] > len)
            {
                maze[y][x] = len;
                maze[x][y] = len;
            }
        }
        //��0Ϊ�����һ��dij
        dijkstra(0);

    }
}
