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

#ifndef __APIROUTER_H__
#define __APIROUTER_H__


#include "api/NetworkState.h"
#include "common/interfaces/IControllerListener.h"
#include "rapidjson/fwd.h"


class Hashrate;


namespace xmrig {
    class Controller;
    class HttpReply;
    class HttpRequest;
}


class ApiRouter : public xmrig::IControllerListener
{
public:
    ApiRouter(xmrig::Controller *controller);
    ~ApiRouter();

    void get(const xmrig::HttpRequest &req, xmrig::HttpReply &reply) const;
    void exec(const xmrig::HttpRequest &req, xmrig::HttpReply &reply);

    void tick(const NetworkState &results);

protected:
    void onConfigChanged(xmrig::Config *config, xmrig::Config *previousConfig) override;

private:
    void finalize(xmrig::HttpReply &reply, rapidjson::Document &doc) const;
    void genId();
    void getConnection(rapidjson::Document &doc) const;
    void getHashrate(rapidjson::Document &doc) const;
    void getIdentify(rapidjson::Document &doc) const;
    void getMiner(rapidjson::Document &doc) const;
    void getResults(rapidjson::Document &doc) const;
    void getThreads(rapidjson::Document &doc) const;
    void setWorkerId(const char *id);
    void updateWorkerId(const char *id, const char *previousId);

    char m_id[17];
    char m_workerId[128];
    NetworkState m_network;
    xmrig::Controller *m_controller;
};

#endif /* __APIROUTER_H__ */
