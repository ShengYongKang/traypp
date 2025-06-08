#if defined(__linux__)
#include <core/icon.hpp>

Tray::Icon::Icon(std::wstring path) : iconPath(std::move(path)) {}
Tray::Icon::Icon(const wchar_t *path) : iconPath(path) {}
Tray::Icon::operator const wchar_t *()
{
    return iconPath.c_str();
}

#endif