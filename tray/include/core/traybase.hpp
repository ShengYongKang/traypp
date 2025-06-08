#pragma once
#include "entry.hpp"
#include "icon.hpp"

#include <memory>
#include <string>
#include <type_traits>
#include <vector>

namespace Tray
{
    class BaseTray
    {
      protected:
        Icon icon;
        std::wstring identifier;
        std::vector<std::shared_ptr<TrayEntry>> entries;
        std::wstring tooltip; // 新增：托盘提示文本

      public:
        BaseTray(std::wstring identifier, Icon icon);

        template <typename... T> void addEntries(const T &...entries)
        {
            (addEntry(entries), ...);
        }
        template <typename T, std::enable_if_t<std::is_base_of<TrayEntry, T>::value> * = nullptr>
        auto addEntry(const T &entry)
        {
            entries.emplace_back(std::make_shared<T>(entry));
            auto back = entries.back();
            back->setParent(this);
            update();

            return std::dynamic_pointer_cast<std::decay_t<T>>(back);
        }
        
        // 新增：设置托盘提示文本
        void setTooltip(const std::wstring& tip) {
            tooltip = tip;
            update();
        }

        // 新增：获取托盘提示文本
        std::wstring getTooltip() const {
            return tooltip;
        }
        
        virtual void run() = 0;
        virtual void exit() = 0;
        virtual void update() = 0;
        std::vector<std::shared_ptr<TrayEntry>> getEntries();
    };
} // namespace Tray