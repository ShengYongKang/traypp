#if defined(_WIN32)
#include <core/icon.hpp>

Tray::Icon::Icon(const std::wstring &path)
    : hIcon(reinterpret_cast<HICON>(
          LoadImageW(nullptr, path.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE)))
{
}
Tray::Icon::Icon(HICON icon) : hIcon(icon) {}
Tray::Icon::Icon(const wchar_t *path) : Icon(std::wstring(path)) {}
Tray::Icon::Icon(WORD icon) : hIcon(LoadIcon(GetModuleHandle(nullptr), MAKEINTRESOURCE(icon))) {} // NOLINT

Tray::Icon::operator HICON()
{
    return hIcon;
}

#endif