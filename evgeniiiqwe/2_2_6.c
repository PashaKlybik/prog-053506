#include <math.h>

/*float S(float x, int n)
{
    float s = x;
    float rec = s;

    for (int k = 2; k <= n; k++) {
       rec *= -1*x*x/k/(k+1);
       s+=rec;
    }

    return s;
}*/

float S(float x, int n, float s, int k) {
    if(k==2) return S(x, n, x, k+1);
    else if(k<=n) return S(x, n, s+s*-1*x*x/k/(k+1), k+1);
    else return s;
}

float Y(float x)
{
    return sin(x);
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    float x = 0, a = 0, h = 0, e = 0;
    float y;
    float s;
    float min = -1;
    float founded = 1;

    printf("������� ����� X: "); scanf("%f", &x);
    printf("������� ����� A(�� ������ �������� X ����� �������������): "); scanf("%f", &a);
    printf("������� ����� H(��������� ����� X �� ���): "); scanf("%f", &h);
    printf("������� ����� E(�����������): "); scanf("%f", &e); printf("\n");

    for(; x<a;x+=h) {
        int n = 1;
        y = Y(x);
        s = S(x, n, 0 , 2);
        while(fabs(y-s) > e) {
            s = S(x,n, 0, 2);
            n++;
            if(fabs(y-s) < min || min == -1) min = fabs(y-s);
            if(n > 100) {
                printf("��� �������� x=%f ����������� ������ e �� ����������\n����������� ��������� - %f\n", x, min);
                founded = 0;
                break;
            }
        }

        if(founded == 1)
            printf("��� �������� x=%f ����������� ������ e - %f ��� n=%i\n", x, fabs(y-s), n);
    }


    return 0;
}

// ������� ����� ��� x = 1, a = 3, h = 1, e = 0.2

