cmake_minimum_required(VERSION 3.14)
project(Portfolio)

set(CMAKE_CXX_FLAGS " -std=c++11")

# Find's all the source files within a project and groups them within the (PROJECTNAME)_SRC file.
file(GLOB Portfolio_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

set(SOURCE_FILES main.cpp)

# Add's all the found source files within the executable
add_executable(Portfolio ${Portfolio_SRC} SFMLTools/Component.cpp SFMLTools/Component.h SFMLTools/Application.cpp SFMLTools/Application.h SFMLTools/EventHandleable.cpp SFMLTools/EventHandleable.h Games.cpp Games.h
        Projects/BouncingBall/BouncingBall.cpp Projects/BouncingBall/BouncingBall.h Projects/Ball/Ball.cpp Projects/Ball/Ball.h Projects/TopHatGuy/TopHatGuy.cpp Projects/TopHatGuy/TopHatGuy.h Projects/PingPong/Pong.cpp
        Projects/PingPong/Pong.h Projects/PingPong/PongBall.cpp Projects/PingPong/PongBall.h Projects/PingPong/Paddle.cpp Projects/PingPong/Paddle.h Projects/Applications/Screens.cpp Projects/Applications/Screens.h SFMLTools/MouseEvent.cpp SFMLTools/MouseEvent.h
        Projects/Applications/States.cpp Projects/Applications/States.h Projects/Applications/states_enum.h Projects/Applications/fonts_enum.h Projects/Applications/Fonts.cpp Projects/Applications/Fonts.h
        Projects/Applications/Position.cpp Projects/Applications/Position.h Projects/Applications/ListItem.cpp Projects/Applications/ListItem.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories()
target_link_libraries(Portfolio sfml-system sfml-window sfml-graphics sfml-audio sfml-network)