#include "BaseTransport.h"

BaseTransport::~BaseTransport()
{
	RemoveAllFuniture();
}

inline int BaseTransport::GetFurnitureNum() const
{
	return m_transports.size();
}

void BaseTransport::ShowFurnitreInfo()
{
	for (auto& _obj : m_transports) {
		std::cout << "	furniture : " << _obj->getName() << std::endl;
	}
}

void BaseTransport::AddFurniture(BaseFurniture* _furniture)
{
	this->m_transports.push_back(_furniture);
}

BaseFurniture* BaseTransport::RemoveFurnitureByName(const std::string& name)
{
	for (auto _it = m_transports.begin(); _it != m_transports.end(); ++_it)
	{
		if ((*_it)->getName() == name) {
			BaseFurniture* result = (*_it);
			m_transports.erase(_it);
			return result;
		}
	}
}

void BaseTransport::RemoveAllFuniture()
{
	for (auto _it : m_transports)
	{
		if (_it != nullptr) {
			delete _it;
			_it = nullptr;
		}
	}
	m_transports.clear();
}
