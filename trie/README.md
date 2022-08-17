# TRIE
## Properties
- Efficient for the following operations on words in a dictionary.
- Search
- Insert
- Delete
- Prefix Search
- Lexicographical ordering of words

## ![image](https://i.ibb.co/sjBJDZ6/image-2022-08-01-211300623.png)

## Trie Representation
```
struct TrieNode {
    TrieNode *child[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++) child[i] = NULL;
    }
}
```
