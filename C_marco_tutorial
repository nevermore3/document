### C语言宏定义学习

----------
#### 宏基础  
宏仅仅是在C预处理阶段的一种文本替换工具，编译完之后对二进制代码不可见，基本用法如下： 

-  标示符别名


		#define  BUFFER_SIZE 1024
预处理阶段， `foo = (char*)malloc(BUFFER_SIZE)`; 会被替换成,`foo = (char*)malloc(1024)`  
- 宏函数  
宏后之后带括号的宏被认为是宏函数，其用法和普通函数一样，只不过在预处理阶段，宏函数就会被展开，优点是：没有普通函数保存寄存器和参数传递的开销，有利于CPU cache的利用和指令预测，速度快。 缺点是：可执行代码体积大。
		
		#define ERROR_LOG(module) fprintf(stderr, "error:"#moduele"\n")  
		将ERROR_LOG("add") 转换为 fprintf(stderr, "error: "add"\n");
#### 宏的特殊用法

- 字符串化(Stringification)  
在宏体中，如果宏参数前面加个`#`，那么在宏展开的时候，宏参数就会被扩展成字符串的形式。如：  

		#define WARN_IF(EXP)) \
			do { if (EXP) \
					fprintf(stderr, "Warning: " #EXP "\n"); }\
			while(0)

	`WARN_IF(x == 0)；`会被扩展成：
		
		do{ if(x == 0)
			fprintf(stderr, "Warning: " "x == 0" "\n");}
		while(0)
	这种用法可以用在assert中，如果断言失败，可以将失败的语句输出到反馈信息中。
