#ifndef CSM_PREFS_BOOLSETTING_H
#define CSM_PREFS_BOOLSETTING_H

#include "setting.hpp"

#include <string>
#include <utility>

class QCheckBox;

namespace CSMPrefs
{
    class Category;

    class BoolSetting : public Setting
    {
        Q_OBJECT

        std::string mTooltip;
        bool mDefault;
        QCheckBox* mWidget;

    public:
        BoolSetting(Category* parent, QMutex* mutex, const std::string& key, const QString& label, bool default_);

        BoolSetting& setTooltip(const std::string& tooltip);

        /// Return label, input widget.
        std::pair<QWidget*, QWidget*> makeWidgets(QWidget* parent) override;

        void updateWidget() override;

    private slots:

        void valueChanged(int value);
    };
}

#endif
