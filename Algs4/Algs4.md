# 算法4

## 1.基础

### 1.1栈

下压栈API：

`public class Stack<Item> implements Iterable<Item>`

- `boolean isEmpty();`
- `int size();`

- `void push(Item item);`
- `Item pop();`

##### 使用数组实现的下压栈

```java
import edu.princeton.cs.algs4.StdOut;
import java.util.Iterator;

public class ResizingArrayStack<Item> implements Iterable<Item> {
    private Item[] array = (Item[]) new Object[1];
    private int N = 0;

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    public void push(Item item) {
        if (N == array.length) resize(array.length * 2);
        array[N++] = item;
    }

    public Item pop() {
        Item item = array[--N];
        array[N] = null;
        if (N > 0 && N == array.length / 4)
            resize(array.length / 2);
        return item;
    }

    public Iterator<Item> iterator() {
        return new ReverseArrayIterator();
    }

    private void resize(int max) {
        Item[] temp = (Item[]) new Object[max];
        for (int i = 0; i < N; i++)
            temp[i] = array[i];
        array = temp;
    }

    private class ReverseArrayIterator implements Iterator<Item> {
        private int i = N;

        public boolean hasNext() {
            return i > 0;
        }

        public Item next() {
            return array[--i];
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public static void main(String[] args) {
        ResizingArrayStack<Integer> resizingArrayStack = new ResizingArrayStack<Integer>();

        resizingArrayStack.push(20);
        resizingArrayStack.push(32);
        resizingArrayStack.push(321);
        StdOut.println(resizingArrayStack.pop());
        StdOut.println(resizingArrayStack.pop());
        StdOut.println(resizingArrayStack.pop());
    }
}
```

##### 使用链表实现的下压栈

```java
import edu.princeton.cs.algs4.StdOut;
import java.util.Iterator;

public class ListStack<Item> implements Iterable<Item> {
    private Node first;
    private int N = 0;

    private class Node {
        Item item;
        Node next;
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            return current != null;
        }

        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    public void push(Item item) {
        Node oldnode = first;
        first = new Node();
        first.item = item;
        first.next = oldnode;
        ++N;
    }

    public Item pop() {
        Item item = first.item;
        first = first.next;
        --N;
        return item;
    }

    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    public static void main(String[] args) {
        ListStack<Integer> listStack = new ListStack<Integer>();

        listStack.push(12);
        listStack.push(2);
        listStack.push(234);
        StdOut.println(listStack.pop());
        StdOut.println(listStack.pop());
        StdOut.println(listStack.pop());
    }
}

```



### 1.2队列

队列API：

`public class Queue<Item> implements Iterable<Item>`

- `int size();`
- `boolean isEmpty();`
- `void enqueue(Item item);`
- `Item dequeue();`

```java
import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.List;

public class Queue<Item> implements Iterable<Item> {
    private Node first;
    private Node last;
    int N = 0;

    private class Node {
        Item item;
        Node next;
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            return current != null;
        }

        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    public void enqueue(Item item) {
        Node oldlast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if (isEmpty()) first = last;
        else oldlast.next = last;
        N++;
    }

    public Item dequeue() {
        Item item = first.item;
        first = first.next;
        N--;
        if (isEmpty()) last = null;
        return item;
    }

    public ListIterator iterator() {
        return new ListIterator();
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new Queue<Integer>();

        queue.enqueue(32);
        queue.enqueue(53);
        queue.enqueue(2340);
        for (Integer elem : queue) {
            StdOut.println(elem)
        }
        StdOut.println(queue.dequeue());
        StdOut.println(queue.dequeue());
        StdOut.println(queue.dequeue());
        StdOut.println("final size: " + queue.size());
    }
}
```

### 1.3背包

背包API：

`public class Bag<Item> implements Iterable<Item>`

- `int size();`
- `boolean isEmpty();`
- `void add(Item item);`

