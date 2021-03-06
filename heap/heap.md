# 堆

### 堆的实现

##### heap.h中实现了堆，同时提供了两个构造函数

- 直接初始化一个空堆，之后每插入一个元素之后通过shiftUp函数维护最大堆
- 构造函数中传递一个数组，将会通过heapify将数组转化为堆

同时在heap.h中实现了简单的堆的图形化输出操作

##### heapSort.h中实现了三个排序操作

- 算法1:

  按照元素在原数组中的顺序依次向堆中插入
  插入的过程中需要保证每次插入之后仍然是最大堆
  插入完成之后直接取出就是一个有序的数组

- 算法2:

  按照元素的次序依次堆中的数组,
  在插入的时候不用保证每次插入仍然是最大堆
  插入完成之后从最后一个非叶节点开始,对每个子堆执行heapify操作,进而实现最大堆
  之后直接取出就是一个有序数组

- 算法3:

  跟算法2类似,但是算法3直接在原数组上操作

  思路:

  首先对原来的数组进行一次heapify操作,让数组变成一个最大堆
  之后将array[0]和array[n-1]进行交换,最大值到了数组的末尾,
  再对数组除了最后一个元素之外的元素进行一个shiftDown操作，之后第二大的元素将到array【0】的位置
  再次交换
  重复操作，一直到最后

##### 在indexHeap.h中,MaxHeap维护了一个index数组,每次完成最大堆时只会改变index数组,不会更改data数组

因为在修改堆中元素的时候,我们需要遍历整个堆去找到当前数值对应的index下标,因此我们改进之前的算法,维护一个reverse数组,该数组满足 `reverse[inde[i]]=i` `index[reverse[i]]=i` ,可以保证我们在change item的时候直接调用reverse即可找到值和当前data的下标相等的index的下标

### 堆的实现细节优化

- 用赋值替换swap操作

- 将堆从1开始索引设为从0开始

- 动态调整堆大小,不用固定堆的最大容量

- 可以实现最大最小队列

  可以在堆中放两个数组,分别放最大堆和最小堆

- 其他堆:

  - 二项堆
  - 斐波那契堆

### 堆的应用

- 实现优先队列

- 保证角色在攻击的时候总会攻击血量最少的敌人

- 在元素个数为10000的数组中选择前100名元素

  - 思路: 维护一个最小堆,从第101个元素之后,每次将data[0]改变为data[i],之后通过shiftDown函数维护最小堆,最后堆中的元素就是前100个元素
  - 复杂度: 10000log(100)要小于10000log(10000)

- 多路归并排序

  - ![多路归并](多路归并排序.png)

  归并中每个子数组中使用堆,然后每一次比较两个数组最小元素取出最小堆中的堆顶元素

- 当前实现的是一个二叉堆,也可以实现三叉堆,d叉堆