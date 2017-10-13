## Softmax 函数
---
softmax 用于多分类神经网络输出  
公式如下：   
![](http://upload-images.jianshu.io/upload_images/1667471-c798481b7b366cb2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)  
举例如下：  

![](http://upload-images.jianshu.io/upload_images/1667471-5bf75eefed2154f7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)  
softmax直白来说就是将原来输出是3,1,-3通过softmax函数一作用，就映射成为(0,1)的值，而这些值的累和为1（满足概率的性质），那么我们就可以将它理解成概率，在最后选取输出结点的时候，我们就可以选取概率最大（也就是值对应最大的）结点，作为我们的预测目标  
如上图所示，就是如果某一个Zj打过其他的z，那这个映射的分量就逼近于1，其他就逼近于0，主要应用时多分类。  
为什么要取指数，第一个原因是要模拟max的行为，所以要让大的更大，第二个原因就是需要一个可导的函数。
