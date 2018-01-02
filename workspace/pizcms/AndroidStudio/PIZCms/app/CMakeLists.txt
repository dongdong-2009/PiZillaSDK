# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Specifies a path to native header files.
include_directories(src/main/cpp/include/)
include_directories(../../../../include/)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_definitions("-DUSE_PIZIOT_CORE_CMS")

add_library( # Sets the name of the library.
    piziot_core_app

    # Sets the library as a shared library.
    SHARED

    # Provides a relative path to your source file(s).
    src/main/cpp/app/piziot_core_app.cpp
    src/main/cpp/libpiziot/piziot_os.cpp
    src/main/cpp/libpiziot/piziot_file_avi.cpp
    src/main/cpp/libpiziot/piziot_p2p_common.cpp
    src/main/cpp/libpiziot/piziot_p2p_client.cpp
    src/main/cpp/libpiziot/piziot_core_cms.cpp
)

# Sets distribution_DIR to the path of the desired output directory.
    #set(source_so_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/intermediates/cmake/${CMAKE_BUILD_TYPE}/obj/${ANDROID_ABI})
    set(source_so_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../Android.outputs/PIZCms/app/build/intermediates/cmake/${CMAKE_BUILD_TYPE}/obj/${ANDROID_ABI})
    set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../lib/AndroidStudio/${CMAKE_BUILD_TYPE}/${ANDROID_ABI})
    file(MAKE_DIRECTORY ${distribution_DIR})
    #file(REMOVE ${source_so_DIR}/libpiziot_core_app.so)
    #file(REMOVE ${distribution_DIR}/libpiziot_core_app.so)
    #add_custom_command(TARGET piziot_core_app POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${source_so_DIR}/libpiziot_core_app.so ${distribution_DIR}/libpiziot_core_app.so)

    add_custom_command(TARGET piziot_core_app POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${distribution_DIR}/libpiziot_os.so ${source_so_DIR}/libpiziot_os.so)
    add_custom_command(TARGET piziot_core_app POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${distribution_DIR}/libpiziot_p2p_common.so ${source_so_DIR}/libpiziot_p2p_common.so)
    add_custom_command(TARGET piziot_core_app POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${distribution_DIR}/libpiziot_p2p_client.so ${source_so_DIR}/libpiziot_p2p_client.so)
    add_custom_command(TARGET piziot_core_app POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${distribution_DIR}/libpiziot_core_cms.so ${source_so_DIR}/libpiziot_core_cms.so)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
    log-lib

    # Specifies the name of the NDK library that
    # you want CMake to locate.
    log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

add_library(piziot_os SHARED IMPORTED)
set_target_properties(piziot_os PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/libpiziot_os.so)
add_library(piziot_p2p_common SHARED IMPORTED)
set_target_properties(piziot_p2p_common PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/libpiziot_p2p_common.so)
add_library(piziot_p2p_client SHARED IMPORTED)
set_target_properties(piziot_p2p_client PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/libpiziot_p2p_client.so)
add_library(piziot_core_cms SHARED IMPORTED)
set_target_properties(piziot_core_cms PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/libpiziot_core_cms.so)

target_link_libraries( # Specifies the target library.
    piziot_core_app

    # link so
    piziot_os
    piziot_p2p_common
    piziot_p2p_client
    piziot_core_cms

    # Links the target library to the log library
    # included in the NDK.
    ${log-lib} )