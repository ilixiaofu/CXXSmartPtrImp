#include "SmartPtr.h"
#include "ReferCount.h"
#include "Object.h"

#include<stdio.h>

using namespace std;

int main()
{
	SmartPtr<Object> sPtr = new Object;
	sPtr->fun();
	sPtr = new Object;
}
