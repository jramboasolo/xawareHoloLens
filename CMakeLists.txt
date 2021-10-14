cmake_minimum_required(VERSION 3.5)

if(WIN32)
    project(xawareHoloLens VERSION 0.1 LANGUAGES CXX)
elseif(UNIX)
    project(xawareHoloLens)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_SOURCE_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
message("OPENMP FOUND")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()


FIND_PACKAGE(OpenGL REQUIRED)


#find_package(QT NAMES Qt4 COMPONENTS Widgets REQUIRED)
#find_package(Qt4 COMPONENTS Widgets Core Network GUI REQUIRED)
FIND_PACKAGE(Qt4 COMPONENTS QtCore QtNetwork QTGUI REQUIRED)
SET(QT_USE_QTOPENGL TRUE)
SET(QT_USE_QTDESIGNER TRUE)
SET(QT_USE_QTGUI TRUE)
INCLUDE(${QT_USE_FILE})

#For Zeego Comm
SET( RABBITMQ_DIR "/camma/libs/rabbitmq-c-master/" CACHE FILEPATH "Path to rabbitmq-c library" )
SET( SIMPLEAMQPCLIENT_DIR "/camma/libs/SimpleAmqpClient-master/" CACHE FILEPATH "Path to SimpleAMQPClient library" )
SET( JSONCPP_DIR "/camma/libs/jsoncpp-master/" CACHE FILEPATH "Path to jsoncpp library" )


INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/include
        include/
        ${CMAKE_CURRENT_BINARY_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        ${EXTERNAL_INCLUDE_DIR}

        ${RABBITMQ_DIR}/install/include/
        ${SIMPLEAMQPCLIENT_DIR}/install/include/
        ${JSONCPP_DIR}/install/include/
)

LINK_DIRECTORIES(
        ${RABBITMQ_DIR}/install/lib/x86_64-linux-gnu/
        ${SIMPLEAMQPCLIENT_DIR}/install/lib/
        ${JSONCPP_DIR}/install/lib/
)

SET(HEADER_FILES
    include/amqpconnection.h
    include/mainwindow.h
    include/servertcp.h
)

SET(HEADER_FILES_MOC
    include/mainwindow.h
)

SET(SOURCE_FILES
    src/main.cpp
    src/amqpconnection.cpp
    src/mainwindow.cpp
    src/servertcp.cpp
)

SET(FORMS
    src/mainwindow.ui
)

SET(NEEDED_LIBS
        ${Boost_LIBRARIES}
        ${PROTOBUF_LIBRARY}
        ${OpenCV_LIBS}
        ${OPENGL_LIBRARIES}
        ${QT_LIBRARIES}
        ${PCL_LIBRARIES}
        rabbitmq
        SimpleAmqpClient
        jsoncpp
        Qt4::QtCore
        Qt4::QtNetwork
)

INCLUDE_DIRECTORIES(${INCLUDE_DIRS})
QT4_WRAP_UI(FORMS_HEADERS ${FORMS})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${HEADER_FILES} ${SOURCE_FILES}
                    ${FORMS_HEADERS} ${MOC_FILES}
    )
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${HEADER_FILES} ${SOURCE_FILES}
                        ${FORMS_HEADERS} ${MOC_FILES}
        )
    else()
        add_executable(${PROJECT_NAME}
            ${HEADER_FILES} ${SOURCE_FILES}
                        ${FORMS_HEADERS} ${MOC_FILES}
        )
    endif()
endif()

#target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
#target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Network)

#set_target_properties(${PROJECT_NAME} PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()

SET_SOURCE_FILES_PROPERTIES(
  PROPERTIES
  EXTERNAL_OBJECT true
  GENERATED true
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${NEEDED_LIBS})
