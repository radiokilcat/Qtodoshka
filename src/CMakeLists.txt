find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(TimeTrack
  main.cpp
  qml.qrc
  session.cpp
  taskmodel.cpp
)

target_compile_definitions(TimeTrack
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(TimeTrack
  PRIVATE Qt5::Core Qt5::Quick ${CONAN_LIBS})
