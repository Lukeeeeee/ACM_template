/* from freecode */

#define MAXN 1010	//���鼯�Ĵ�С

int par[MAXN];    //par[x]��ʾx�ĸ��ڵ�
int n;

void Init()    //��ʼ��
{
    int i;
    for(i=0;i<=n;i++)
        par[i] = i;
}

int Find(int x)    //��ѯx�ĸ��ڵ㲢·��ѹ��
{
    if(par[x]!=x)
        par[x] = Find(par[x]);
    return par[x];
}

void Union(int x,int y)    //�ϲ�x��y���ڼ���
{
    par[Find(x)] = Find(y);
}
