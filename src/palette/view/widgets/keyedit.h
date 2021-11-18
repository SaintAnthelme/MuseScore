/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __KEYEDIT_H__
#define __KEYEDIT_H__

#include "ui_keyedit.h"

#include "modularity/ioc.h"
#include "ipaletteconfiguration.h"

namespace mu::palette {
class PaletteWidget;
class PaletteScrollArea;
}

namespace Ms {
class KeySig;
class KeyEditor : public QWidget, Ui::KeyEdit
{
    Q_OBJECT

    Q_PROPERTY(bool showKeyPalette READ showKeyPalette WRITE setShowKeyPalette)

    INJECT(palette, mu::palette::IPaletteConfiguration, configuration)

public:
    KeyEditor(QWidget* parent = 0);
    KeyEditor(const KeyEditor& widget);

    bool dirty() const { return _dirty; }
    void save();

    bool showKeyPalette() const;

public slots:
    void setShowKeyPalette(bool showKeyPalette);

private slots:
    void addClicked();
    void clearClicked();
    void setDirty() { _dirty = true; }

signals:
    void keySigAdded(const std::shared_ptr<KeySig>);

private:
    mu::palette::PaletteScrollArea* _keyPalette = nullptr;
    mu::palette::PaletteWidget* sp = nullptr;
    mu::palette::PaletteWidget* sp1 = nullptr;

    bool _dirty = false;
};
} // namespace Ms
#endif
