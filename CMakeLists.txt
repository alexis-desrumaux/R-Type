cmake_minimum_required(VERSION 3.5)

project(r-type_client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(r-type_client
  Client/src/Core.cpp
  Client/src/main.cpp
  Client/src/GameState/Menu/Menu.cpp
  Client/include/Core/Core.hpp
  Client/include/Core/GameState/Menu/Menu.hpp
  Client/lib/GameCore/src/Behavior/Behavior.cpp
  Client/lib/GameCore/src/Object/Object.cpp
  Client/lib/GameCore/src/Objects/Objects.cpp
  Client/lib/GameCore/src/Tools/tools.cpp
  Client/lib/GameCore/include/Behavior/Behavior.hpp
  Client/lib/GameCore/include/Object/Object.hpp
  Client/lib/GameCore/include/Objects/Objects.hpp
  Client/lib/GameCore/include/Tools/Tools.hpp
  Client/lib/graphical/sfml/src/Components.cpp
  Client/lib/graphical/sfml/src/Sfml_c.cpp
  Client/lib/graphical/sfml/src/Sfml.cpp
  Client/lib/graphical/sfml/include/Components.hpp
  Client/lib/graphical/sfml/include/Event.hpp
  Client/lib/graphical/sfml/include/IGLib.hpp
  Client/lib/graphical/sfml/include/SFML.hpp
  Client/lib/graphical/sfml/include/SFMLTools.hpp
  Client/lib/Parser/src/Parser.cpp
  Client/lib/Parser/include/Parser.hpp
)

target_link_libraries(r-type_client -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system -logg -ldl)
