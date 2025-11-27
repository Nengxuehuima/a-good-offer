思路
要同时满足 O(1) 访问和删除：
  用 哈希表（unordered_map） 实现 O(1) 查找；
  用 双向链表（list） 记录访问顺序。
✅ get(key)
如果 key 不存在 → 返回 -1；
如果存在：
  把该节点移到链表头（代表最近使用）；
  返回 value。
✅ put(key, value)
如果 key 已存在：
  更新 value；
  把该节点移到链表头；
如果 key 不存在：
  若容量未满 → 直接插入到链表头；
  若容量已满：
    删除链表尾节点（最久未使用的）；
    同时从哈希表删除该 key；
  然后插入新节点到链表头，并更新 map。

#include <bits/stdc++>
using namespace std;

class LRUCache{
private:
  int capacity;//缓存容量
  list<pair<int,int>> cache;//双向链表（key，value）
  unordered_map<int,list<pair<int,int>>::interator> mp;//哈希表：key-> 链表节点迭代器

public:
//构造函数
  LRUCache(int capacity){
    this->capacity = capacity;
  }
  
  //获取key对应的值
  int get(int key){
    //如果键不存在
    if(mp.find(key) == mp.end())  return -1;
  
    //如果键存在,将该节点移动到链表头部
    auto it = mp[key];
    int val = it->second;
    cache.erase(it);//从原位置删除
    cache.push_front({key,val});//插入到头部
    mp[key] = cache.begin();//更新哈希表中的迭代器
    return val;
  }
  
  //插入或更新key-value
  void put(int key,int value){
    //1、如果key已存在，先删除旧节点
    if(mp.find(key) != mp.end()){
      cache.erase(mp[key]);
      mp.erase(key);
    }
  
    //2、如果缓存已满，删除最久未使用的节点(链表尾)
    if((int)cache.size() == capacity){
      auto last = cache.back();//尾部节点
      mp.erase(last.first);//从哈希表删除
      cache.pop_back();//从链表删除
    }
  
    //3、插入新节点到链表头
    cache.push_front({key,value});
    mp[key] = cache.begin();
  }
};

