## Numpy小结

----------
#### Numpy Arrays 通过Numpy可以建立一维或者多维数组，矩阵  
**通过 List 建立数组**  
`List`和`Array`是有区别的，`List`只是一些对象的集合，但是`Array`是一种数据结构。  
我们可以先建立一个`List` 然后再将`List`进行数组化。

	my_list = [1,2,3]  #一维数组
	np.array(my_list)
**通过内置的方法建立数组**  

- arrange  
>arange方法返回一个间隔均匀的值，常用的包含三个参数：起始位置(start)，结束位置(end)，间隔(step)。其中结束位置不包含近返回值，这与`linspace`不同，起始位置默认为0，间隔默认为1，故arange可以只有一个或者两个参数。

	np.arange(10)	
	np.arange(0,10)
	np.arange(0,10,1) #以上三个返回同一个数组。

- zero and ones  
>返回全是0或者全是1的数组。  

	np.zeros(3)  # output: array([0,0,0])
	np.zeros((2,2)) # output: array( [[0,0],[0,0]])
	np.ones(3) #output: array([1,1,1])
	
- linspace  
>linspace 和 arange很相似，有三个参数，前两个相同，最后一个参数，Linspace返回数组是均分起始和结束位置之间的步数。即返回数组内对象的个数。并且linspace包含结束位置。第三个参数的默认值是50.

	np.linspace(0,10,3)  #output: array([0.5.10])

- eye
>返回一个单位矩阵

	np.eye(2)  #output: array([ [1,0],[0,1] ])

### random随机数组  
Numpy返回随机数组的方法有：  

- rand  
>返回一个[0,1)符合均匀分布的数组。  

	np.random.rand(2) #output: array([0.11578797,0.35883472])
	np.random.rand(2,2)

- randn
>返回一个符合正太分布的数组，这个最常用  

	np.random.randn(2) #output: array([-0.12312312,0.9823746])
	np.random.randn(5,5)
- randint  
>返回一个从起始到结束(not include)的随机数，三个参数，起始，结束，个数。  

	np.random.randint(1,100,10) #output: array([13,23,34,65,30,98,46,39,27,12])
- random_sample
> 返回[0,1)之间的浮点数，只能有一个参数，就是浮点数的个数。返回的只能是一维数组。

	np.random.random_sample(10)
- max,min,argmax,argmin
> 返回数组中，最大值，最小值，最大值的下标，最小值的下标。
