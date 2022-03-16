# Tree
## Use Cases
### To represent hierarchical data
- Organization Structure
- Folder Structure
- XML/ HTML Content(JSON objects)
- OOP (inheritance)
#### BST
#### Binary heap
#### Parse Tree, Expression Tree in Compilers
### Variations of Tree
- Trie: used in dictonary
- suffix tree: search in large strings
- binary index tree: range based qury searches (fast for certain conditions)
- segment Tree: range based qury searches (more powerfull)

## Binary Tree
- every tree has at-most two children
- ![image](https://user-images.githubusercontent.com/69719072/158005098-9f7ee762-954a-4560-b1bb-098bde047115.png)
### Representation
- for below tree
- ![image](https://user-images.githubusercontent.com/69719072/158005307-50157881-37c3-46c1-9360-d49c68b2bef9.png)
```
struct Node {
  int key;
  Node *left;
  Node *right;
  Node(int k) {
  key = k;
  left = right = NULL;
  // we have to initialize as NULL in cpp
  // not in Java
}
int main () {
  // To initialize a empty tree
  // Node *root = NULL;
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
}
```
### Tree Traversal
#### Depth First Search (DFS)
- L: Left, M: Root Node, R: Right
- Inorder (L M R)
- Preorder (M L R)
- Postorder (L R M)
#### Inorder
```
void printInorder(node *root) {
  if (root == NULL) return;
  printInorder(root->left);
  cout << root->key << " ";
  printInorder(root->right);
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h) [h +1 recursive calls]

#### Preorder
```
void printInorder(node *root) {
  if (root == NULL) return;
  cout << root->key << " ";
  printInorder(root->left);
  printInorder(root->right);
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h) [h+1 calls at a time in stack]
#### Postorder
```
void printInorder(node *root) {
  if (root == NULL) return;
  printInorder(root->left);
  printInorder(root->right);
  cout << root->key << " ";
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h) [h+1 calls at a time in stack]
#### Height of binary tree
```
int height(node *root) {
  if (root == NULL) return 0;
  return max(height(root->left), height(right)) + 1;
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h) [max h+1 calls at a time in stack]
#### Print Nodes at distance K
```
void printKDist(node *root, int k) {
  if (root == NULL) return;
  if (k == 0) cout << root->key << " ";
  else {
    printKDist(root->left, k-1);
    printKDist(root->right, k-1);
  }
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h)
### Level Order Traversal
- use queue here, recursion is not recomended
```
void LOT(node *root) {
  Queue<node *> q;
  q.push(root);
  node *temp = NULL;
  while(!q.empty()) {
    q.pop() = temp; 
    cout << temp.key << " ";
    if (temp->left != NULL) q.push(temp->left);
    if (temp->right != NULL) q.push(temp->right);
  }
}
```
- Time Complexity: 0(n) [theta]
- Auxilary Space: 0(w) (width of binary tree)
### Level Order Traversal Line by Line
- ![image](https://user-images.githubusercontent.com/69719072/158051286-cae0b61a-30fb-4ffd-be1f-ab2db1b5ccee.png)
#### Method 1
- If we encounter a NULL that means we reached at end of line
```
void LOT(node *root) {
  Queue<node *> q;
  q.push(root);
  q.push(NULL);
  node *temp = NULL;
  while(!q.empty()) {
    q.pop() = temp;
    if (temp == NULL) {
      q.push(NULL);
      cout << "\n":
      q.pop() = temp;
    }
    cout << temp.key << " ";
    if (temp->left != NULL) q.push(temp->left);
    if (temp->right != NULL) q.push(temp->right);
  }
}
```
- Time Complexity: 0(n) [theta]
- Auxilary Space: 0(w) (width of binary tree)
#### Method 2
- run 2 loops
 ```
 void LOT(node *root) {
  Queue<node *> q;
  q.push(root);
  node *temp = NULL;
  while(!q.empty()) {
    int count = q.size();
    for (int i = 0; i < count; i++) {
      q.pop() = temp;
      cout << temp.key << " ";
      if (temp->left != NULL) q.push(temp->left);
      if (temp->right != NULL) q.push(temp->right);
    }
    cout << "\n";
  }
}
```
### Size of binary Tree
- for iterative solution, queue can be used code will be similar to Level order traversal
```
int getSize(node * root) {
  if (root == NULL) return 0;
  return 1 + getSize(root->left) + getSize(root->right);
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h) [max h+1 calls at a time in stack]
### Maximum in Binary Tree
- for iterative solution, queue can be used code will be similar to Level order traversal
- for iterative Auxilary Space: O(w)
```
int getMax(Node *root) {
  if (root == NULL) return INT_MIN;
  return max(root->key, max(getMax(root->left), getMax(root->left)));
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h) [max h+1 calls at a time in stack]
### Print Left View of binary Tree
- ![image](https://user-images.githubusercontent.com/69719072/158302578-63229751-4dbb-497b-94a3-beaca43393c9.png)
- ![image](https://user-images.githubusercontent.com/69719072/158302616-308beeb9-55ea-4958-aeb1-fd74e5822c17.png)
#### Method 1 (recursive)
- If you do a pre-order traversal of Binary tree, you will always vist leftmost node first
```
int maxLevel = 0;
void printLeft(Node *root, int level) {
  if (root == NULL) return;
  if (maxLevel < level) {
    cout << root->key << " ";
    maxLevel = level;
  }
  printLeft(root->left, level+1);
  printLeft(root->right, level+1);
}
void printLeftView(Node *root) {
  printLeft(root, 1);
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h)
#### Method 2 (iterative)
- Level order traversal Line by Line
```
void printLeft (node *root) {
  if (root == NULL) return;
  Queue<node *> q;
  q.push(root);
  node* curr = NULL;
  int size;
  while(!q.empty) {
    size = q.size();
    for (int i = 0; i < size(); i++) {
      curr = q.pop();
      if (i == 0) cout << (curr->key) << " ";
      if (curr->left != NULL) q.push(curr->left);
      if (curr->right != NULL) q.push(curr->right);
    }
  }
}
```
- Time Complexity: 0(n)
- Auxilary Space: 0(w), O(n)
### Children Sum Property (CSP)
- root must be equal to sum of it's 2 children
- if no children exists or root is NULL, then it's CSP is true
- ![image](https://user-images.githubusercontent.com/69719072/158516103-6a9b47bb-9cf8-476e-a2df-d59bef6218db.png)
```
bool isCSum(node *root) {
  if (root == NULL) return true;
  if (root->left == NULL && root->right == NULL) return true;
  int sum = 0;
  if (root->left != NULL) sum += root->left->key;
  if (root->right != NULL) sum += root->right->key;
  return ((sum == root->key) && isCSum(root->left) && isCSum(root->right));
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h)
