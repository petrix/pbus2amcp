////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GUI_PBUS_HPP
#define GUI_PBUS_HPP

////////////////////////////////////////////////////////////////////////////////
#include "src/ports.hpp"
#include "ui_pbus.h"

#include <QtXml/QDomElement>
#include <QWidget>
#include <QXmlStreamWriter>

////////////////////////////////////////////////////////////////////////////////
namespace gui
{

////////////////////////////////////////////////////////////////////////////////
class pbus : public QWidget
{
    Q_OBJECT

public:
    ////////////////////
    explicit pbus(const src::ports&, QWidget* parent = nullptr);

    ////////////////////
    void reset();
    void read(const QDomElement&);
    void write(QXmlStreamWriter&);

    void opened() { set(state::opened); }
    void closed() { set(state::closed); }

signals:
    ////////////////////
    void changed();

    void open(const QString&, int);
    void close();

private:
    ////////////////////
    Ui::pbus ui_;

    enum class state { closed, opening, opened };
    state state_ = state::closed;
    void set(state);

    void update();
};

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
