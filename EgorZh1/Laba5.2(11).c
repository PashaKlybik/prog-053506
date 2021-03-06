#include<bits.h>

struct node {
    int key;
    struct node *l ,*r;
};

struct node* New(){
    struct node *v;
    v = malloc(sizeof(struct node) * 1);
    v -> key = malloc(sizeof(char) * 100);
    v -> l = v -> r = NULL;
    return v;
}
void upd(struct node *v, char* value ){
    if(v == NULL) return;
    if(value < v -> key) {
        if(v -> l == NULL) {
            v -> l = New();
            strcpy(v -> l -> key, value);
        } else upd(v -> l, value);
    }
    if(value > v -> key) {
        if(v -> r == NULL) {
            v -> r = New();
            strcpy(v -> r -> key, value);
        } else upd(v -> r, value);
    }
}

void Copy(struct node* A, struct node* B) {
    if(B == NULL) B = New();
    if(A == NULL) return;
    B -> key = A -> key;
    if(A -> l) {
        B -> l = New();
        Copy(A -> l, B -> l);
    }
    if(A -> r) {
        B -> r = New();
        Copy(A -> r, B -> r);
    }
    return;
}
int Check(struct node *A, struct node *B) {

    if(A == NULL && B == NULL) return 0;
    if(A == NULL) return 1;
    if(B == NULL) return 1;
    if(A -> key != B -> key) return 1;
    int x = (A -> l ? 1 : 0);
    int y = (A -> r ? 1 : 0);
    int X = (B -> l ? 1 : 0);
    int Y = (B -> r ? 1 : 0);
    if(x != X || y != Y) return 1;
    return (x ? Check(A -> l, B -> l) : 0) + (y ? Check(A -> r, B -> r) : 0);
}
int main()
{
    struct node *A = New();
    A -> key = 1;
    struct node *B = New();
    Copy(A, B);
    printf("%d", Check(A, B));

}
