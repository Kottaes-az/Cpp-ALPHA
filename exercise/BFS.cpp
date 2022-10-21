#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int a[1001][1001];
void BFS(TreeNode *root) {
    queue<TreeNode *> Q;
    Q.push(root);                    //队尾插入根节点
    while (!Q.empty()) {             //不为空
        TreeNode *pNode = Q.front(); // pnode指针指向第一个元素
        printf("[%d]", pNode->val);  //需要执行的操作，这里为输出
        Q.pop();                     //删除第一个元素
        if (pNode->left) Q.push(pNode->left);
        if (pNode->right) Q.push(pNode->right);
    }
}
int main(int argc, char *argv[], char *env) {
    TreeNode a(1), b(2), c(3), d(4), e(5), f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    BFS(&a);
    return 0;
}