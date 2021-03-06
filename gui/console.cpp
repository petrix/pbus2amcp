////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#include "console.hpp"

#include <QDateTime>
#include <QFont>
#include <QScrollBar>

////////////////////////////////////////////////////////////////////////////////
namespace gui
{

////////////////////////////////////////////////////////////////////////////////
console::console(QWidget* parent) : QWidget(parent)
{
    ui_.setupUi(this);

    QFont font("Courier 10 Pitch");
    font.setStyleHint(QFont::Courier);

    info_ = ui_.text->currentCharFormat();
    info_.setFont(font);

    warn_ = info_;
    warn_.setForeground(Qt::darkYellow);

    fail_ = info_;
    fail_.setForeground(Qt::red);
}

////////////////////////////////////////////////////////////////////////////////
void console::append(const QString& s, const QTextCharFormat& format)
{
    auto bar = ui_.text->verticalScrollBar();
    bool at_max = bar->value() == bar->maximum();

    ui_.text->setCurrentCharFormat(format);
    ui_.text->append(QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss] ") + s);

    if(at_max) bar->setValue(bar->maximum());
}

////////////////////////////////////////////////////////////////////////////////
}
