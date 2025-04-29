# WEBSOCKET
add_executable(WebSocketClient main.cpp)
target_link_libraries(WebSocketClient PRIVATE ixwebsocket)
target_include_directories(WebSocketClient PRIVATE
        ${PROJECT_SOURCE_DIR}/externals/nlohmann
)
set_property(TARGET WebSocketClient PROPERTY CXX_STANDARD 20)
