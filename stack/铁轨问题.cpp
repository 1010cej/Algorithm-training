#include<iostream>
#include<stack>
using namespace std;
const int MAXN = 1110;
int n,target[MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
        stack<int>st;
        int A = 1,B = 1;
        for(int i = 1;i<=n;i++)
            scanf("%d",&target[i]);

        bool ok = true;
        while(B<=n)
        {
            if(A==target[B]) {A++,B++;}
            else if(!st.empty()&&st.top()==target[B]) {st.pop();B++;

            }
            else if(A<=B) st.push(A++);
            else {
                ok = false;break;
            }

        }
        printf("%s \n",ok?"yes":"no");

    }



}
