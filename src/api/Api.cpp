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

#include <string.h>


#include "api/Api.h"
#include "api/ApiRouter.h"
#include "common/api/HttpReply.h"
#include "common/api/HttpRequest.h"


ApiRouter *Api::m_router = nullptr;


bool Api::start(xmrig::Controller *controller)
{
    m_router = new ApiRouter(controller);

    return true;
}


void Api::release()
{
    delete m_router;
}


void Api::exec(const xmrig::HttpRequest &req, xmrig::HttpReply &reply)
{
    if (!m_router) {
        reply.status = 500;
        return;
    }

    if (req.method() == xmrig::HttpRequest::Get) {
        return m_router->get(req, reply);
    }

    m_router->exec(req, reply);
}


void Api::tick(const NetworkState &network)
{
    if (!m_router) {
        return;
    }

    m_router->tick(network);
}
