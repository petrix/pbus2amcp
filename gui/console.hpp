////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GUI_CONSOLE_HPP
#define GUI_CONSOLE_HPP

////////////////////////////////////////////////////////////////////////////////
#include "ui_console.h"
#include <QTextCharFormat>

////////////////////////////////////////////////////////////////////////////////
namespace gui
{

////////////////////////////////////////////////////////////////////////////////
class console : public QWidget
{
    Q_OBJECT

public:
    ////////////////////
    explicit console(QWidget* parent = nullptr);

    ////////////////////
    void info(const QString& text) { append(text, info_); }
    void crit(const QString& text) { append(text, crit_); }

private:
    ////////////////////
    Ui::console ui_;

    QTextCharFormat info_, crit_;
    void append(const QString&, const QTextCharFormat&);
};

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
