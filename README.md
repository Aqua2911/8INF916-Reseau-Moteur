# Magnum Bootstrap

A self-contained bootstrap for Magnum GLFW with Bullet that compile on Windows, Linux and MacOS

Integration done by Valere at https://github.com/VALERE91/MagnumBootstrap.


# Running the project

## Windows

Start the API
```bash
cd GameApi/bin/Release/net9.0/win-x64/publish/
```
```bash
./GameApi.exe
```

In a new terminal, run the server
```bash
cd cmake-build-release/Release/bin/
```
```bash
./MagnumServer.exe
```

In another terminal, run the client
```bash
cd cmake-build-release/Release/bin/
```
```bash
./LauncherApp.exe
```

## Linux

Start the API
```bash
cd GameApi/bin/Release/net9.0/linux-x64/publish/
```
```bash
./GameApi
```

In a new terminal, run the server
```bash
cd cmake-build-release/Release/bin/
```
```bash
./MagnumServer
```

In another terminal, run the client
```bash
cd cmake-build-release/Release/bin/
```
```bash
./LauncherApp
```