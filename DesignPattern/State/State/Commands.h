#pragma once
class Mario;

/// <summary>
/// 命令模式基类
/// </summary>
class Command {
public:
	virtual void execute(Mario* mario) = 0;
	virtual ~Command() = default;
};

/// <summary>
/// 马里奥左转
/// </summary>
class RunLeftCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};

/// <summary>
/// 马里奥右转
/// </summary>
class RunRighCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};

/// <summary>
/// 马里奥跳跃
/// </summary>
class JumoCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};