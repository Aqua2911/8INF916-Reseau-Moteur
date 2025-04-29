# SERVER APP
add_executable(ServerApp
        main.cpp
        ${PROJECT_SOURCE_DIR}/src/client/OnlineClient.cpp
        ${PROJECT_SOURCE_DIR}/src/client/OnlineClient.h
)

target_include_directories(ServerApp PRIVATE
        ${PROJECT_SOURCE_DIR}/externals/cpp-httplib
        ${PROJECT_SOURCE_DIR}/externals/nlohmann
)

target_link_libraries(ServerApp PRIVATE ws2_32)
set_property(TARGET ServerApp PROPERTY CXX_STANDARD 20)
