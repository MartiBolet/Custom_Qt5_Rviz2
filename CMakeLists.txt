##############################################################################
# PROJECT
##############################################################################

cmake_minimum_required(VERSION 3.5)
project(myviz)

##############################################################################
# CMAKE | As found in ROS2 eloquent distribution
##############################################################################

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

##############################################################################
# DEPENDENCIES | Add package dependencies here
##############################################################################

# Find QT dependencies
find_package(Qt5 COMPONENTS Core Gui Widgets UiTools REQUIRED) #Ejemplo para QWidget

# Find ROS2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rviz_common REQUIRED)
find_package(rviz_default_plugins REQUIRED)
find_package(rviz_ogre_vendor REQUIRED)
find_package(rviz_rendering REQUIRED)

find_package(Qt5Core REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5UiTools REQUIRED)

##############################################################################
# QT5 - FILES PATH | AUTO SET  
##############################################################################

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
  include
)

file(GLOB_RECURSE MOC_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS
  include/${PROJECT_NAME}/*.h *.hpp
)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS
  src/*.cpp
)

QT5_WRAP_CPP(QT_HEADERS ${MOC_HEADERS})


##############################################################################
# COMPILE | Add ament_target dependencies here | Add target link ligraries
##############################################################################

## Add executable
add_executable(${PROJECT_NAME}
  src/main.cpp
  ${SOURCES} 
  ${QT_RESOURCES}
  ${QT_HEADERS} 
)


ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  rclcpp_components
  rviz_common
  rviz_default_plugins
  rviz_ogre_vendor
  rviz_rendering
)

target_link_libraries(${PROJECT_NAME}
  Qt5::Widgets
  Qt5::Core
  Qt5::Gui
  Qt5::UiTools
)

## Install executable
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

ament_package()
