////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef SRC_MEDIA_HPP
#define SRC_MEDIA_HPP

////////////////////////////////////////////////////////////////////////////////
#include <QList>
#include <QString>

////////////////////////////////////////////////////////////////////////////////
namespace src
{

////////////////////////////////////////////////////////////////////////////////
enum type { audio, movie, still };

////////////////////////////////////////////////////////////////////////////////
struct medium
{
    src::type type;
    QString path;
};

////////////////////////////////////////////////////////////////////////////////
using media = QList<medium>;

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif