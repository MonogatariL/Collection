＃记录一些小玩意

1:QQ


为应付答辩设计匆忙制作的qq

![G0PU96OTC`G $C@Q H95P1](https://user-images.githubusercontent.com/73738864/136547683-1b7fab2c-b8ef-40c4-8769-aa362ab06978.png)

![M68M LUTDSM7$BAH)4B4 VE](https://user-images.githubusercontent.com/73738864/136547714-e9d8bd92-b7eb-4fd8-91d5-167bfffceb09.png)

![~7BK@CP4%FNG59~FCUO9D8I](https://user-images.githubusercontent.com/73738864/136547922-6aeb9d94-4ce6-4010-a33f-a318a9552c4a.png)

![Q)8@XWPPKGPSN_)5Y@WUX(5](https://user-images.githubusercontent.com/73738864/136548372-8bcb39be-2a02-4af9-8e67-bad6e1421500.png)

2:Tetris


1、基本游戏界面+键盘操作指令


![20210314141447829](https://user-images.githubusercontent.com/73738864/136546186-3fc510e0-0e65-41c6-870a-a06e25d03dd0.png)

操作指令：
①← ↓ →：分别移动方块向左/下/右移动一格。
②X：立刻下落。
③Z：将方块进行顺时针90°旋转。

2、游戏功能实现思路

①游戏布局：
采用标准的俄罗斯方块规则，游戏布局为10*20，实际游戏布局为10*21，意味着在除了能够观测到的界面最高层上还有隐藏的一层，当有任何方块确定落下后处于该隐藏层，这意味着游戏结束。
在代码层面，我选择用了

QVector<QVector<QPair<bool,bool>>>block;

二维数组便是我们游戏的布局模拟，而QPair<bool,bool>的考虑为：
-first为当前位置是否有方块。
-second为当前位置的方块是否为正在操作的方块。

②方块预设
俄罗斯方块的七种方块O、I、W、S、Z、J、L：
有的只有一种变换形态：O。
有的只有两种变换形态：I、S、Z。
剩余则是四种变换形态：W、J、L。
这意味着一共有20种形态。
例子：方块O（正方形方块）的预设：

if(block[0][5].first==false){block[0][5].first=true;block[0][5].second=true;}else{game_over();return;}
if(block[0][4].first==false){block[0][4].first=true;block[0][4].second=true;}else{game_over();return;}
if(block[1][5].first==false){block[1][5].first=true;block[1][5].second=true;}else{game_over();return;}
if(block[1][4].first==false){block[1][4].first=true;block[1][4].second=true;}else{game_over();return;}
1
2
3
4
在每次预设好一个方块后，我在程序层里使用一个QPair<int,int>对象进行记录。

QPair<int,int>status;
1
这一对象非常重要、这可以直接让程序知道，我们当前操作的图形是什么样的结构，这使得程序可以直接跳过判断其结构而进行变换、下落检测等操作，如在程序里规定status.first为方块的类型，0-6分别对应O、I、W、S、Z、J、L，而status.second则对应first所指向方块的角度。

③判断方块碰撞
游戏是随着定时器不断进行的，定时器初设为1s，也就是1s过后，当前操作方块就要做一次下落，而下落函数的判断规则如下：
-首先找到当前操作的方块，判断其下一格的状态。
-下一格的状态为空（也就是.first的值为false），则说明可以进行向下操作。有
-方块是一个整体，所以我们要探寻四个方块是否都可以进行向下操作，如果有任何一个方块下方已经有确定了的方块，无法执行向下操作时，则所有方块都无法向下，于是乎当前操作的这个方块已经固定，按顺序执行以下步骤（判断是否有一整行可以消除、预设新的方块）。

④方块变化
俄罗斯方块的方块变化规律是顺时针\逆时针 旋转90°，在这里我的规定是将方块设置为顺时针90°旋转，旋转的规则有以下几点：
-方块的旋转不能改变方块的相对位置！！！才开始写方块变化的时候最大的问题就是没有想过方块的位置在旋转的过程中时候相对改变，简单的例子就是按住Z不放旋转方块时候，方块会出现左移、右移、甚至是向上移动的趋向，向上移则完全破坏了游戏规则，而向左向右则会在游玩过程中影响游戏体验。
-第一条是方块旋转的必要设计，至于这一条基础规则则不用多说，方块进行90°旋转必须能够满足模拟旋转，在无法旋转的场景中甚至是无处置放旋转后的方块的场景中肯定是不能进行旋转的。
-紧接上一条，我们知道在模拟旋转的过程中如果无法完成旋转方块是无法做出改变的，但在有些场合我们规定方块可以进行转变。

![20210314151923952](https://user-images.githubusercontent.com/73738864/136546373-03f6bc16-be9b-498f-8d9e-80e71ef7a02e.png)

⑤得分和难度上升
定时器的初设为1s，随着玩家消除的方块增多，定时器的计时会越来越短，从而提升游戏难度。
Timer：1000ms
score：0
每消除一行方块获得100分，每1200分，定时器的时间缩短为Timer=Timer0.9。

3、游戏细节及其他功能

①下一个！
每次需要新方块的时候，系统会生成两个随机数，第一个随机数0-6决定该方块的类型，第二个随机数0-3决定对应方块的对应方向（正方形方块没有其他变化，只有两个变化方向的方块则将随机数%2）。
在俄罗斯方块游戏中基本都会有下一个出现方块的预测，这将给玩家提供一些处理当前方块的思路，为下一个方块的位置做预留和准备。

![20210314153558459](https://user-images.githubusercontent.com/73738864/136546417-55583c16-232f-4ee0-9f5a-2e8ac3e5be16.png)

为了实现这个功能，我们另开一个类似上面的记录对象，改变一下思路，每次随机数的值由status_next储存，当status需要新的数值时候，我们直接将status_next的值给它而不是取随机生成的值。

QPair<int,int>status_next
1
②下落预坠
“没有幻影坦克的俄罗斯方块是没有灵魂的”
按TAB开启下落预坠：

![20210314141943470](https://user-images.githubusercontent.com/73738864/136546500-8a4cbc9c-683c-4d79-b1e5-f148639b92cd.png)

“方块一格一格的下落太慢了，有没有办法让它们快一点”<方向键↓>

“我已经确定这个方块的位置了，没有必要在浪费时间”<X>

“我认为我已经对好方块的位置，只是…不太确定”
TAB：开启下落预坠，从此只看屏幕底端，没有一个方块能让我操作超过1秒。

