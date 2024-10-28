#pragma once
#include "Object.h"
#include "OSContents/KeyListener.h"


class UKeyManager : public UObject
{
public:
	void SetKeyListener(IKeyListener* KeyListener);
public:
	void Initialize();
	UKeyManager();
	~UKeyManager();

private:
	IKeyListener* m_KeyListener;
};

