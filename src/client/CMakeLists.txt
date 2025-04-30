# CLIENT APP
add_executable(ClientApp
        main.cpp
        ${PROJECT_SOURCE_DIR}/src/client/OnlineClient.cpp
        ${PROJECT_SOURCE_DIR}/src/client/OnlineClient.h
)

target_include_directories(ClientApp PRIVATE
        ${PROJECT_SOURCE_DIR}/externals/cpp-httplib
        ${PROJECT_SOURCE_DIR}/externals/nlohmann
)

if (WIN32)
  target_link_libraries(ClientApp PRIVATE ws2_32)
endif()
set_property(TARGET ClientApp PROPERTY CXX_STANDARD 20)
