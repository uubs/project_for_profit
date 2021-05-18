# 问题 1
- 输入自然数
- 使用non tail recursion, tail recursion, combined recursion解题，并计算递归层次
- 

## 对象
一个文件表示一个对象，变量私有，向其他文件暴露更改变量的全局函数，public里的函数是全局函数


## recursion的种类
- direct recursion
- indirect recursion
- tail recursive
- non tail recursive

### direct recursive
a function is called direct recursive if it calls the same function again
direct recrusive的结构
```c
fun() {
    // some code
    fun();
    // some code
}
```

## indirect recursive
a function (fun) is said indrect recursive if it calls another function(fun2), and then fun2 calls fun directly or indrectly

indirect recursive 的结构
```c
fun() {
    // some code
    fun2();
    // some code
}

fun2() {
    // some code
    fun();
    // some code
}
```

**example**
print 1 to 10, when number is odd, add 1 and when number is even substract 1

```c
void odd();
void even();
int n = 1;

void odd() {
    if (n <= 10) {
        printf("%d ", n + 1);
        ++ n;
        even();
    }
    return ;
}

void even() {
    if (n <= 10) {
        printf("%d ", n + 1);
        ++ n;
        odd();
    }
    return ;
}
```


### tail recursive
tail recursive if the recursive call is the last thing done by the function

there is no need to keep record of the previous state

**example**
```c
void fun(int n) {
    if (n == 0) 
        return;
     else 
        printf("%d ", n);

    return fun(n - 1);
}
```

### non tail recursive
non-tail recursive if the recursive call is not the last thing done by the function

after returning back, there is some something left to evaluate.

```c
void fun(int n) {
    if (n == 0) return;
    fun(n - 1);
    printf("%d", n)

}
```

# 问题 2
list 的大小：n, 从键盘输入

keys 的类型：由变量设置

输入key in any way : random numbers, generate values by a formula, 从文件输入, 从键盘输入

tyep of list : queue, stack, deck, direct single-linked linear list, inverted single-linked linear list, double-linked linear list, single-linked ring list, double-linked ring list, 有变量设置

list type is choosen for the most appropriate solution of the problem set

创建list, 释放list


