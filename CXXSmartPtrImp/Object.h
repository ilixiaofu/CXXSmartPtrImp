#pragma once
#include "ReferCount.h"
class Object : public ReferCount
{
public:
	Object()
	{
		LOG_INF("%s at line %d\n", __FUNCTION__, __LINE__);
	}
	~Object()
	{
		LOG_INF("%s at line %d\n", __FUNCTION__, __LINE__);
	}

	void fun()
	{
		LOG_INF("%s at line %d\n", __FUNCTION__, __LINE__);
	}
};

