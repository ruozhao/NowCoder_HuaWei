// algorithm
//
// algorithm 在STL中的应用主要是 sort()   swap()   reverse()   find()
//
//vector sort : https://blog.csdn.net/weixin_40349531/article/details/88361095
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(3);
    vi.push_back(0);

    sort(vi.begin(), vi.end()); /// /小到大
    reverse(vi.begin(), vi.end()); /// 从大道小

    vector<int> vi;
    for( int i = 0 ; i < 10 ; i++)
    {
      vi.push_back(i);
    }

    vector<int>::interator it = find(vi.begin(), vi.end(), 3);
    cout << *it << endl ; ///返回容器内找到值的位置。
}
//
//
/*algorithm头文件下的常用函数*/
/*
使用algorithm头文件，需要在头文件下加一行using namespace std;”
*/

//常用函数max(), min(), abs()
//swap()
//reverse()
//next_permutation()
//fill()
//sort()
//lower_bound和upper_bound()


/*max(), min(), abs()的使用*/
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int x =1, y =-2;
    cout <<max(x,y)<< " "<< min(x,y)<<endl;
    cout << abs(x)<<" "<<abs(y)<<endl;

return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
      return a<b;
}
int main()
{
      int num[]={2,3,1,6,4,5};
      cout<<"最小值是 " << *min_element(num,num+6) << endl;
      cout<<"最大值是 " << *max_element(num,num+6) <<endl;
      cout<<"最小值是 " << *min_element(num,num+6,cmp) <<endl;
      cout<<"最大值是 " << *max_element(num,num+6,cmp) <<endl;
      return 0;
}



/*
swap()的使用
swap(x,y)用来交换x和y的值，示例如下：
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int x=1, y=2, z;

    swap(x, y);
    cout<< x << " "<< y<<endl;
    swap(x, z);

    cout<<x<< z <<endl;
    swap(y, z);
    cout<<y<< z <<endl;
    return 0;
}



/*reverse()的使用 */
/*reverse(it, it2)可以将数组指针在[it, it2)之间的元素或容器的迭代器在[it, it2)范围内的元素
进行反转。示例如下： */


 /*对整形数组逆转*/
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    int a[10]= {10, 11, 12, 13, 14, 15};
    reverse(a, a+4);//a[0]~a[3]反转
    for(int i=0; i<6; i++){
        cout<<a[i]<<" ";
    }


    return 0;
}
/*对容器中的元素（例如string字符串）进行反转，结果也一样*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string str = "abcdefghi";
    reverse(str.begin()+2, str.begin()+6);//对a[2]~a[5]逆转*左闭右开*
    for( int i=0; i < str.length(); i++){
        cout<<str[i]<<" ";
    }
    return 0;
}


/*next_permutation的用法
/*@注意!!!* 只有在是个有小到大的序列!!!!!*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    // just show the increase sequence order
    int a[10] = {3, 2, 1};
    do{
        cout<<a[0]<< " "<<a[1]<<" "<<a[2]<<endl;
    }while(next_permutation(a, a+3));


    return 0;
}
// It will show all sequence
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int a[10] = {3, 2, 1, 4, 5};
    int sum = 0;
    bool flag;
    flag = next_permutation(a, a+3);

    do{
        cout<<a[0]<< " "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
        cout << flag << endl;
        sum++;
    }while(flag = next_permutation(a, a+5));

    cout << "the num is " << sum << endl;
    return 0;
}



/*fill()函数 的使用*/
/*
fill()可以把数组或容器中的某一段区间赋为某个相同的值。和memset不同，这里的赋值可以是
数组类型对应范围中的任意值。示例如下：
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int a[5] = {1,2,3,4,5};
    fill(a, a+5, 233);//将a[0]~a[4]赋值为233
    for(int i=0; i<5; i++){
        cout<<a[i]<<endl;
    }
    return 0;
}

/*sort()函数的使用*/
//sort()使用 ：sort(首元素地址(必填), 尾元素地址的下一个地址(必填), 比较函数(非必填));
//如果不填写比较函数默认是递增数列

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int a[6] = {9, 4, 2, 5, 6, -1};
    //将a[0]~a[3]从小到大排序
    sort(a, a+4);
    for( int i = 0; i<6; i++){
        cout<<*(a+i)<<" ";
    }
    cout<<" "<<endl;

    sort(a, a+6);//将a[0]~a[5]从小到大排序
    for( int i = 0; i<6; i++){
        cout<<*(a+i)<<" ";
    }

    return 0;
}




