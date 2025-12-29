三个操作的本质
1️⃣ insert(word)
  从根开始
  沿着字符往下走
  不存在就新建
  最后一个字符标记 isEnd = true
2️⃣ search(word)
  字符路径必须 完全存在
  并且最后一个节点 isEnd == true
3️⃣ startsWith(prefix)
  只要求路径存在
  不要求是完整单词

#include <bits/stdc++.h>
using namespace std;

//定义Trie节点
class TrieNode{
public:
TrieNode* children[26];//指向26个小写字母的子节点
bool isEnd;//标记是否是一个单词的结尾

//构造函数
TrieNode(){
  //初始化所有子节点为空
  for(int i = 0;i < 26;i++){
    children[i] = nullptr;
  }
  isEnd = false;//默认不是单词结尾
}
};

//Trie类
class Trie{
private:
TrieNode* root;//根节点（不存字符）

public:
//初始化Trie
Trie(){
  root = new TrieNode();//创建根节点
}
//插入单词
void insert(string word){
  TrieNode* cur = root;//从根节点开始

  //遍历单词中的每个字符
  for(char c : word){
    int idx = c - 'a';//将字符映射为0-25

    //如果该字符对应的子节点不存在
    if(cur->children[idx] == nullptr){
      //创建新节点
      cur->children[idx] = new TrieNode();
    }

    //移动到子节点
    cur = cur->children[idx];
  }
  //单词插入完成，标记结尾
  cur->isEnd = true;
    
  }

//查找完整单词
bool search(string word){
  TrieNode* cur = root;//从根节点开始

  //遍历单词中每个字符
  for(char c : word){
    int idx = c - 'a';

    //如果路径中断。说明不存在该单词
    if(cur->children[idx] == nullptr){
      return false;
    }

    //继续向下
    cur = cur->children[idx];
  }
  //必须是一个完整单词的结尾
  return cur->isEnd;
}

//判断是否存在某个前缀
bool startsWith(string prefix){
  TrieNode* cur = root;// 从根节点开始

  //遍历前缀中的每个字符
  for(char c : prefix){
    int idx = c - 'a';

    //如果路径中断，说明该前缀不存在
    if(cur->children[idx] == nullptr){
      return false;
    }

    //继续向下
    cur = cur->children[idx];
  }
  //只要路径存在即可
  return true;
}

};
