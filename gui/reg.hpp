////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef GUI_REG_HPP
#define GUI_REG_HPP

////////////////////////////////////////////////////////////////////////////////
#include "src/media.hpp"
#include "src/trigger.hpp"
#include "ui_reg.h"

#include <QtXml/QDomElement>
#include <QWidget>
#include <QXmlStreamWriter>

////////////////////////////////////////////////////////////////////////////////
namespace gui
{

////////////////////////////////////////////////////////////////////////////////
class reg : public QWidget
{
    Q_OBJECT

public:
    ////////////////////
    explicit reg(int n, QWidget* parent = nullptr);

    ////////////////////
    void reset();
    void read(const QDomElement&);
    void write(QXmlStreamWriter&);

    void set(const src::media&);
    void exec(src::trigger);

signals:
    ////////////////////
    void   play(int n, const QString& path, int from, int to, bool fade_in, bool fade_out, bool loop);
    void  pause(int n);
    void resume(int n);
    void   stop(int n, bool fade_out);

private:
    ////////////////////
    Ui::reg ui_;
    int nr_;
};

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
