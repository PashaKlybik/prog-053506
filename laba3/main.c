#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(0,"");
    int n, s[10000], h[10000], v[10000], i, o;
    printf("¬ведите количество тестов: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("¬ведите рассто€ние от берега до берега:");
        scanf("%d",&s[i]);

        printf("\n¬ведите глубину реки:");
        scanf("%d",&h[i]);

        printf("\n¬ведите скорость течени€ реки:");
        scanf("%d",&v[i]);

        o = s[i]*h[i]*v[i];
        printf("%d\n\n",o);
    }
        free(s);
        free(h);
        free(v);

    return 0;
}
