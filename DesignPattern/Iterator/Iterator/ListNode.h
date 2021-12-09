#pragma once

template<typename T>
class ListNode
{
public:
	ListNode() : next(nullptr) ,behind(nullptr) {}
	ListNode(T data) : _data(data), next(nullptr), behind(nullptr) {}

	T _data;
	ListNode* next;
	ListNode* behind;
};