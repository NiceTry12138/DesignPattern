#pragma once
class BaseSocket
{
public:
	void SetCurrentVoltag(int voltag);
	int GetRatedVoltag();

	BaseSocket(int ratedvoltag);
	virtual ~BaseSocket();

	void DoWork();

protected:
	virtual void WorkNormal();
	virtual void WorkWarning();

private:
	int m_RatedVoltag;		// 额定电压
	int m_CurrentVoltag;	// 当前电压
};

