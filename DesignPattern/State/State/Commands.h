#pragma once
class Mario;

/// <summary>
/// ����ģʽ����
/// </summary>
class Command {
public:
	virtual void execute(Mario* mario) = 0;
	virtual ~Command() = default;
};

/// <summary>
/// �������ת
/// </summary>
class RunLeftCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};

/// <summary>
/// �������ת
/// </summary>
class RunRighCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};

/// <summary>
/// �������Ծ
/// </summary>
class JumoCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};