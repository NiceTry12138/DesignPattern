/*
 * @Autor: LC
 * @Date: 2021-11-29 19:33:07
 * @LastEditors: LC
 * @LastEditTime: 2021-11-29 19:33:30
 * @Description: 创建传输方法类
 */

#ifndef TRANPORT_METHOD
#define TRANPORT_METHOD
#include "BaseTransport.h"

// 陆路运输
class TransportLand : public BaseTransport {
public:
	void DoTransport() override;
	void ShowTransportInfo() override;
};

// 水路运输
class TransportLiquid : public BaseTransport {
	void DoTransport() override;
	void ShowTransportInfo() override;
};

// 航空运输
class TransportAir : public BaseTransport {
	void DoTransport() override;
	void ShowTransportInfo() override;
};
#endif