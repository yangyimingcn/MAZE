# maze3.0
## 前言
这一版本的程序，用户可以向后行走，在走到相同的地方时，可消除多走的路线。用户走过的路使用箭头表示出行走方向。
## 1 代码说明
通过利用struct来声明Node类，保存用户在x、y处的行走方向，从而能够向后行走，并在走到相同的地方时，消除多走的路线。  
在JudgeGo函数中，改变x或y的值时，也在M中记录下用户在x、y处的行走方向。
## 2 使用方法
用户输入L/l，R/r，U/u，D/d，分别表示向左、向右、向上、向下行走，走到出口则成功。

