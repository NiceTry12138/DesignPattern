<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-01 21:09:01
 * @LastEditors: LC
 * @LastEditTime: 2021-12-02 10:06:30
 * @Description: file content
-->
# 观察者模式

## 目标

1. 学生订阅多个老师，获取老师所发布作业
的作业通知系统
2. 学生可以取消订阅老师，老师也可以屏蔽学生的订阅

## 实现

维护两个列表，分别知道所有学生和老师。取消订阅与订阅操作通过列表来实现，消息通知通过老师的基类IPublisher的Modify方法实现
 