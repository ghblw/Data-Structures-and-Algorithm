### 第二章 向量（上）

#### (a)接口与实现

模板类

描述区间，左闭右开（右端点为第一个不属于区间的元素）

####(b)可扩充向量

递增策略

倍增策略

平均分析

分摊分析

###第三章 列表

####(a)接口与实现

头哨兵（-1）、首（0）、末（n-1）、尾哨兵(n)

#### (b)无序列表

重载`[]`,实现寻秩访问，O(r)

删除节点：解除拓扑关系

销毁列表：先删除外部可见节点（反复删除header的后继），然后释放header和trailer

唯一化