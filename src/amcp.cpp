////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Dimitry Ishenko
// Contact: dimitry (dot) ishenko (at) (gee) mail (dot) com
//
// Distributed under the GNU GPL license. See the LICENSE.md file for details.

////////////////////////////////////////////////////////////////////////////////
#include "amcp.hpp"
#include <QTimer>

////////////////////////////////////////////////////////////////////////////////
#define VOID(cl, fn, ...) static_cast<void(cl::*)(__VA_ARGS__)>(&cl::fn)

////////////////////////////////////////////////////////////////////////////////
namespace src
{

////////////////////////////////////////////////////////////////////////////////
amcp::amcp(QAbstractSocket& socket, const QByteArray& cmd, QObject* parent) :
    QObject(parent), socket_(socket)
{
    conn_
    << connect(&socket_, VOID(QAbstractSocket, error, QAbstractSocket::SocketError),
        [&](){ emit fail(socket_.errorString()); }
    )
    << connect(&socket_, &QAbstractSocket::readyRead, this, &amcp::read);

    // delay write to make sure
    // all connections have been established
    QTimer::singleShot(0, [=](){ socket_.write(cmd + "\r\n"); });
}

////////////////////////////////////////////////////////////////////////////////
void amcp::read()
{
    for(;;)
    {
        auto read = socket_.readLine();
        if(!read.size()) break;

        store_ += std::move(read);
        if(!store_.endsWith("\r\n")) continue;

        store_.chop(2);
        switch(state_)
        {
        case state::none:
            {
                auto code = store_.mid(0, store_.indexOf(' '));

                     if(code == "200") state_ = state::data;
                else if(code == "201") state_ = state::data_one;
                else if(code == "202") emit_done();
                else if(code == "400") state_ = state::error_one;
                else if(code == "401") emit_fail("Illegal video channel");
                else if(code == "402") emit_fail("Parameter missing");
                else if(code == "403") emit_fail("Illegal parameter");
                else if(code == "404") emit_fail("Media file not found");
                else if(code == "500") emit_fail("Internal server error");
                else if(code == "501") emit_fail("Internal server error");
                else if(code == "502") emit_fail("Media file unreadable");
                else if(code == "503") emit_fail("Access error");
                else emit_fail("Invalid response: " + store_);

                store_.clear();
            }
            break;

        case state::data_one:
            data_ << store_;
            store_.clear();
            emit_done();
            break;

        case state::data:
            if(store_.size())
            {
                data_ << store_;
                store_.clear();
            }
            else emit_done();
            break;

        case state::error_one:
            emit_fail("Invalid command: " + store_);
            break;

        case state::done:
            while(conn_.size()) disconnect(conn_.takeLast());
            break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void amcp::emit_done()
{
    emit done(data_);
    state_ = state::done;
}

////////////////////////////////////////////////////////////////////////////////
void amcp::emit_fail(const QString& message)
{
    emit fail(message);

    emit done(QByteArrayList());
    state_ = state::done;
}

////////////////////////////////////////////////////////////////////////////////
}
