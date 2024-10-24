#pragma once

#include <assert.h>
#include <Windows.h>

#define SHOW_ERROR(text) MessageBoxA(0, text, "¿¡·¯", MB_OK); assert(false)

#define SAFE_DELETE(p) if (p) {delete p; p = nullptr;}