#### 专业词汇

**控制序列（或称命令/标记）**： 以反斜杠 `\` 开头，以第一个***空格或非字母\*** 的字符结束的一串文字。它们不被输出，但是他们会影响输出文档的效果。`{article}` 代表这个控制序列有一个必要的参数。

> 分控制序列还有被方括号 `[]` 包括的可选参数。

**宏包** ： 一系列控制序列的合集。这些控制序列太常用，以至于人们会觉得每次将他们写在导言区太过繁琐，于是将他们打包放在同一个文件中，成为所谓的宏包（台湾方面称之为「巨集套件」）。`\usepackage{}` 可以用来调用宏包。

> `CTeX` 宏集的优势在于，它能适配于多种编译方式；在内部处理好了中文和中文版式的支持



## 标准实际案例：

```latex
\documentclass[UTF8]{ctexart} % 调用宏，实现支持中英文
% 这里是导言区 ：对整篇文档进行设置的区域。设置页面大小、页眉页脚样式、章节标题样式等等。

\usepackage{amsmath} %导言区加载 amsmath 宏包：用于编写数学公式。


\title{你好，world!} % 标题
\author{Liam} % 作者
\date{\today} % 日期

% 导言区 在documentclass{article}与begin{document}之间

\begin{document}
\maketitle % 这个控制序列能将在导言区中定义的标题、作者、日期按照预定的格式展现出来。

\tableofcontents % 插入目录 
%\maketitle如果在\tableofcontents后面，那么会自动将目录页与正文分开。

% 环境：两个控制序列之间的内容。
\section{你好中国} %一级节。标题：你好中国。转译后： 1.你好中国
中国在East Asia.
\subsection{Hello Beijing} %二级节。标题：Hello Beijing。转译后： 1.1 Hello Beijing
北京是capital of China.
\subsubsection{Hello District}%三级节。标题：转译后： 1.1.1 Hello District

\paragraph{Tian'anmen Square} %三级节下的一级段落。段落开头加粗语句Tian'anmen Square。
\subparagraph{Chairman Mao}% is in the center of 天安门广场。

\subsection{Hello 山东} %二级节。标题：Hello 山东。转译后： 1.2 Hello 山东

Einstein 's $E=mc^2$. % 使用 $ ... $ 可以插入行内公式


\[ E=mc^2. \] % 插入行间公式

\begin{equation}
\[ z = r\cdot e^{2\pi i}. \]   %自动对着行间公式进行编号。上标或者下标如果想对连续的几个字符起作用，请将这些字符用花括号 {} 括起来。
\end{equation}


\end{document}
```

> 在`report`/`ctexrep`中，还有`\chapter{·}`；在文档类`book`/`ctexbook`中，还定义了`\part{·}`。

这里提一下关于公式标点使用的规范。行内公式和行间公式对标点的要求是不同的：行内公式的标点，应该放在数学模式的限定符之外，而行间公式则应该放在数学模式限定符之内

#### 公式

根式用 `\sqrt{·}` 来表示，分式用 `\frac{·}{·}` 来表示（第一个参数为分子，第二个为分母）。

```latex
\[ \pm\; \times \; \div\; \cdot\; \cap\; \cup\;
\geq\; \leq\; \neq\; \approx \; \equiv \] %一些小的运算符，可以在数学模式下直接输入
```

连加、连乘、极限、积分等大型运算符分别用 `\sum`, `\prod`, `\lim`, `\int` 生成。他们的上下标在行内公式中被压缩，以适应行高。我们可以用 `\limits` 和 `\nolimits` 来强制显式地指定是否压缩这些上下标。

多重积分可以使用 `\iint`, `\iiint`, `\iiiint`, `\idotsint` 等命令输入

```latex
\documentclass{article}
\usepackage{amsmath}
\begin{document}
$\sqrt{x}$, $\frac{1}{2}$.

\[ \sqrt{x}, \]

\[ \frac{1}{2}. \]

$ \sum_{i=1}^n i\quad \prod_{i=1}^n $
$ \sum\limits _{i=1}^n i\quad \prod\limits _{i=1}^n $
\[ \lim_{x\to0}x^2 \quad \int_a^b x^2 dx \]
\[ \lim\nolimits _{x\to0}x^2\quad \int\nolimits_a^b x^2 dx \]

\[ \iint\quad \iiint\quad \iiiint\quad \idotsint \]%多重积分

\end{document}
```

