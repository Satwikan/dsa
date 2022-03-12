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
- Auxilary Space: O(n) [n+1 recursive calls]

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
- Auxilary Space: O(n) [n+1 recursive calls]
