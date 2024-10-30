以下是`gbr_daemon`项目的模块文档，介绍了各个模块的功能和作用。

---

# gbr_daemon 项目模块文档

## 项目概述
`gbr_daemon` 是一个基于C++的路由协议守护进程项目，旨在实现一种名为“Gravity Backpressure Routing”（GBR）的路由算法。项目模块化设计，包含多个子模块，以便支持未来的扩展、灵活的路由算法、缓存和优先级管理。每个模块通过Docker和CMake工具链进行构建和部署，方便测试和使用。

---

## 模块概览

1. **GBR Daemon（GBRDaemon）**
   - **描述**：该模块是整个守护进程的主控制器，负责启动守护进程，管理配置文件，初始化各模块，并保持守护进程的运行。
   - **主要文件**：
     - `GBRDaemon.cpp`：守护进程的主程序实现。
     - `GBRDaemon.h`：守护进程主程序的头文件。

2. **路由模块（router）**
   - **描述**：管理路由算法的执行和路由表的维护。支持扩展不同的路由算法。
   - **主要文件**：
     - `GBRRouter.cpp / GBRRouter.h`：路由器主类，负责处理数据包和维护邻居关系。
     - `RoutingAlgorithm.h`：路由算法的抽象基类。
     - `GravityRouting.cpp / GravityRouting.h`：GBR路由算法实现。
     - `BackpressureRouting.cpp / BackpressureRouting.h`：回压路由算法实现。

3. **邻居管理模块（neighbor）**
   - **描述**：负责管理和维护邻居关系。包括发现、状态更新以及邻居信息的持久化。
   - **主要文件**：
     - `GBRNeighbor.cpp / GBRNeighbor.h`：邻居管理类，用于处理邻居状态和更新邻居信息。

4. **数据包模块（packet）**
   - **描述**：管理不同类型的数据包的解析与封装，支持 OSPF 类协议的基本数据包类型。
   - **主要文件**：
     - `GBRPacket.cpp / GBRPacket.h`：通用数据包处理类。
     - `HelloPacket.cpp / HelloPacket.h`：Hello数据包类型，处理邻居发现。
     - `DbDescriptionPacket.cpp / DbDescriptionPacket.h`：Database Description数据包，用于数据库同步。
     - `LsaPacket.cpp / LsaPacket.h`：LSA数据包类型，管理链路状态信息的传播。

5. **链路状态公告模块（LSA）（lsa）**
   - **描述**：负责管理链路状态公告（LSA）数据结构，记录各节点的链路状态信息。
   - **主要文件**：
     - `LSA.cpp / LSA.h`：LSA类，封装网络中每个节点的状态信息。

6. **链路状态数据库模块（LSDB）（lsdb）**
   - **描述**：链路状态数据库（LSDB）用于存储所有LSA，支持路由器访问并利用这些信息计算最优路径。
   - **主要文件**：
     - `LSDB.cpp / LSDB.h`：LSDB类，提供LSA数据存储和查找接口。

7. **路由表模块（table）**
   - **描述**：管理实际的路由表信息，包括插入、更新和删除路由表项。
   - **主要文件**：
     - `RoutingTable.cpp / RoutingTable.h`：路由表管理类，处理路由表的维护和更新。

8. **工具模块（utils）**
   - **描述**：提供一些常用的工具类和函数，包含日志管理、配置解析和网络工具。
   - **主要文件**：
     - `ConfigParser.cpp / ConfigParser.h`：配置文件解析器，读取并存储配置参数。
     - `Logger.cpp / Logger.h`：日志管理类，用于记录运行时的事件和错误信息。
     - `NetworkUtils.cpp / NetworkUtils.h`：网络相关的工具函数。

9. **缓存管理模块（buffer）**
   - **描述**：缓存管理模块，用于存储和管理临时数据，优化网络传输的效率。
   - **主要文件**：
     - `BufferManager.cpp / BufferManager.h`：缓存管理类，实现缓存的增删查操作和容量管理。

10. **优先级管理模块（priority）**
    - **描述**：管理数据包或邻居的优先级，用于控制数据传输的优先级调度。
    - **主要文件**：
      - `PriorityManager.cpp / PriorityManager.h`：优先级管理类，用于为邻居或数据包分配优先级。

11. **路径选择策略模块（path_selection）**
    - **描述**：用于定义路径选择的策略，支持多种路径选择算法（如最短路径、多路径选择）。
    - **主要文件**：
      - `PathSelectionStrategy.h`：路径选择的抽象基类。
      - `ShortestPathSelection.cpp / ShortestPathSelection.h`：最短路径选择策略。
      - `MultiPathSelection.cpp / MultiPathSelection.h`：多路径选择策略。

---

## 依赖项

- **C++17**：项目代码使用C++17标准。
- **Docker**：用于容器化部署。
- **CMake**：构建管理工具，配置并构建项目及其子模块。
- **libcap-dev**：处理网络权限的库。
- **libpcap-dev**：用于数据包捕获的库，支持处理数据包级别操作。

---

## 构建和运行

### 使用CMake构建

1. 从项目根目录运行以下命令来生成构建文件：
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

2. 成功构建后，主可执行文件`gbr_daemon`将生成在`build`目录中。

### 使用Docker构建和运行

1. 在项目根目录下构建Docker镜像：
   ```bash
   docker build -t gbr_d .
   ```

2. 启动Docker容器并运行守护进程：
   ```bash
   docker run -it --rm gbr_d
   ```

---

## 模块间交互

- **GBRDaemon**模块调用**router**模块，并通过**neighbor**模块管理邻居状态。
- **router**模块通过**packet**模块发送和接收网络数据包，访问**LSDB**模块存储的LSA信息，结合**RoutingTable**计算路由路径。
- **utils**模块中的日志功能贯穿整个项目，为各模块提供日志记录能力。
- **buffer**模块为路由操作提供缓存支持，**priority**模块管理数据传输优先级。
- **path_selection**模块实现路径选择算法，为路由决策提供策略。

---

通过这些模块的合理分工和组合，`gbr_daemon`可以实现灵活的路由协议和高效的数据包管理，满足不同网络环境的需求。