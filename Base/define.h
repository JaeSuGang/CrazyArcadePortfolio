#pragma once

#include <assert.h>
#include <Windows.h>

#define ShowError(text) MessageBoxA(0, text, "¿¡·¯", MB_OK); assert(false)