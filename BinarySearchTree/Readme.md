# Binary Search Tree

## ![image](https://i.ibb.co/K0qccD6/image-2022-08-16-150004191.png)

### ![image](https://i.ibb.co/SvW3srC/image-2022-08-16-150435243.png)

- if you have operations like search insert or delete than hash table is best but when dealing with operations like find closest. binary search tree should be used.

## Features of Binary Search Tree

- it is not cache friendly, nodes are stored in different memory locations
- we don't need to recycle the memory, we can add or delete nodes
- example:

## ![image](https://i.ibb.co/Hqzmj2H/image-2022-08-17-091708056.png)

```c++
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

```c++
bool search(Node *root, int x) {
    if (root == null) return false;
    if (root->key > x) return search(root->left, x);
    if (root->key < x) return search(root->right, x);
    if (root->key == x) return true;
}
```

### Iterative

```cpp
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

```cpp
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

```cpp
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

```cpp
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

- Note: this getSuccessor function won't give in-order successor in every case but only when right child is not empty, here we are only calling it when we have a right child
- Time Complexity: O(h)
- Space: O(h)

## Floor in a BST

- given (x, a bst)
- return x if x is present else return maximum value < x;

## ![image](https://i.ibb.co/J5tm1Pz/image-2022-08-17-144053396.png)

- my sol

```cpp
Node* floor(Node *root, int x) {
    while (root) {
        if (root->key == x) return x;
        if (root->key > x) {
            if (root->left == NULL) return root;
            root = root->left;
        }
        else {
            if (root->right == NULL) return root;
            root = root->right;
        }
    }
    return NULL;
}
```

- sol

```cpp
Node* floor(Node *root, int x) {
    Node* res = NULL;
    while (root) {
        if (root->key == x) return root;
        else if (root->key > x) root = root->left;
        else {
            res = root;
            root = root->right;
        }
    }
    return res;
}
```

- Time Complexity: O(h)
- Space: O(1)

## Ceil in BST

## ![image](https://i.ibb.co/WkDg59N/image-2022-08-17-150731653.png)

```cpp
Node* ceil(Node *root, int x) {
    Node* res = NULL;
    while (root) {
        if (root->key == x) return root;
        else if (root->key > x) {
            res = root;
            root = root->left;
        }
        else root = root->right;
    }
    return res;
}
```

# Self Balancing Binary Search Tree

- Idea: keep height O(logn)

## ![image](https://i.ibb.co/V3WJWLj/image-2022-08-17-151101188.png)

## ![image](https://i.ibb.co/jVkcTpd/image-2022-08-17-150948044.png)

- if we already will have all keys in advance then we can make perfectly balanced BST

## ![image](https://i.ibb.co/Pjf7W64/image-2022-08-18-165334818.png)

## types of self balancing BST

## AVL Tree

- it is a BST (for every node, left subtree is smaller and right greater)
- it is balanced(for every node, difference between left and right heights does not succeed by 1)

### Insertion in AVL Trees

## ![image](https://i.ibb.co/p2hrjyn/image-2022-08-18-171508260.png)

- perform normal BST insert
- Traverse all ancestors of the newly inserted node from the node to root
- if find an unbalanced node, check for any of the below cases.
- 1 Left Left [Single Rotation]
- 2 Right Right [Single Rotation]
- 3 Left Right [Double Rotation]
- 4 Right Left [Double Rotation]

## ![image](https://i.ibb.co/YDbn0Vc/image-2022-08-18-183330686.png)

### Deletion in AVL Trees

- same as insertion, except after said rotation is done travel to ancestors to fix them through rotations again

### Red Black Tree

- it is used more than AVL trees
- map,set in cpp and java both uses Red Black Tree
- rotations occur less frequently here, because rules are less strict here
- here height may became large than AVL Trees
- so when we require large amount search operations as compared to insertion or deletion operations, AVL Trees are used otherwise Red Black Trees are preferred.

#### Rules

- Every node is either Red or Black
- Root is always black
- No two consecutive Reds
- Number of black nodes from every node to all of it's decedents leaves should be same

## ![image](https://i.ibb.co/3YBKcKW/image-2022-08-18-185613224.png)

#### Most Imbalanced Red Black Trees

## ![image](https://i.ibb.co/z8qQWrF/image-2022-08-18-185908173.png)

## Application of BST

- To maintain sorted of data(or sorted set of data)
- To implement doubly ended priority queue [find both max. and min in same O(1)]
- To solve problems like:

> 1. Count smaller/greater is a stream
> 2. Floor/Ceiling/Greater/Smaller in a stream

- Note: If we only have to deal with operations search, insert and delete or subset of those then it is recommended to use hashmap instead.

### map STL

- it uses BST

## ![image](https://i.ibb.co/9n7BgV2/image-2022-08-20-173520678.png)

- here m[20] will insert {20, 0} into BST
- if you want to check if some key exists or not, use m.at(20) (Note:it will throw exception if 20 is not there)

## Ceiling on Left Side

- print pre-ceiling of a given arr

## ![image](https://i.ibb.co/wc5Rd5w/image-2022-08-20-182159109.png)

- use set(Self Balancing BST)

## ![image](https://i.ibb.co/CVz1JKX/image-2022-08-21-113434559.png)

## Find Kth smallest

- define a data structure that can perform search, insert, delete and find kth smallest operations in efficient time.
- we will use what is called augmented tree, we will add 1 extra variable in the Node that stores no of descendants in left subtree

```cpp
struct Node {
    int key;
    Node *left, *right;
    int lCount;
    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
        lCount = 0;
    }
}
```

## ![image](https://i.ibb.co/rdwh5yX/image-2022-08-21-122317538.png)

- compare (lCount + 1) with k
- If same, return root
- if greater than k, go to left subtree
- if smaller than k, go to right subtree with k = k-lCount-1 (Note: we do this because we are skipping lCount+1 descendants in left subtree)

### How to maintain lCount

- when traversing if you go inside left-subtree increase lCount by 1

## Check for BST

check if given Tree is BST or not

## ![image](https://i.ibb.co/GVGsp65/image-2022-08-21-123226777.png)

## ![image](https://i.ibb.co/PwcDrR5/image-2022-08-21-123331572.png)

## ![image](https://i.ibb.co/JFMnSwb/image-2022-08-21-123512067.png)
## ![image](https://i.ibb.co/Ykw2qYz/image-2022-08-21-125145472.png)
