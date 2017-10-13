### tensorflow的流程
---
#### 计算图纸
Tensorflow首先要定义神经网络的结构，然后在把数据放入结构当中去`运算`和`训练`,As follows：  
![](https://morvanzhou.github.io/static/results/tensorflow/1_4_1.png)  
动态图可以点击[这里](https://www.tensorflow.org/images/tensors_flowing.gif)  
  
 因为Tensorflow是采用数据流图来进行计算， 所以首先我们应该创建一个数据流图，然后将我们的数据(数据以张量Tensor形式存在)放到数据流图中计算，节点(Nodes)表示数学操作，图中的edges表示节点间相互联系的多维数组，即张量(Tensor)，训练模型时tensor会不断的从数据流图的一个节点flow到另一个节点，This is How the tensorflow works.
