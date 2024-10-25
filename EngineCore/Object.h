#pragma once
class UObject
{
public:
	UObject() = default;

private:
	UObject(const UObject& Other) = delete;
	UObject(UObject&& Other) = delete;
	UObject& operator=(const UObject& Other) = delete;
	UObject& operator=(UObject&& Other) = delete;
};

