#include <components/toggle.hpp>
#include <core/traybase.hpp>

Tray::Toggle::Toggle(std::wstring text_info, bool state, std::function<void(bool)> callback)
    : TrayEntry(std::move(text_info)), toggled(state), callback(std::move(callback))
{
}

bool Tray::Toggle::isToggled() const
{
    return toggled;
}

void Tray::Toggle::onToggled()
{
    toggled = !toggled;
    callback(toggled);
}

void Tray::Toggle::setChecked(bool checked, std::function<void(bool)> call_back)
{
    toggled = checked;
    callback(toggled);
    parent->update();
}