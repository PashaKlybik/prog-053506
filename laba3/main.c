#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(0,"");
    int n, s[10000], h[10000], v[10000], i, o;
    printf("������� ���������� ������: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("������� ���������� �� ������ �� ������:");
        scanf("%d",&s[i]);

        printf("\n������� ������� ����:");
        scanf("%d",&h[i]);

        printf("\n������� �������� ������� ����:");
        scanf("%d",&v[i]);

        o = s[i]*h[i]*v[i];
        printf("%d\n\n",o);
    }
        free(s);
        free(h);
        free(v);

    return 0;
}
