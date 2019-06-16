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
		LOG_INF("%s construction\n", __FUNCTION__);
	}
	virtual ~ReferCount()
	{
		LOG_INF("%s destruction at line %d: refers = %d\n", __FUNCTION__, __LINE__, refers);
	}

	void incCount(void)
	{
		__asm {
			mov		eax, dword ptr[this]
			lea		ecx, dword ptr[eax + 4]
			lock	inc [ecx]
		}
		LOG_INF("%s at line %d: refers = %d\n", __FUNCTION__, __LINE__, refers);
	}

	void decCount(void)
	{
		__asm {
			mov		eax, dword ptr[this]
			lea		ecx, dword ptr[eax + 4]
			lock	dec [ecx]
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

