## p01

算法库中有哪些类型的操作？什么是函数对象？

- 非修改式
    - count 
    - for_each
    - find
- 修改式
    - copy
    - remove_if
- 划分
    - lower_bound
    - upper_bound
- 排序
    - sort
- 集合
    - set_intersetion
    - set_union
- 堆相关
    - push_heap
    - make_heap
- 取最值
    - max
    - min
- 数值操作
    - accumulate
- 未初始化的内存操作
    - uninitialized_copy

函数对象：
    可以以函数方式与()结合使用的任意对象，包括（functor-仿函数）
    1. 函数名；
    2. 指向函数的指针
    3. 重载了()操作符的类对象（寄定义了函数的operator()()类）



## p02

容器、迭代器、算法之间的关系是怎样的？他们是如何结合在一起的？

## p03

什么是迭代器失效问题？该问题是如何产生的？怎样避免产生迭代器失效问题

## p04

Leetcode 127题

https://leetcode-cn.com/problems/word-ladder/

 

字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

每一对相邻的单词只差一个字母。
 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

 
示例 1：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
示例 2：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：0
解释：endWord "cog" 不在字典中，所以无法进行转换。
 

提示：

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord
wordList 中的所有字符串 互不相同

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