```java
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.ST;
import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;

public class Bag<Item> implements Iterable<Item> {
    private Node first;
    private int N = 0;

    private class Node {
        Item item;
        Node next;
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            return current != null;
        }

        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    public void add(Item item) {
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        N++;
    }

    public Iterator iterator() {
        return new ListIterator();
    }

    public static void main(String[] args) {
        Bag<Integer> bag = new Bag<Integer>();

        bag.add(120);
        bag.add(32);
        bag.add(42);
        for (Integer elem : bag)
            StdOut.println(elem);
        StdOut.println("current size: " + bag.size());
    }
}
```

### 1.4链表

使用C实现的单链表：

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node{
    struct Node*next;
    char value[1];/* 虽然value数组只有一个字节，但可以通过malloc扩展
                    字节大小，而且还能够很好的获取其指针 */
};


struct List{
    struct Node*first;
    struct Node*last;
    int ListSize;
};


/*
 * 链表初始化
 */
void ListInit(struct List*list){
    list->first=NULL;
    list->last=NULL;
    list->ListSize=0;
}


/*
 * 链表销毁 
 */
void ListDestroy(struct List*list){
    struct Node*node,*temp;

    node=list->first;
    while(node!=NULL){
        temp=node;
        node=node->next;
        free(temp);
    }
    list->first=NULL;
    list->last=NULL;
    list->ListSize=0;
}


/* 
 * 返回链表长度
 */
static inline 
int Size(const struct List*list){
    return list->ListSize;
}


/*
 * 链表是否为空
 */
static inline 
int isEmpty(const struct List*list){
    return list->ListSize==0;
}


/*
 * 链表前向插入数据
 */
struct Node* FInsert(struct List*list,void*value,size_t sz){
    struct Node*newNode;

    if((newNode=malloc(sizeof(struct Node)+sz-1))==NULL)
        return NULL;
    memcpy(newNode->value,value,sz);
    newNode->next=list->first;
    if(isEmpty(list)) list->last=newNode;
    list->first=newNode;
    list->ListSize++;
    return newNode;
}


/*
 * 链表后向插入 
 */
struct Node* BInsert(struct List*list,void*value,size_t sz){
    struct Node*newNode;

    if((newNode=malloc(sizeof(struct Node)+sz-1))==NULL)
        return NULL;
    memcpy(newNode->value,value,sz);
    newNode->next=NULL;
    if(isEmpty(list)) list->first=newNode;
    else list->last->next=newNode;
    list->last=newNode;
    list->ListSize++;
    return newNode;
}


/*
 * 链表普通插入，当node==NULL等同于FInsert() 
 */
struct Node* Insert(struct List*list,struct Node*node,void*value,size_t sz){
    struct Node*newNode;

    if(node==NULL)
        return FInsert(list,value,sz);
    else if(list->first==NULL)
        return NULL;
    if((newNode=malloc(sizeof(struct Node)+sz-1))==NULL)
        return NULL;
    memcpy(newNode->value,value,sz);
    newNode->next=node->next;
    node->next=newNode;
    if(list->last==node)
        list->last=newNode;
    list->ListSize++;
    return newNode;
}


/*
 * 链表前向删除元素 
 */
int FRemove(struct List*list,void*retval,size_t sz){
    struct Node*temp;

    if(isEmpty(list))
        return -1;
    if(retval!=NULL)//若retval非空才选择拷贝待删除元素中的数据
        memcpy(retval,list->first->value,sz);
    temp=list->first;
    list->first=list->first->next;
    free(temp);
    if(list->ListSize==1)
        list->last=NULL;
    list->ListSize--;
    return 0;     
}


//不支持bremove()


/*
 * 普通链表元素删除，当node==NULL时等同于FRemove()
 */
int Remove(struct List*list,struct Node*node,void*retval,size_t sz){
    struct Node*temp;

    if(node==NULL)
        return FRemove(list,retval,sz);
    if(node->next==NULL)
        return NULL;
    temp=node->next;
    node->next=temp->next;
    if(list->last==temp)
        list->last=node;
    if(retval!=NULL)
        memcpy(retval,temp->value,sz);
    free(temp);
    list->ListSize--;
    return 0;
}


/*
 * 链表遍历函数，使用用法类似于strtok() 
 */
