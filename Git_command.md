## Git Command
---
- amend  
> 若想要更改一次提交，使用`git commit --amend`。git会使用与当前提交相同的父节点进行一次新提交，旧的提交会被取消。  某次需求开发提交中，由于某种原因导致提交的结果不是期望的，需要重新提交，但是又不希望前一次的提交使git提交历史树变长，那么可以使用`git commit --amend`来用暂存区的内容修正前一次的提交。 如果不使用带`--amend`的提交，结果是git提交历史树会变长,如下图所示：  

![](http://images2015.cnblogs.com/blog/408483/201604/408483-20160403222318363-136423066.png)

- [cherry-pick](http://pinkyjie.com/2014/08/10/git-notes-part-3/)  
> "复制"一个提交节点并且在当前分支做一次完全一样的提交  

![](https://marklodato.github.io/visual-git-guide/cherry-pick.svg)
