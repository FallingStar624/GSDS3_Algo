#include <stdio.h>
#include <stdlib.h>
/*
다시 풀기
*/

int main()
{
    char st1[1000001], st2[1000001], st3[1000001];
    int top1, top2, top3;
    char str1[1000001], str2[1000001];
    int T, i, j, len;

    scanf("%d", &T);
    getchar();

    for(i=0; i<T; i++){
        top1 = top2 = top3 = -1;

        gets(str1);

        len = strlen(str1);
        for(j=0; j<len; j++){
            switch(str1[j])
            {
            case '<' :
                if(top1 != -1)
                    st2[++top2] = st1[top1--];
                break;
            case '>' :
                if(top2 != -1)
                    st1[++top1] = st2[top2--];
                break;
            case '-' :
                if(top1 != -1)
                    top1--;
                break;
            default :
                st1[++top1] = str1[j];
            }
        }

        while(top2 != -1)
            st1[++top1] = st2[top2--];

        st1[top1+1] = 0;

        printf("%s\n", st1);
    }

    return 0;
}
