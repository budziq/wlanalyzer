/*
 * Copyright © 2014 Samsung Electronics
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef CONNECTION_H
#define CONNECTION_H

#include <pthread.h>
#include <queue>
#include <ev++.h>
#include "socket.h"
#include "request.h"

class WlaConnection
{
public:
    WlaConnection(UnixLocalSocket *client, UnixLocalSocket *server);
    virtual ~WlaConnection();

    void close();

protected:
    void serverHandler(ev::io &watcher, int revents);
    void clientHandler(ev::io &watcher, int revents);

private:
    UnixLocalSocket *_clientSocket;
    UnixLocalSocket *_serverSocket;
    ev::io _clientWatcher;
    ev::io _serverWatcher;

    std::queue<WlaMessage *> _requests;
    std::queue<WlaMessage *> _events;
};

#endif // CONNECTION_H
