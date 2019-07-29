C++ 中常用的STL 有：

1. algorithm:
#include<algorithm>
algorithm 在STL中的应用主要是: sort()   swap()   reverse()   find()
max(), min(), abs()
swap()
reverse()  //reverse(vi.begin(), vi.end());
sort()     // sort(a, a+4);
find()     // find(vi.begin(), vi.end(), 3);
next_permutation()    // could get all sequence for several numbers. 000_algorithm.cpp
fill()     // fill(a, a+5, 233);
*min_element(num,num+6)
*max_element(num,num+6)
lower_bound和upper_bound()

https://blog.csdn.net/weixin_40349531/article/details/88361095

2. math:
#include<cmath>
// #include<math.h>

https://blog.csdn.net/zy2317878/article/details/79414431
https://blog.csdn.net/FX677588/article/details/52962798


3. vector:
#include<vector>
push_back();
pop_back();
begin();
end();
insert();
erase();
find();
at();
size();

http://blog.chinaunix.net/uid-26000296-id-3785623.html
http://blog.chinaunix.net/uid-26000296-id-3785610.html
https://www.cnblogs.com/aminxu/p/4686332.html

4. string:
#include<string>
data();       // 返回指向自己的第一个字符的指针
+=            // 连接操作符
append();
insert();
find();       // if not include, return iterator::end()
replace();
size();
substr();
swap();

http://blog.chinaunix.net/uid-26000296-id-3781405.html
https://www.cnblogs.com/aminxu/p/4686320.html#at

5. set:
#include<set>
// set的特性是，所有元素都会根据元素的键值自动排序.
// set的元素不像map那样可以同时拥有实值(value)和键值(key),set元素的键值就是实值，实值就是键值。
// set不允许两个元素有相同的键值.

https://www.cnblogs.com/omelet/p/6627667.html

6. map:
#include<map>
// map的特性是，所有元素都会根据元素的键值自动被排序。
// map的所有元素都是pair，同时拥有实值(value)和键值(key)。pair的第一个元素会被视为键值，第二个元素会被视为实值。
// map不允许两个元素拥有相同的键值。

map<string , int> strMap;    // constructor
strMap.insert(map<string, int>::value_type("a", 1));
strMap["a"] = 1;             // for insert, will override 覆盖之前的值
size();

https://www.cnblogs.com/omelet/p/6617362.html
https://blog.csdn.net/sevenjoin/article/details/81943864

7. others:
7.1   int <--> string
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
int main()
{
    // int 转 string
    stringstream ss;
    int n = 123;
    string str;
    ss<<n;
    ss>>str;
    cout << str << endl;
    // string 转 int
    str = "456";
    n = atoi(str.c_str());
    cout << n << endl;

    return 0;
}

7.2    int number <--> char
char ch = '2';
int in = ch - '0';

in = in + 1;
char chHigher = in + '0';

7.3    random number:
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define MAX 100
using namespace std;
int  main()
{
    srand( (unsigned)time(NULL) );
    for(int i=0; i<10; i++)
        cout<<rand()%MAX<<endl;

    return 0;
}

https://www.jb51.net/article/124108.htm
