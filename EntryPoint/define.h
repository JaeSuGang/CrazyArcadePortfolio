#pragma once

#include <assert.h>
#include <Windows.h>

#ifdef NDEBUG
#define SHOW_ERROR(text) ((void)0)
#else
#define SHOW_ERROR(text) MessageBoxA(0, text, "¿¡·¯", MB_OK); assert(false)
#endif

#define SAFE_DELETE(p) if (p) {delete p; p = nullptr;}