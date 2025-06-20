﻿#pragma once
#include <core/entry.hpp>
#include <functional>

namespace Tray
{
    class Toggle : public TrayEntry
    {
        bool toggled;
        std::function<void(bool)> callback;

      public:
        ~Toggle() override = default;
        Toggle(
            std::wstring text, bool state, std::function<void(bool)> callback = [](bool /**/) {});

        void onToggled();
        bool isToggled() const;
        void setChecked(bool checked, std::function<void(bool)> call_back = [](bool /**/) {});
    };
} // namespace Tray