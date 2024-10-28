#pragma once
#include "Object.h"
#include "EngineContents/Level.h"
#include "EngineContents/GameInstance.h"
#include "OSContents/GameWindow.h"
#include "OSContents/Timer.h"
#include "EngineContents/KeyManager.h"


/*
	Engine을 실행하기 위해서 설정 및 실행해야 하는 함수
	1. SetWindow() , 운영체제에 맞는 창 클래스
	2. SetTimer() , 운영체제에 맞는 타이머 클래스
	3. SetGameInstance() , 실행할 게임인스턴스
	4. InitializeKeyManager(), 키입력 로직 관련 매니저 설정
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
