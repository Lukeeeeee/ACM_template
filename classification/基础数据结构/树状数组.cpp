/* from freecode */
#define MAXN 100010

int N;	
int c[MAXN];

int lowbit(int x)
{
    return x & (-x);
}

void add(int d,int x)	//�����Ϊd������x
{
    while(d<=N){
        c[d] += x;
        d += lowbit(d);
    }
}

int sum(int d)		//�������[1,d]Ԫ�صĺ�
{
    int ans =0;
    while(d>=1){
        ans += c[d];
        d -= lowbit(d);
    }
    return ans;
}

