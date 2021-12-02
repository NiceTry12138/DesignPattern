<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-01 21:09:01
 * @LastEditors: LC
 * @LastEditTime: 2021-12-01 21:24:38
 * @Description: file content
-->
# 观察者模式

## 目标

1. 学生订阅多个老师，获取老师所发布作业
的作业通知系统
2. 学生可以取消订阅老师，老师也可以屏蔽学生的订阅

## 实现

因为观察者(学生)需要可以订阅多个老师并且可以取消订阅，所以底层需要维护一个数组，用来知道