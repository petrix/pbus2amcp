////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GUI_WINDOW_HPP
#define GUI_WINDOW_HPP

////////////////////////////////////////////////////////////////////////////////
#include <QWidget>

////////////////////////////////////////////////////////////////////////////////
namespace gui
{

namespace Ui { class window; }

////////////////////////////////////////////////////////////////////////////////
class window : public QWidget
{
    Q_OBJECT

public:
    explicit window(QWidget* parent = nullptr);
    ~window();

private:
    Ui::window* ui;
};


////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
