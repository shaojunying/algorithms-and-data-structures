# 二叉树

### 二分查找的实现

- 非递归实现二分查找法


- 递归实现二分查找法
- 使用floor和ceil实现
  - 如果存在target,那么floor返回第一个target下标,ceil返回最后一个的下标
  - 如果不存在target,那么floor返回的是最后一个小于target的下标,ceil返回第一个大于target的下标


### 二叉树

下面的功能函数的private一般都是直接返回以参数node为根节点经过操作之后对应的根节点

 - insert

   - 递归实现
   - 一直遍历,一直到找到一个空节点,返回一个新创建的节点

- contain

  - 递归实现

  - 查找当前数中是否包含目标key,返回true或者false

  - private的contain(递归的函数)

    return: 结果

- search 查找key

- 遍历

  - 递归
    - 前序遍历
    - 中序遍历
    - 后序遍历
  - 层序遍历
    - 非递归
    - 通过一个队列实现

- findMin (findMax)

  - 通过递归找出最小值的key值

- removeMin(removeMax)

  - 通过递归删除树中的最小节点
  - 需要保证整个树中有大于1颗节点

- remove(Key key)

  - 通过递归删除key值对应的节点

- findSuccessor(Node* node)

  - 找到一个节点的前驱节点

- findPredecessor(Node* node)

  - 找到一个节点的后继节点

- floor

  - 找到小于目标key值的最大值对应的节点key值

- ceil

  - 找到大于目标key值的最小值对应的节点key值

- rank

  - 找出一个元素的排名
  - 如果在node中添加新的值,需要在insert和remove中维护

- select

  - 找出排名为n的元素

- 实现支持重复元素的二叉搜索树

  - 为每个节点增加一个count属性
  - 需要维护insert,remove,rank,select

- 平衡二叉树和堆的结合 Treap

- trie![1540965291790](C:\Users\shao\Documents\codingProject\algorithms-and-data-structures\binary-tree\trie)

- 其他树

  - kd树
  - 区间树
  - 哈夫曼树