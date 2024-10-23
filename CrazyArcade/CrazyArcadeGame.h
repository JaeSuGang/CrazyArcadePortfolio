#pragma once
class CCrazyArcadeGame
{
public:
	void RunForever();

public:
	void Initialize();
	CCrazyArcadeGame();
	~CCrazyArcadeGame();

private:
	void Release();
	CCrazyArcadeGame(const CCrazyArcadeGame& Other) = delete;
	CCrazyArcadeGame(CCrazyArcadeGame&& Other) = delete;
	CCrazyArcadeGame& operator=(const CCrazyArcadeGame& Other) = delete;
	CCrazyArcadeGame& operator=(CCrazyArcadeGame&& Other) = delete;

private:
	bool m_bIsInitialized;
};

