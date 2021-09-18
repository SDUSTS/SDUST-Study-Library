感谢原作者：beepony
链接：https://www.zhihu.com/question/21682976/answer/79489643

## 基本原理：

**我尝试用类比的方法来解释一下 pull reqeust。**想想我们中学考试，老师改卷的场景吧。你做的试卷就像仓库，你的试卷肯定会有很多错误，就相当于程序里的 bug。老师把你的试卷拿过来，相当于先 fork。在你的卷子上做一些修改批注，相当于 git commit。最后把改好的试卷给你，相当于发 pull request，你拿到试卷重新改正错误，相当于 merge。

**当你想更正别人仓库里的错误时，要走一个流程：**

1. 先 fork 别人的仓库，相当于拷贝一份，相信我，不会有人直接让你改修原仓库的
2. clone 到本地分支，做一些 bug fix
3. 发起 pull request 给原仓库，让他看到你修改的 bug
4. 原仓库 review 这个 bug，如果是正确的话，就会 merge 到他自己的项目中

至此，整个 pull request 的过程就结束了。

## 实际操作例子：

理解了 pull request 的含义和流程，具体操作也就简单了。以 Github 排名最高的 [https://github.com/twbs/bootstrap](https://link.zhihu.com/?target=https%3A//github.com/twbs/bootstrap) 为例说明。
\1. 先点击 fork 仓库，项目现在就在你的账号下了



![img](https://pic3.zhimg.com/50/0d01d6aa4cc4330c525347e5b0a0ecb8_720w.jpg?source=1940ef5c)![img](https://pic3.zhimg.com/80/0d01d6aa4cc4330c525347e5b0a0ecb8_720w.jpg?source=1940ef5c)



![img](https://pic3.zhimg.com/50/6aaed35908e74de871fcbed7c5affb0e_720w.jpg?source=1940ef5c)![img](https://pic3.zhimg.com/80/6aaed35908e74de871fcbed7c5affb0e_720w.jpg?source=1940ef5c)



\2. 在你自己的机器上 git clone 这个仓库，切换分支（也可以在 master 下），做一些修改。

```bash
~  git clone https://github.com/beepony/bootstrap.git
~  cd bootstrap
~  git checkout -b test-pr
~  git add . && git commit -m "test-pr"
~  git push origin test-pr
```

\3. 完成修改之后，回到 test-pr 分支，点击旁边绿色的 Compare & pull request 按钮

![img](https://pic3.zhimg.com/50/3e1ac7f58774a79a5dd6bf8e852e4199_720w.jpg?source=1940ef5c)![img](https://pic3.zhimg.com/80/3e1ac7f58774a79a5dd6bf8e852e4199_720w.jpg?source=1940ef5c)

\4. 添加一些注释信息，确认提交

![img](https://pic3.zhimg.com/50/f5ed68dfe4d60fe90e2fb22ec1933006_720w.jpg?source=1940ef5c)![img](https://pic3.zhimg.com/80/f5ed68dfe4d60fe90e2fb22ec1933006_720w.jpg?source=1940ef5c)

\5. 仓库作者看到，你提的确实是对的，就会 merge，合并到他的项目中



以上就是 pull reqesut 的整个流程，希望对你有帮助～

参考文档：
[Fork A Repo - User Documentation](https://link.zhihu.com/?target=https%3A//help.github.com/articles/fork-a-repo/)
[Using pull requests](https://link.zhihu.com/?target=https%3A//help.github.com/articles/using-pull-requests/)
[Creating a pull request](https://link.zhihu.com/?target=https%3A//help.github.com/articles/creating-a-pull-request/)
