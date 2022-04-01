# Tree
# Use Cases
## To represent hierarchical data
- Organization Structure
- Folder Structure
- XML/ HTML Content(JSON objects)
- OOP (inheritance)
### BST
### Binary heap
### Parse Tree, Expression Tree in Compilers
## Variations of Tree
- Trie: used in dictonary
- suffix tree: search in large strings
- binary index tree: range based qury searches (fast for certain conditions)
- segment Tree: range based qury searches (more powerfull)
- 
# Binary Tree
- every tree has at-most two children
- ![image](https://user-images.githubusercontent.com/69719072/158005098-9f7ee762-954a-4560-b1bb-098bde047115.png)
## Representation
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
## Tree Traversal
### Depth First Search (DFS)
- L: Left, M: Root Node, R: Right
- Inorder (L M R)
- Preorder (M L R)
- Postorder (L R M)
### Inorder
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

### Preorder
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
### Postorder
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
### Height of binary tree
```
int height(node *root) {
  if (root == NULL) return 0;
  return max(height(root->left), height(right)) + 1;
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h) [max h+1 calls at a time in stack]
### Print Nodes at distance K
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
## Level Order Traversal
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
## Level Order Traversal Line by Line
- ![image](https://user-images.githubusercontent.com/69719072/158051286-cae0b61a-30fb-4ffd-be1f-ab2db1b5ccee.png)
### Method 1
- If we encounter a NULL that means we reached at end of line
```
void LOT(node *root) {
  Queue<node *> q;
  q.push(root);
  q.push(NULL);
  node *temp = NULL;
  while(q.size() > 1) {
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
### Method 2
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
## Size of binary Tree
- for iterative solution, queue can be used code will be similar to Level order traversal
```
int getSize(node * root) {
  if (root == NULL) return 0;
  return 1 + getSize(root->left) + getSize(root->right);
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h) [max h+1 calls at a time in stack]
## Maximum in Binary Tree
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
## Print Left View of binary Tree
- ![image](https://user-images.githubusercontent.com/69719072/158302578-63229751-4dbb-497b-94a3-beaca43393c9.png)
- ![image](https://user-images.githubusercontent.com/69719072/158302616-308beeb9-55ea-4958-aeb1-fd74e5822c17.png)
### Method 1 (recursive)
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
### Method 2 (iterative)
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
## Children Sum Property (CSP)
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
## Check for Balanced Binary Tree
- every root must have difference between height of left subtree and right subtree less than equal 1
- [Refrence Video](https://www.youtube.com/watch?v=cCaeuQxKx3o&list=PL0SWhLkCGuU86tlJinmBwB114wdu8X2WS&index=17)
- Fn returns -1 is not balanced else returns height of the tree/subtree, which can be used by root to calculate it's own height.
```
int isBalanced(node *root) {
  if (root == NULL) return 0;
  int lh = isBalanced(root->left);
  int rh = isBalanced(root->right);
  if ((rh == -1) || (lh == -1) || (abs(lh-rh) > 1)) return -1;
  return max(lh, rh) + 1;
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h)
## Maximum Width of Binary Tree
- Use Level Order Traversal Line by Line
```
int (node *root) {
  Queue<node *> q;
  q.push(root);
  q.push(NULL);
  node *temp = NULL;
  int maxW = 0;
  while(q.size() > 1) {
    q.pop() = temp;
    if (temp == NULL) {
      maxW = maxW < q.size() ? q.size() : maxW;
      q.push(NULL);
      // cout << "\n":
      q.pop() = temp;
    }
    // cout << temp.key << " ";
    if (temp->left != NULL) q.push(temp->left);
    if (temp->right != NULL) q.push(temp->right);
  }
  return maxW;
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h)
## Convert Binary Tree to Doublly Linked List inspace
- [Refrence](https://www.youtube.com/watch?v=U85iBR14sxw&list=PL0SWhLkCGuU86tlJinmBwB114wdu8X2WS&index=19)
- no extra space allocation
- Nodes should be placed by inorder traversal in Doublly LL
- Inorder Traversal
- for next we use right, for prev we use left
```
Node *prev = NULL:
Node* *BTToDLL(Node *root) {
  if (root == NULL) return root;
  Node *head = BTToDLL(root->left);
  if (prev == NULL) head = root; // for 1st node of Double LL
  else {
    root->left = prev;
    prev->right = root;
  }
  prev = root;
  BTToDLL(root->right);
  return head;
}
```
- Time Complexity: O(n) [same as Inorder Traversal]
- Auxilary Space: O(h)
## construct Binary Tree from Inorder and Preorder
- we need atleast Inorder and 1 more traversal(Preorder/Postorder) to construct the binary tree
- check preorder for root and inorder for it's children
- [Refrence](https://www.youtube.com/watch?v=BlCEi0I3RB8&list=PL0SWhLkCGuU86tlJinmBwB114wdu8X2WS&index=22)
```
Node *cTree(int in[], int pre[], int is, int ie) {
  if (is > ie) return NULL;
  Node *root = new Node(pre[preIndex++]);
  int inIndex;
  for(int i = is; i <= ie; i++) {
    if (in[i] == root->key) {
      inIndex++;
      break;
    }
    root->left = cTree(in, pre, is, inIndex-1);
    root->right = cTree(in, pre, inIndex+1, ie);
    return root;
  }
}
```
- Time Complexity: O(n2)
- for Time Complexity: O(n) use hashset to store inOrder keys
## Traverse Tree in Spiral Form
- ![image](https://user-images.githubusercontent.com/69719072/159624490-c9e6e68a-2372-4bc0-9f99-53eecb08de0e.png)
#### Method 1
- use Line by Line Level Order Trversal Method
```
void printSpiral(node *root) {
  Queue<node *> q;
  // ======new lines start=============
  stack <int> s;
  bool reverse = false;
  // ======new lines end=============
  q.push(root);
  node *temp = NULL;
  while(!q.empty()) {
    int count = q.size();
    for (int i = 0; i < count; i++) {
      temp = q.front();q.pop();
      // ======new lines start=============
      if (reverse) s.push(curr->key);
      // ======new lines end=============
      else cout << temp.key << " ";
      if (temp->left != NULL) q.push(temp->left);
      if (temp->right != NULL) q.push(temp->right);
    }
    // ======new lines start=============
    if (reverse) {
      while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
      }
      reverse = !reverse;
    }
    // ======new lines end=============
    cout << "\n";
  }
}
```
#### Method 2
- Method 1 works extra amount of work for reverse nodes
- use 2 stacks s1 s2 instead, push children in alternate stack 
- for s2's children push children in revrerse order
```
void printSpiral(node *root) {
  stack <int> s1;
  stack <int> s2;
  s1.push(root);
  node *temp = NULL;
  while(!s1.empty() || !s2.empty()) {
    while (!s1.empty()) {
      temp = q.top();q.pop();
      cout << temp.key << " ";
      if (temp->left != NULL) s2.push(temp->left);
      if (temp->right != NULL) s2.push(curr->right);
    }
    while (!s2.empty()) {
      temp = q.top();q.pop();
      cout << temp.key << " ";
      if (temp->right != NULL) s1.push(curr->right);
      if (temp->left != NULL) s1.push(temp->left);
    }
    // cout << "\n";
  }
}
```
## Diameter of Binary Tree
- ![image](https://user-images.githubusercontent.com/69719072/159840385-bb7d1d40-f5ef-450d-8d22-feb68dd91e82.png)
```
int maxD = 0;
int diameter(Node *root) {
  if (root == NULL) return 0;
  int lh = diameter(root->left);
  int rh = diameter(root->right);
  maxD = max(1 + lh + rh, maxD);
  return 1 + max(lh, rh);
}
int solution (Node *root) {
  diameter(root);
  return maxD;
}
```
- Time Complexity: O(n)
- Auxilary Space: O(h)
## Lowest Common Ancestor (LCA)
- ![image](https://user-images.githubusercontent.com/69719072/159841786-5ffd9d08-773d-4c3b-a8e1-a498de0a5e1d.png)
### Method 1
```
bool calPath(node *root, int target, vector<Node *>& path){
  if (root == NULL) return false;
  path.push_back(root);
  if (root->key == target) return true;
  if (calPath(root->left, target, path) || calPath(root->right, target, path)) return true;
  p.pop_back();
  return false;
}
Node* lca(Node *root, int n1, int n2){
  vector<Node *> path1, path2;
  if(findPath(root, n1, path1) == false || findPath(root, n2, path2) == false)
    return null;
  for(int i = 0; i < path1.size()-1 && path2.size()-1; i++){
     if(path1[i+1] != path2[i+1]) return path1[i];
  }
  return null;
}
```
- Time Complexity: 0(n) + 0(n) + O(n) = O(n)
### Method 2 (More Efficient, but with assumptions)
- requires only one traversal and 0(h) extra space for the recursive traversal
- assumes that both n1 and n2 exist in the tree. won't give accurate results when only (n1 or n2) exists
- ![image](https://user-images.githubusercontent.com/69719072/160272041-a446f66e-1bfa-4da4-bd09-c134c3961e12.png)
- ![image](https://user-images.githubusercontent.com/69719072/160272047-ea38f82a-4bee-49f7-8da1-0ebf2bdc2e1f.png)
```
Node *lca(Node *root, int n1, int n2) {
  if (root == NULL) return NULL;
  if (root->key == n1 || root->key == n2) return root;
  Node *lca1 = lca(root->left, n1, n2);
  Node *lca2 = lca(root->right, n1, n2);
  if (lca1 != NULL && lca2 != NULL) return root;
  if (lca1 != NULL) return lca1;
  else return lca2;
}
```
## Burn a Binary Tree from Leaf
- ![image](https://user-images.githubusercontent.com/69719072/160273797-0787929d-5950-494f-b261-6b93fc5bb9e0.png)
- find farthest node from given leaf, that will be the ans
- farthest node must be reachable from one of the ancestors of given leaf node
- this function changes distance and returnss hieght
- distance would be -1 if given node is not a descedent of leaf, else it would be dist
```
int res = 0;
// Initially: dist = -1;
int burnTree(Node *root, int leaf, int &dist) {
  if (root == NULL) return 0;
  if (root->data == leaf) {dist = 0; return 1;}
  int ldist = -1, rdist = -1;
  int lh = burnTime(root->left, leaf, ldist);
  int rh = burnTime(root->right, leaf, rdist);
  if (ldist != -1) {
    dist = ldist+1;
    res = max(res, dist+rh);
  } else if (rdist != -1) {
    dist = rdist + 1;
    res = max(res, dist + lh);
  }
  return max(lh, rh) + 1;
}
```
## Count Nodes in a Complete Binary Tree
- [Refrence](https://www.youtube.com/watch?v=aRQgNG32-qI&list=PL0SWhLkCGuU86tlJinmBwB114wdu8X2WS&index=31)
- Complete Binary Tree: every node must has 2 child's
- except last level which must be filled from left to right
- ![image](https://user-images.githubusercontent.com/69719072/161204076-3987c086-b0c2-4a7d-9eda-57beb106a805.png)
### Method 1:
- count all nodes in 0(n) recursivly, (works on every tree)
### Method 2:
- use the fact that it is binary tree
- Time Complexity: O(logn * logn)
```
int countNodes(Node * root) {
  if (root == null) return 0;
  int lh = 0, rh = 0;
  NOde *root = curr;
  while (curr != null) {
    lh++;
    curr = curr->left;
  }
  curr = root;
  while (curr != null) {
    rh++;
    curr = curr->right;
  }
  if (lh == rh) {
    return pow(2, lh) - 1;
  }
  return 1 + countNodes(root->left) + countNodes(root->right);
}
```
- Best Case:when given binary tree is also perfect, then Time Complexity = 0(h) = 0(logn)
- Worst Case: O(logn * logn)