/*cmp函数的使用 */

/*(1)cmp对于整型数组*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


bool cmp(int a, int b)
{
    return a > b;  //可以理解为当a>b时把a放在b前面
}

int main()
{
    int a[4] = {3, 1, 4,2};
    sort(a,a+4,cmp);
    for(int i=0; i<4; i++){
        cout<<*(a+i)<<" ";
    }

    return 0;
}


/*(2)同样对char型数组*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


bool cmp(char a, char b)
{
    return a > b;  //可以理解为当a>b时把a放在b前面
}

int main()
{
    char a[4] = {'a', 'b', 'c','d'};
    sort(a,a+4,cmp);
    for(int i=0; i<4; i++){
        cout<<*(a+i)<<" ";
    }

    return 0;
}



/*(3)对结构体数组排序*/

/*定义结构体：
struct node｛
    int x, y;
}ssd[10];
bool cmp(node a, node b)
{
    return a.x>b.x;//
}
*/
//示例如下：

#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    int x, y;
}ssd[10];

bool cmp(node a,node b)
{
    return a.x > b.x; //按x值从大到小对结构体数组排序
}

int main()
{
    ssd[0].x =2;ssd[0].y=2;
    ssd[1].x =1;ssd[1].y=3;
    ssd[2].x =3;ssd[2].y=1;
    sort(ssd, ssd+3, cmp);//排序

    for( int i=0; i<3; i++){
    cout<< ssd[i].x <<endl;
    }
    cout<<" "<<endl;
    return 0;
}



/*lower_bound()和upper_bound()的使用 */
//lower_bound()和upper_bound() 需要用在一个有序数组或容器中

/*
lower_bound(first, last, val)寻找数组或容器中[first, last)范围内第一个值大于等于val的元素位置,
如果是数组则返回该位置的指针；如果是容器则返回该位置的迭代器
upper_bound(first, last, val)寻找数组或容器中[first, last)范围内第一个值大于val的元素位置,
如果是数组则返回该位置的指针；如果是容器，则范围该位置的迭代器
**注意**
如果数组或容器中没有需要寻找的元素，则lower_bound()和upper_bound()均返回可以插入该元素的位置的指针或迭代器
(即假设存在该元素，该元素应当在的位置)
lower_bound()和upper_bound()的复杂度均为O(log(last-first))
*/

//示例如下：

#include<iostream>
#include<algorithm>

using namespace std;



int main()
{
    int a[10]={1,2,2,3,3,3,5,5,5,5};

    //寻找-1
    int* lowerPos = lower_bound(a, a+10, -1);
    int* upperPos = upper_bound(a, a+10, -1);
    cout<<lowerPos-a<< " "<<upperPos-a<< endl;

    //寻找1
    lowerPos = lower_bound(a, a+10, 1);
    upperPos = upper_bound(a, a+10, 1);
    cout<<lowerPos-a<< " "<<upperPos-a<< endl;

    //寻找2
    lowerPos = lower_bound(a, a+10, 2);
    upperPos = upper_bound(a, a+10, 2);
    cout<<lowerPos-a<< " "<<upperPos-a<< endl;

    //寻找3
    lowerPos = lower_bound(a, a+10, 3);
    upperPos = upper_bound(a, a+10, 3);
    cout<<lowerPos-a<< " "<<upperPos-a<< endl;

    //寻找4
    lowerPos = lower_bound(a, a+10, 4);
    upperPos = upper_bound(a, a+10, 4);
    cout<<lowerPos-a<< " "<<upperPos-a<< endl;

    //寻找6
    lowerPos = lower_bound(a, a+10, 6);
    upperPos = upper_bound(a, a+10, 6);
    cout<<lowerPos-a<< " "<<upperPos-a<< endl;

    return 0;
}
