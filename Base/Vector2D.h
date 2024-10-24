#pragma once

template <typename T>
class FVector2D
{
public:
	FVector2D(T _x, T _y)
		:
		x{},
		y{}
	{
		x = _x;
		y = _y;
	}

public:
	T x;
	T y;
};
