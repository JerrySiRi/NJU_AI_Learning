'''
定义一个3行4列的随机矩阵a。
需要利用numpy的切片方法完成以下操作：（1）输出矩阵a的第0行（2）输出a的第2列（3）输出a的最后两列（4）输出a左下角2*2的子矩阵
目标：熟悉numpy切片和索引。
例子：

输入：

a =
[[4 2 3 3]
 [4 3 3 4]
 [3 1 3 2]]

输出：

第0行
[4 2 3 3]

第2列
[3 3 3]

最后两列
[[3 3]
 [3 4]
 [3 2]]

左下角2*2的子矩阵
[[4 3]
 [3 1]]
'''
import numpy as np
a=np.array([[4,2,3,3],[4,3,3,4],[3,1,3,2]])
print(a[0,:])
print(a[:,2])
print(a[:,-2:])
print(a[-2:,0:2])
