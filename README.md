# 世界线变动率探测仪 DivergenceMeter

目标: 还原原作

参考：
1. [想做个辉光管时钟 0 - 想法](https://zhuanlan.zhihu.com/p/37329082)
2. [世界线变动率探测仪制作（一）](https://zhuanlan.zhihu.com/p/28265652)
3. [如何自己制作一个 divergense meter（辉光管时钟）？](https://www.zhihu.com/question/34564116)
4. [用Arduino制作一个功能最基础的辉光钟](https://juejin.cn/post/6844903862793404430)

# 供电
5v type-c
电池组

# 硬件
* 辉光管IN-14*8
* ESP32-C3 或 ESP32-C6
* RTC芯片
* 电容触摸
* ~3D打印外壳~ | ~亚克力雕刻~ | ~注塑~ | ~CNC铝合金件~ |
* 电路板印刷 | ~万用电路板~
* ......

# 软件
* 显示时间 时2-分2-秒2-毫秒 示例： 2 1 2 0 5 2 4 8 9
* 显示日期 年4-月2-日     示例： 2 2 0 2 2 0 7 1 6
* 显示粉丝数 8位最大9999 9999 示例： 0 0 0 0 0 9 9 8
* 网络连接 蓝牙连接
* ntp时间同步
* 内嵌网页
* 随机数生成(时间线检测)
* type-C串口
* 引出剩余的IO, 留出内部空间拓展硬件
* ......