#pragma once

#include<stdio.h>

#ifndef LOG_INF
#define LOG_INF printf
#endif

class ReferCount
{
public:
	ReferCount():refers(0)
	{
		LOG_INF("%s at line %d: refers = %d\n", __FUNCTION__, __LINE__, refers);
	}
	virtual ~ReferCount()
	{
		LOG_INF("%s at line %d: refers = %d\n", __FUNCTION__, __LINE__, refers);
	}

	void incCount(void)
	{
		__asm {
			mov eax, [refers]
			lock inc eax
			mov [refers], eax
		}
		LOG_INF("%s at line %d: refers = %d\n", __FUNCTION__, __LINE__, refers);
	}

	void decCount(void)
	{
		__asm {
			mov eax, [refers]
			lock dec eax
			mov [refers], eax
		}

		if (refers == 0) {
			LOG_INF("%s at line %d: refers = %d\n", __FUNCTION__, __LINE__, refers);
			delete this;
		}
		else {
			LOG_INF("%s at line %d: refers = %d\n", __FUNCTION__, __LINE__, refers);
		}
	}

private:
	int refers;
};

