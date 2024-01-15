#include <stdio.h>
#include <stdlib.h> // 添加此头文件以使用 malloc 函数

struct node {
    int data;
    struct node* right;
    struct node* left;
};

void get_info(struct node* b){
    printf("%d\n",b->data);
    printf("%d\n",b->right->data);
    printf("%d\n",b->left->data);
}

void inorder(struct node* n){
    if(n){
        inorder(n -> left);
        printf("%d\n", n->data);
        inorder(n -> right);
    }
}

void get_suc(struct node* root, int target){
    struct node* temp = root;
    while(temp ->right)
    {
        temp = temp->right;
    }
    /*first, we need to determine the node is max of the tree or not*/
    if(temp -> data == target)
    {
        printf("%s\n", "it's max of the tree, no successor");
    }
    /*if it's not the max, we can start to find the successor*/
    else
    {
        /*找左tree max，其實就是precessor*/
        /*如果沒有左tree 則successor是右子點*/
        if(root->left)
        {
            struct node* root_l_max = root->left;
            while(root_l_max -> right)
            {
                root_l_max = root_l_max->right;
            }
            /*if root's precessor value equal to target then we can say root is the scuccessor of target*/
            if(root_l_max->data == target)
            {
                printf("%d\n", root->data);
            }
            /*root's precessor value isn't equal to target*/
            else{
                if (root_l_max -> data > target)
                {
                    get_suc(root->left, target);
                }
                else
                {
                    get_suc(root->right, target);
                }
            }
        }
        else{
            printf("%d\n", root->right->data);
        }
    }
}


int main()
{
    struct node l2_left  = {2, NULL, NULL};
    struct node l1_left  = {3, NULL, &l2_left};
    struct node l2_right = {7, NULL, NULL};
    struct node l1_right = {6, &l2_right, NULL};
    struct node root     = {5, &l1_right, &l1_left};
    
    get_suc(&root, 6);
    return 0;
}
