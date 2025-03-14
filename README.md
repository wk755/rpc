# mprpc - 分布式RPC通信框架

## 项目概述
mprpc是一个基于**muduo高性能网络库**和**Protobuf**开发的分布式网络通信框架。该项目旨在实现一个高效的RPC（远程过程调用）通信框架，支持分布式环境下的服务调用。通过结合muduo网络库的高并发处理能力和Protobuf的高效序列化，mprpc框架能够提供高性能的远程服务调用功能。

## 技术栈
- **集群与分布式**：理解集群和分布式系统的概念，掌握如何将模块拆分并部署到不同的服务器节点上。
- **RPC通信原理**：深入理解RPC的通信机制，包括请求的打包、传输、解包和响应的处理。
- **Protobuf**：使用Protobuf进行数据的序列化和反序列化，确保数据在传输过程中的高效性和兼容性。
- **ZooKeeper**：利用ZooKeeper作为分布式协调服务，实现服务的注册与发现。
- **muduo网络库**：基于muduo网络库实现高并发的网络通信。
- **CMake**：使用CMake构建项目，管理项目的编译和依赖。
- **异步日志**：实现异步日志系统，记录系统运行时的关键信息。

## 项目结构
- **bin**：存放可执行文件。
- **build**：存放项目编译生成的文件。
- **lib**：存放项目依赖的库文件。
- **src**：存放项目的源代码。
- **test**：存放测试代码。
- **example**：存放框架的使用示例。
- **CMakeLists.txt**：项目的顶层CMake配置文件。
- **README.md**：项目的自述文件。
- **autobuild.sh**：一键编译脚本，简化项目的编译过程。

## 核心功能
### RPC通信机制
- 通过Protobuf实现数据的序列化和反序列化，确保数据的高效传输。
- 使用muduo网络库处理网络通信，支持高并发的请求处理。
- 通过ZooKeeper实现服务的注册与发现，确保服务调用的高可用性。

### 网络I/O模型
- 支持多种网络I/O模型，包括单线程模型、多进程模型、多线程模型以及基于Reactor模式的高并发模型。
- 采用muduo的“one loop per thread”设计，确保每个连接的操作都在独立的线程中完成，充分利用CPU资源。

### ZooKeeper集成
- 使用ZooKeeper作为分布式协调服务，管理服务的注册与发现。
- 通过ZooKeeper的原生API实现节点的创建、删除、监听等操作，确保服务的动态管理。

### 异步日志系统
- 实现异步日志系统，确保系统运行时的关键信息能够被高效记录，避免日志记录对系统性能的影响。

## 项目亮点
- **高性能**：基于muduo网络库和Protobuf，mprpc框架能够处理高并发的RPC请求，确保系统的高性能。
- **分布式支持**：通过ZooKeeper实现服务的注册与发现，支持分布式环境下的服务调用。
- **易用性**：提供一键编译脚本和详细的示例代码，方便开发者快速上手和使用。

## 项目挑战
- **网络通信的高并发处理**：在高并发场景下，如何确保网络通信的稳定性和高效性是一个挑战。通过muduo的Reactor模式和多线程设计，项目成功解决了这一问题。
- **服务的动态管理**：在分布式环境下，服务的动态注册与发现是一个复杂的问题。通过ZooKeeper的集成，项目实现了服务的动态管理，确保系统的高可用性。

## 总结
mprpc项目是一个高性能的分布式网络通信框架，结合了muduo网络库、Protobuf和ZooKeeper等优秀的技术，实现了高效的RPC通信机制。通过该项目，不仅深入理解了分布式系统的设计和实现，还掌握了高并发网络编程、数据序列化、服务发现等关键技术。该框架可以广泛应用于分布式系统中，提供高效、稳定的远程服务调用功能。
