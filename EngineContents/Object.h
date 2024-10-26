#pragma once
class UObject
{
public:
	virtual void Initialize() = 0;
	UObject() = default;
	virtual ~UObject() = default;

private:
	UObject(const UObject& Other) = delete;
	UObject(UObject&& Other) = delete;
	UObject& operator=(const UObject& Other) = delete;
	UObject& operator=(UObject&& Other) = delete;
};

