# Binary Search Tree

## ![image](https://i.ibb.co/K0qccD6/image-2022-08-16-150004191.png)

### ![image](https://i.ibb.co/SvW3srC/image-2022-08-16-150435243.png)

- if you have operations like search insert or delete than hash table is best but when dealing with operations like find closest. binary search tree should be used.

## Features of Binary Search Tree

- it is not cache friendly, nodes are stored in different memory locations
- we don't need to recycle the memory, we can add or delete nodes
- example:

## ![image](https://i.ibb.co/Hqzmj2H/image-2022-08-17-091708056.png)

```

struct Node {
    int key;
    Node *left, *right;
    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
}
```

## Search in BST

- return true or false is some value is present or not.

### Recursive

```
bool search(Node *root, int x) {
    if (root == null) return false;
    if (root->key > x) return search(root->left, x);
    if (root->key < x) return search(root->right, x);
    if (root->key == x) return true;
}
```

### Iterative

```
bool search(Node *root, int x) {
    while (root) {
        if (root->key == x) return true;
        if (root->key > x) root = root->left;
        else root = root->right;
    }
    return false;
}
```

- Time Complexity: O(h)
- Space: O(h) [Recursive]
- Space: O(1) [Iterative]

### BST Insert

## ![image](https://i.ibb.co/1sNwTkM/image-2022-08-17-095625603.png)

## ![image](https://i.ibb.co/ZWXJXDb/image-2022-08-17-104836395.png)

- if value to be inserted is already present, then return same BST.

```
Node *insert(Node *root, int x) {
    if (root == null) return new Node(x);
    if (root->key == x) return;
    if (root->key > x)
        root->left = insert(root->left, x);
    else if (root->key < x)
        root ->right = insert(root->right, x);
    return root;
}
```

- my recursive solution

```
class Solution {
public:
    void search(TreeNode** root, int x) {
        if (*root == NULL) {
            *root =  new TreeNode(x);
            return;
        }
        if ((*root)->val == x) return;
        if ((*root)->val > x) search(&((*root)->left), x);
        if ((*root)->val < x) search(&((*root)->right), x);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        search(&root, val);
        return root;
    }
};
```

### BST Delete

## ![image](https://i.ibb.co/6Xc8qVy/image-2022-08-17-122131093.png)

## ![image](https://i.ibb.co/nfmS1XG/image-2022-08-17-122244386.png)

- if no child is present in nodeToBeDeleted, then simply delete it
- if only one child is present, then substitute that child in that node's place.
- if both child children are present, then add inOrderSuccessor of the node. which would be node that has value just greater than nodeToBeDeleted's value.

```
class Solution {
public:
    TreeNode *getSuccessor(TreeNode *cur) {
        cur = cur->right;
        while(cur != NULL && cur->left != NULL) cur = cur->left;
        return cur;
    }

    TreeNode *deleteNode(TreeNode *root, int x) {
        if (root == NULL) return root;
        if (root->val == x) {
            if (root->left == NULL) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else {
                TreeNode *succ = getSuccessor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        else if (root->val > x)
            root->left = deleteNode(root->left, x);
        else if (root->val < x)
            root ->right = deleteNode(root->right, x);
        return root;
    }
};
```
