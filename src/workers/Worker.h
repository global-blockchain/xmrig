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

#ifndef __WORKER_H__
#define __WORKER_H__


#include <atomic>
#include <stdint.h>


#include "interfaces/IWorker.h"
#include "Mem.h"


struct cryptonight_ctx;
class Handle;


namespace xmrig {
    class CpuThread;
}


class Worker : public IWorker
{
public:
    Worker(Handle *handle);

    inline const MemInfo &memory() const       { return m_memory; }
    inline size_t id() const override          { return m_id; }
    inline uint64_t hashCount() const override { return m_hashCount.load(std::memory_order_relaxed); }
    inline uint64_t timestamp() const override { return m_timestamp.load(std::memory_order_relaxed); }

protected:
    void storeStats();

    const size_t m_id;
    const size_t m_totalWays;
    const uint32_t m_offset;
    MemInfo m_memory;
    std::atomic<uint64_t> m_hashCount;
    std::atomic<uint64_t> m_timestamp;
    uint64_t m_count;
    uint64_t m_sequence;
    xmrig::CpuThread *m_thread;
};


#endif /* __WORKER_H__ */
