# XMRig

:warning: **If you mine Monero, Aeon, Sumokoin, Turtlecoin, Stellite, GRAFT, Haven Protocol, IPBC, 


XMRig is a high performance Monero (XMR) CPU miner, with official support for Windows.
XMRig 是一款高性能的CPU门罗币挖矿软件，支持windows操作系统  在算法和程序调度上做了大量的优化工作



#### Table of contents
* [Features](#features)
* [Download](#download)
* [Usage](#usage)
* [Algorithm variations](#algorithm-variations)
* [Build](https://github.com/xmrig/xmrig/wiki/Build)
* [Common Issues](#common-issues)
* [Other information](#other-information)
* [Donations](#donations)
* [Release checksums](#release-checksums)
* [Contacts](#contacts)

#### 目录
* [特色](#features)
* [下载](#download)
* [用法](#usage)
* [Algorithm variations](#algorithm-variations)
* [Build](https://github.com/xmrig/xmrig/wiki/Build)
* [Common Issues](#common-issues)
* [Other information](#other-information)
* [Donations](#donations)
* [Release checksums](#release-checksums)
* [Contacts](#contacts)

## Features
* High performance.
* Official Windows support.
* Small Windows executable, without dependencies.
* x86/x64 support.
* Support for backup (failover) mining server.
* keepalived support.
* Command line options compatible with cpuminer.
* CryptoNight-Lite support for AEON.
* Smart automatic 
* Nicehash support
* It's open source software.
## 特色
* 高性能门罗挖矿软件，对挖矿算法做了极致优化
* 支持windows系统
* 不需要安装依赖，可执行文件占用很少的磁盘空间
* 支持 x86/x64 系统.
* 支持失效备源服务器，一台服务器失效，自动切换到另一台服务器
* 不会掉线，断线自动重连.
* 支持命令行选项.
* 支持 AEON CryptoNight-Lite算法.
* 只能调节线程数量.
* 支持Nicehash
* 完全开源.
## Download
* Binary releases: https://github.com/global-blockchain/xmrig
* Git tree: https://github.com/global-blockchain/xmrig.git
  * Clone with `git clone https://github.com/global-blockchain/xmrig.git` :hammer: [Build instructions](https://github.com/xmrig/xmrig/wiki/Build).

## 下载
* CPU挖矿软件下载: https://github.com/global-blockchain/xmrig
* git 地址: https://github.com/global-blockchain/xmrig.git
  * Clone with `git clone https://github.com/global-blockchain/xmrig.git` :hammer: [Build instructions](https://github.com/xmrig/xmrig/wiki/Build).

## Usage
Edit config.json.

### Options
```
  -a, --algo=ALGO          cryptonight (default) or cryptonight-lite
  -o, --url=URL            URL of mining server
  -O, --userpass=U:P       username:password pair for mining server
  -u, --user=USERNAME      username for mining server
  -p, --pass=PASSWORD      password for mining server
  -t, --threads=N          number of miner threads
  -v, --av=N               algorithm variation, 0 auto select
  -k, --keepalive          send keepalived for prevent timeout (need pool support)
  -r, --retries=N          number of times to retry before switch to backup server (default: 5)
  -R, --retry-pause=N      time to pause between retries (default: 5)
      --cpu-affinity       set process affinity to CPU core(s), mask 0x3 for cores 0 and 1
      --cpu-priority       set process priority (0 idle, 2 normal to 5 highest)
      --no-huge-pages      disable huge pages support
      --no-color           disable colored output
      --variant            algorithm PoW variant
      --donate-level=N     donate level, default 5% (5 minutes in 100 minutes)
      --user-agent         set custom user-agent string for pool
  -B, --background         run the miner in the background
  -c, --config=FILE        load a JSON-format configuration file
  -l, --log-file=FILE      log all output to a file
  -S, --syslog             use system log for output messages
      --max-cpu-usage=N    maximum CPU usage for automatic threads mode (default 75)
      --safe               safe adjust threads and av settings for current CPU
      --nicehash           enable nicehash/xmrig-proxy support
      --print-time=N       print hashrate report every N seconds
      --api-port=N         port for the miner API
      --api-access-token=T access token for API
      --api-worker-id=ID   custom worker-id for API
  -h, --help               display this help and exit
  -V, --version            output version information and exit
```

Also you can use configuration via config file, default **config.json**. You can load multiple config files and combine it with command line options.
可以通过配置文件来修改配置，默认的配置文件名是 **config.json**。你可以通过加载命令行加载多个配置文件。

## Algorithm variations
Since version 0.8.0.
* `--av=1` For CPUs with hardware AES.
* `--av=2` Lower power mode (double hash) of `1`.
* `--av=3` Software AES implementation.
* `--av=4` Lower power mode (double hash) of `3`.

## Common Issues
### HUGE PAGES unavailable
* Run XMRig as Administrator.
* Since version 0.8.0 XMRig automatically enables SeLockMemoryPrivilege for current user, but reboot or sign out still required. [Manual instruction](https://msdn.microsoft.com/en-gb/library/ms190730.aspx).

## Other information
* No HTTP support, only stratum protocol support.
* No TLS support.
* Default donation 5% (5 minutes in 100 minutes) can be reduced to 1% via command line option `--donate-level`.
## 其它信息
* 不支持 HTTP 协, 只支持 stratum 协议.
* 不支持TLS.
* 默认捐赠 donation 5% (100分钟捐出5分钟) 可以通过选项`--donate-level` 减少至1%

### CPU mining performance
* **Intel i7-7700** - 307 H/s (4 threads)
* **AMD Ryzen 7 1700X** - 560 H/s (8 threads)
### CPU挖矿性能
* **Intel i7-7700** - 307 H/s (4 threads)
* **AMD Ryzen 7 1700X** - 560 H/s (8 threads)

Please note performance is highly dependent on system load. The numbers above are obtained on an idle system. Tasks heavily using a processor cache, such as video playback, can greatly degrade hashrate. Optimal number of threads depends on the size of the L3 cache of a processor, 1 thread requires 2 MB of cache.
注意：性能和系统负载密切相关。以上性能数据是在空闲的系统上获得的。系统如果运行高度依赖cpu 缓存的任务，比如视频回放，会大大降低挖矿效率。最佳的挖矿线程数量根据cpu L3缓存而定。一个线程需要2MB的缓存

### Maximum performance checklist
* Idle operating system.
* Do not exceed optimal thread count.
* Use modern CPUs with AES-NI instruction set.
* Try setup optimal cpu affinity.
* Enable fast memory (Large/Huge pages).
### 最大性能调优准则
* 系统不要运行其它任务，
* 不要超出系统最佳线程数量
* Use modern CPUs with AES-NI instruction set.
* Try setup optimal cpu affinity.
* Enable fast memory (Large/Huge pages).
## Donations
* XMR: `48PbYAxS8rj6B3u94zZwfwPZ7Y777zztQHrDGSvDaheu4LG6Y1e5L7QbUt28z4ZGETi5bSLeUCerx4cEnyFSidSQ9o1mJDG`
* ETH: `0x749Eaf7029988a6060Fdb2B1741852A92a45F378`

## Release checksums
### SHA-256
```
```

## Contacts
* admin@imonero.org
