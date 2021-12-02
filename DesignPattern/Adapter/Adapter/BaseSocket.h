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
	int m_RatedVoltag;		// ���ѹ
	int m_CurrentVoltag;	// ��ǰ��ѹ
};

