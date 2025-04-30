# Magnum Bootstrap

A self-contained bootstrap for Magnum GLFW with Bullet that compile on Windows, Linux and MacOS

Integration done by Valere at https://github.com/VALERE91/MagnumBootstrap.


Done by Clément Berlioz BERC13090100
and Nicolas Gravel GRAN01120007

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
cd cmake-build-linux/Release/bin/
```
```bash
./MagnumServer
```

In another terminal, run the client
```bash
cd cmake-build-linux/Release/bin/
```
```bash
./LauncherApp
```

# Workflow

1. Run the `GameApi`
2. Start the `MagnumServer`
3. Start one `LauncherApp` per client you wish to start
4. Log in as either one of the following registered usernames :
    * alice
    * bob
    * charlie
    * valere
5. Click on the `Login` button, logging in should request the api with infos about achievements and skins
6. Click on the `Find match` button
7. Once a match is found, click on the `Launch Game` button
8. game window appears, you can now play the game
