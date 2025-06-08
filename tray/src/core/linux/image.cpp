#if defined(__linux__)
#include <core/image.hpp>

Tray::Image::Image(GtkWidget *image) : image(image) {}
Tray::Image::Image(const wchar_t *path) : Image(std::wstring(path)) {}
Tray::Image::Image(const std::wstring &path) : image(gtk_image_new_from_file(path.c_str())) {}

Tray::Image::operator GtkWidget *()
{
    return image;
}
#endif