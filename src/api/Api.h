/* XMRig
 * Copyright 2014      imonero <https://github.com/global-blockchain>
 * Copyright 2016-2017 XMRig       <admin@imonero.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __API_H__
#define __API_H__


#include <uv.h>


class ApiRouter;
class Hashrate;
class NetworkState;


namespace xmrig {
    class Controller;
    class HttpReply;
    class HttpRequest;
}


class Api
{
public:
    static bool start(xmrig::Controller *controller);
    static void release();

    static void exec(const xmrig::HttpRequest &req, xmrig::HttpReply &reply);
    static void tick(const NetworkState &results);

private:
    static ApiRouter *m_router;
};

#endif /* __API_H__ */
