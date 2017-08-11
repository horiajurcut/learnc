cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)

project(learnc)

link_directories( ${CMAKE_CURRENT_LIST_DIR}/chapters )
include_directories( chapters )

# Basic test app
set( APP_SRC main.c )
set( APP_SRC ${APP_SRC} chapters/one.c chapters/utils.c chapters/scope.c)

add_executable( app ${APP_SRC} )
