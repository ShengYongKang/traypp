#pragma once
#include <string>
#if defined(_WIN32)
#include <Windows.h>
#endif

namespace Tray
{
#if defined(__linux__)
    class Icon
    {
        std::wstring iconPath;

      public:
        Icon(std::wstring path);
        Icon(const char *path);
        operator const char *();
    };
#elif defined(_WIN32)
    class Icon
    {
        HICON hIcon;

      public:
        Icon(HICON icon);
        Icon(WORD resource);
        Icon(const wchar_t *path);
        Icon(const std::wstring &path);

        operator HICON();
    };
#endif
} // namespace Tray