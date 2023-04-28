# 世界线变动率探测仪 DivergenceMeter

目标: 还原原作

参考：
1. [想做个辉光管时钟 0 - 想法](https://zhuanlan.zhihu.com/p/37329082)
2. [世界线变动率探测仪制作（一）](https://zhuanlan.zhihu.com/p/28265652)
3. [如何自己制作一个 divergense meter（辉光管时钟）？](https://www.zhihu.com/question/34564116)
4. [用Arduino制作一个功能最基础的辉光钟](https://juejin.cn/post/6844903862793404430)
5. [世界线变动率探测仪 | Divergence Meter 项目首页 – Omnixie | 辉光钟](https://nixieclock.org/?p=649)

# 供电
5v type-c
电池组

# 硬件
* 辉光管IN-14*8
* ~ESP32-C3 或 ESP32-C6~
* ESP32-S3
* RTC芯片
* GPS时间校准(预留接口)
* 光敏电阻
* 温湿度传感器
* 蜂鸣器
* 电容触摸按键
* 304不锈钢 激光切割
* 顶板:CEM-1电路板
* 内部普通PCB
* ......

# 软件
* 全部使用RUST开发
* 显示时间 时分秒 示例： 2 1 . 0 5 . 4 8 
* 显示日期 年4-月2-日     示例： 2 0 2 2 0 7 1 6
* 闹钟
* 温湿度
* 光照(自动关闭辉光管)
* ?显示粉丝数 8位最大9999 9999 示例： 0 0 0 0 0 9 9 8
* 网络连接 蓝牙连接
* ntp时间同步
* ?内嵌网页
* 世界线变动率探测
* type-C串口
* 引出剩余的IO, 留出内部空间拓展硬件
