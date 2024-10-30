# 设置子模块的目录
# add_subdirectory(router)
# add_subdirectory(neighbor)
# add_subdirectory(packet)
# add_subdirectory(lsa)
# add_subdirectory(lsdb)
# add_subdirectory(table)
add_subdirectory(utils)
# add_subdirectory(buffer)
# add_subdirectory(priority)
# add_subdirectory(path_selection)

# 将所有模块链接到主可执行文件
add_library(core
    gbr_daemon.cpp
    gbr_daemon.h
)

# 链接核心库文件
target_link_libraries(core PRIVATE router neighbor packet lsa lsdb table utils buffer priority path_selection)
