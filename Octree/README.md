## octree八叉树数据结构原理与实现
### Octree实现步骤
- 1. 设定最大递归深度
- 2. 找出场景尺寸,并以此建立第一个立方体
- 3. 依次序将单位元素丢入能被包含且没有子节点的立方体
- 4. 若是没有达到最大递归深度,就在进行细分,继续将当前立方体所包含的元素全部分给八个子立方体
- 5. 若是发现子立方体所分配到的单位元素数量不为零且和父立方体数量相同,则停止此子立方体的细分,跟据空间分割理论，细分的空间所得到的分配必定较少，若是一样数目，则再怎么切数目还是一样，会造成无穷切割的情形。
- 6. 重复步骤 => 3，直到达到最大递归深度或者出发其他的条件

### Octree 节点存储 
 - 节点(具体看：三角形 四边形 点线等)  `template`
 - 包围盒 - 立方体的顶点坐标
 - 八个子节点的指针
 


