#include <stdio.h>
#include <string.h>
int main()
{
    char s[100] = {0, };
    scanf("%s", s);
    char abc[26] = {0, };
    for (int a = 0; a <strlen(s); a++){
        for (int i = 0; i < 26; i++){
            if (s[a] - 'a' == i)
                abc[i]++;
        }
    }
    for (int a = 0; a < 26; a++){
        printf("%d ", abc[a]);
    }
    return 0;
}
