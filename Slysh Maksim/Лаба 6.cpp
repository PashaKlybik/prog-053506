#include <stdio.h>
#include <locale.h>

template <typename T>
class BinaryTree {
private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;
        Node(T value) {
            data = value;
            this->right = nullptr;
            this->left = nullptr;
        }
    };
    Node* root;
    size_t size;
    Node* insert(Node* node, T data);
    void clear(Node* node);
    int getLongestBranchLenAndSum(Node* current, int length, T& sum);
    void print(Node* current);
public:
    BinaryTree();
    ~BinaryTree();
    void Insert(T value);
    int GetLongestBranchSum(T& sum);
    void Print();
};

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::insert(Node* node, T data) {
    if (node == nullptr) {
        node = new Node(data);
        return node;
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

template <typename T>
void BinaryTree<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
    size = 0;
}
template <typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
    size = 0;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
};

template <typename T>
void BinaryTree<T>::Insert(T value) {
    root = insert(root, value);
    size++;
};

template <typename T>
int BinaryTree<T>::GetLongestBranchSum(T& sum) {
    if (root) {
        int length = getLongestBranchLenAndSum(root, 0, sum);
        return length + 1;
    }
    else {
        return 0;
    }
}

template <typename T>
void BinaryTree<T>::Print() {
    print(root);
    printf("\n");
}

template <typename T>
int BinaryTree<T>::getLongestBranchLenAndSum(Node* current, int length, T& sum) {
    int left = 0, right = 0;
    T sumLeft = 0, sumRight = 0;
    T curSum = sum + current->data;
    sum += current->data;
    if (current->left != nullptr) {
        left = getLongestBranchLenAndSum(current->left, length + 1, sum);
        sumLeft = sum;
        sum = curSum;
    }
    if (current->right != nullptr) {
        right = getLongestBranchLenAndSum(current->right, length + 1, sum);
        sumRight = sum;
        sum = curSum;
    }
    if (left == 0 && right == 0) {
        return length;
    }
    else if (left > right) {
        sum = sumLeft;
        return left;
    }
    else {
        sum = sumRight;
        return right;
    }
}

template <typename T>
void BinaryTree<T>::print(Node* current) {
    if (current != nullptr) {
        if (current->left != nullptr) {
            print(current->left);
        }
        printf("%d ", current->data);
        if (current->right != nullptr) {
            print(current->right);
        }
    }
}

int EnterAndCheckInput() {
    int number;
    while (scanf_s("%d", &number) != 1) {
        printf("Incorrect input! Try again\n");
        while (getchar() != '\n') {
        }
    }
    return number;
}

int main() {
    setlocale(LC_ALL, "rus");
    BinaryTree<int> bnt;
    while (true) {
        printf("Введите элемент деерва (Для завершения введите 0):\n");
        int x = 0;
        x = EnterAndCheckInput();
        if (x != 0) {
            bnt.Insert(x);
        }
        else {
            printf("Вы завершили ввод\n");
            bnt.Print();
            break;
        }
    }
    int sum = 0;
    int length = bnt.GetLongestBranchSum(sum);
    printf("Длинна и Сумма самой длинной ветви: %d", length, sum);
    getchar();
    return 0;
}