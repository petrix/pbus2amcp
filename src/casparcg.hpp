////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#ifndef SRC_CASPARCG_HPP
#define SRC_CASPARCG_HPP

////////////////////////////////////////////////////////////////////////////////
#include "media.hpp"

#include <QByteArrayList>
#include <QObject>
#include <QString>
#include <QtNetwork/QTcpSocket>

////////////////////////////////////////////////////////////////////////////////
namespace src
{

////////////////////////////////////////////////////////////////////////////////
class casparcg : public QObject
{
    Q_OBJECT

public:
    ////////////////////
    casparcg(const QString& name, quint16 port, quint16 chan, QObject* parent = nullptr);

    ////////////////////
    void scan();

    void   play(int layer, const QString& path, int from, int to, bool fade_in, bool fade_out, bool loop);
    void  pause(int layer);
    void resume(int layer);
    void   stop(int layer, bool fade_out);

signals:
    ////////////////////
    void opened();
    void closed();
    void failed(const QString&);

    void scanned(const media&);

private:
    ////////////////////
    QTcpSocket socket_;
    quint16 chan_;

    void proc(const QByteArrayList&);
};

////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////
#endif
