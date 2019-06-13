#pragma once

template <typename T>
class SmartPtr
{
public:
	SmartPtr(T* pObject) : _pObject(pObject)
	{
		_pObject->incCount();
	}

	virtual ~SmartPtr()
	{
		_pObject->decCount();
	}

	SmartPtr(const SmartPtr<T>& refSmartPtr) {
		_pObject = refSmartPtr._pObject;
		_pObject->incCount();
	}

	SmartPtr& operator=(SmartPtr<T>& refSmartPtr) {
		return operator=((T*)refSmartPtr);
	}

	SmartPtr& operator=(T* pObject) {
		pObject->incCount();
		_pObject->decCount();
		_pObject = pObject;
		return *this;
	}

	operator T*() {
		return _pObject;
	}

	T& operator*() {
		return *_pObject;
	}

	T* operator->() {
		return _pObject;
	}

private:
	T* _pObject;
};

