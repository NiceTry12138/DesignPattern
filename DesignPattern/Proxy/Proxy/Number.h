#pragma once
#include <string>

/// <summary>
/// Number���࣬�ṩ��Ҫʵ�ֵĻ�������
/// </summary>
class Number {
public:
    // ��ѯ animal��Ӧ��ֵ
    virtual std::pair<bool, int> generate(std::string animal) = 0;
    // ����_key��Ӧ��ֵΪ_val
    virtual void Update(std::string _key, int _val) = 0;
    // ɾ��_key��Ӧ��ֵ
    virtual void Remove(std::string _key) = 0;
    // ���_key��_val�ļ�ֵ��
    virtual void Add(std::string _key, int _val) = 0;
    // չʾ�洢�Ĺ���
    virtual void ShowInfo() const = 0;
    virtual ~Number() = default;
};