struct Node* Iterator(struct List*list){
    static struct Node*node=NULL;
    struct Node*ret=NULL;
    
    if(list!=NULL)
        node=list->first;
    if(node!=NULL){
        ret=node;
        node=node->next;
    }
    return ret;
}


/*
 * 返回链表首元素指针
 */
inline static 
struct Node*First(struct List*list){
    return list->first;
}


/*
 * 返回链表尾元素指针 
 */
inline static 
struct Node*Last(struct List*list){
    return list->last;
}


/*
 * 在链表中查找指定元素 
 */
struct Node*Find(const struct List*list,const void*val,size_t sz,
                int(*pf)(const void*,const void*)){
    struct Node*node=list->first;

    while(node!=NULL){
        if(pf(node->value,val))
            return node;
        node=node->next;
    }
    return NULL;
}


int main(void){
    struct List list;
    double darr[10]={
        1.2,1.4,3.12,3.1,8.3,
        2.4,8.3,3.2,6.4,1.6
    };

    ListInit(&list);
    for(int i=0;i<5;i++)
        Insert(&list,NULL,(void*)&darr[i],sizeof(double));
    for(int i=5;i<10;++i)
        Insert(&list,list.last,(void*)&darr[i],sizeof(double));

    for(const struct Node*p=Iterator(&list);
            p!=NULL;p=Iterator(NULL)){
        printf("%.2f\n",*(double*)(p->value));
    }
    printf("current list size: %d\n",Size(&list));
    ListDestroy(&list);
    printf("final list size: %d\n",Size(&list));
    
    return 0;
}
```

### 1.5算法分析

<img src="image/image-20201029142004452.png" alt="image-20201029142004452" style="zoom: 80%;" />

### 1.6union-find算法

union-find的API：`public class UF`

- `UF(int N)`
- `void find(int p)`
- `int find(int pos)`
- `boolean connected(int p,int q)`
- `int count()`

UF1：使用数组遍历式方式进行连通实现

```java
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class UF1 {
    private int[] id;
    private int count;

    public UF1(int N) {
        id = new int[N];
        count = N;
        for (int i = 0; i < N; i++)
            id[i] = i;
    }

    public int count() {
        return count;
    }

    public int find(int pos) {
        return id[pos];
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public void union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) return;
        for (int i = 0; i < id.length; ++i)
            if (id[i] == pID) id[i] = qID;
        count--;
    }

    public static void main(String[] args) {
        int[] array = In.readInts(args[0]);
        int cnt = 0, N = array[cnt++];
        UF1 uf1 = new UF1(N);

        while (cnt < array.length) {
            int p = array[cnt++];
            int q = array[cnt++];
            if (uf1.connected(p, q)) continue;
            uf1.union(p, q);
            StdOut.println(p + " " + q);
        }
        StdOut.println(uf1.count() + " components");
    }
}
```



UF2：使用节点连接到同一个树根的方式完成连通分量的来链接

```java
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class UF2 {
    private int[] id;
    private int count;

    public UF2(int N) {
        id = new int[N];
        count = N;
        for (int i = 0; i < N; i++)
            id[i] = i;
    }

    public int count() {
        return count;
    }

    public int find(int pos) {
        while (pos != id[pos]) pos = id[pos];
        return pos;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public void union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID != qID) {
            id[pID] = qID;
            count--;
        }
    }

    public static void main(String[] args) {
        int[] array = In.readInts(args[0]);
        int cnt = 0, N = array[cnt++];
        UF2 uf2 = new UF2(N);

        while (cnt < array.length) {
            int p = array[cnt++];
            int q = array[cnt++];
            if (uf2.connected(p, q)) continue;
            uf2.union(p, q);
            StdOut.println(p + " " + q);
        }
        StdOut.println(uf2.count() + " connected");
    }
}
```

图示链接过程：

<img src="image/2020-10-30 200900.png" alt="2020-10-30 200900" style="zoom:67%;" />



UF3：在UF2的基础上增加一个记录连通分量的节点数的数组，每次进行挂载（链接）的时候根据连通分量树的大小将小树挂在大树的根节点上

```java
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class UF3 {
    private int[] id;
    private int[] sz;
    private int count;

    public UF3(int N) {
        id = new int[N];
        sz = new int[N];
        count = N;
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    public int count() {
        return count;
    }

    public int find(int pos) {
        while (pos != id[pos]) pos = id[pos];
        return pos;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public void union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID != qID) {
            //将小树挂在大树的根节点上
            if (sz[pID] < sz[qID]) {
                id[pID] = qID;
                sz[qID] += sz[pID];
            } else {
                id[qID] = pID;
                sz[pID] += sz[qID];
            }
            count--;
        }
    }

    public static void main(String[] args) {
        int[] array = In.readInts(args[0]);
        int cnt = 0, N = array[cnt++];
        UF3 uf3 = new UF3(N);

        while (cnt < array.length) {
            int p = array[cnt++];
            int q = array[cnt++];
            if (uf3.connected(p, q)) continue;
            uf3.union(p, q);
            StdOut.println(p + " " + q);
        }
        StdOut.println(uf3.count() + " connected");
    }
}
```

链接图示：

<img src="image/2020-10-30 211440.png" alt="屏幕截图 2020-10-30 211440" style="zoom: 80%;" />



## 2.排序

公共类API：`public class Sort`

- `private  static boolean less(Comparable lhs, Comparable rhs)`
- `private static void swap(Comparable[] a, int i,int j)`
- `private static void show(Comparable[] a)`
- `public static  boolean isSorted(Comparable[] a)`
- `public static void sort(Comparable[] a)`

封装sort静态方法的类展示如下，后面只展示sort()方法

```java
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import jdk.nashorn.internal.ir.LiteralNode;

