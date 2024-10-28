#pragma once
#include "Object.h"
#include "EngineContents/Level.h"
#include "EngineContents/GameInstance.h"
#include "OSContents/GameWindow.h"
#include "OSContents/Timer.h"
#include "EngineContents/KeyManager.h"


/*
	Engine�� �����ϱ� ���ؼ� ���� �� �����ؾ� �ϴ� �Լ�
	1. SetWindow() , �ü���� �´� â Ŭ����
	2. SetTimer() , �ü���� �´� Ÿ�̸� Ŭ����
	3. SetGameInstance() , ������ �����ν��Ͻ�
	4. InitializeKeyManager(), Ű�Է� ���� ���� �Ŵ��� ����
*/
class UEngine : public UObject
{
public:
	void HandleKeyInput();
	void Tick();
	void Render();

public:
	UGameInstance* GetGameInstance();
	UKeyManager* GetKeyManager();
	void InitializeKeyManager(IKeyListener* KeyListener);
	template<typename T>
	void SetGameInstance()
	{
		static_assert(std::is_base_of<UGameInstance, T>::value);
		m_ActiveGameInstance = new T{};
		m_ActiveGameInstance->Initialize();
	}
	void SetWindow(IGameWindow* Window);
	void SetTimer(ITimer* Timer);
	int* GetpWindowCount();

public:
	void Release();
	void Initialize() override;
	static UEngine* GetEngine();
	~UEngine();

private:
	UEngine() = default;

private:
	UKeyManager* m_KeyManager;
	UGameInstance* m_ActiveGameInstance;
	IGameWindow* m_GameWindow;
	ITimer* m_Timer;
private:
	int m_nWindowCount;
};

extern UEngine* GEngine;