public class Sort {
    private static boolean less(Comparable lhs, Comparable rhs) {
        return lhs.compareTo(rhs) < 0;
    }

    private static void swap(Comparable[] a, int i, int j) {
        Comparable temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private static void show(Comparable[] a) {
        for (int i = 0; i < a.length; ++i)
            StdOut.println(a[i]);
    }

    public static boolean isSorted(Comparable[] a) {
        for (int i = 1; i < a.length; i++)
            if (less(a[i], a[i - 1]))
                return false;
        return true;
    }

    public static void sort(Comparable[] a) {
		//见下
    }

    public static void main(String[] args) {
        Integer[] array = new Integer[100];
        for (int i = 0; i < array.length; ++i)
            array[i] = (Integer) StdRandom.uniform(0, 100);

        sort(array);
        show(array);
    }
}

```



### 2.1初级排序

#### 2.1.1选择排序

核心思想就是将依次最小的元素放在数组最前面

```java
    public static void sort(Comparable[] a) {
        for (int i = 0; i < a.length; ++i) {
            int min = i;
            for (int j = i + 1; j < a.length; ++j) {//选取出最小下标
                if (less(a[j], a[min]))
                    min = j;
            }
            swap(a, i, min);
        }
    }
```

#### 2.1.2插入排序

核心思想就是将第j个元素插入到数组前j-1个元素的某个恰当位置中

解法1：

```java
    public static void sort(Comparable[] a) {
        for (int i = 1; i < a.length; ++i) {
            for (int j = i; j > 0 && less(a[j], a[j - 1]); --j)
                swap(a, j, j - 1);
        }
    }
```

解法2：采用移动而不是交换，节省交换成本

```java
    public static void sort(Comparable[] a) {
        for (int i = 1, j; i < a.length; ++i) {
            for (j = i; j > 0 && less(a[j], a[j - 1]); --j)
                a[j] = a[j - 1];
            swap(a, i, j);
        }
    }
```

#### 2.1.3希尔排序

```java
    public static void sort(Comparable[] a) {
        for (int h = a.length / 3; h >= 1; h /= 3) {
            for (int i = h, j; i < a.length; i++) {
                for (j = i; j >= h && less(a[j], a[j - h]); j -= h)
                    swap(a,j,j-h);
            }
        }
    }
```

