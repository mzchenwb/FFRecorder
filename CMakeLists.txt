cmake_minimum_required(VERSION 3.6)
project(FFRecorder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        ErrorCheck.h
        FFAudioBufferEncoder.cpp
        FFAudioBufferEncoder.hpp
        FFAudioHelper.cpp
        FFAudioHelper.hpp
        FFAudioMixing.cpp
        FFAudioMixing.hpp
        FFAutoReleasePool.cpp
        FFAutoReleasePool.hpp
        transcode_aac.c)

add_executable(FFRecorder ${SOURCE_FILES})

include_directories(
        /Users/chenweibin/Documents/ffmpeg_build/include
)
link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)
target_link_libraries(
        FFRecorder
        /Users/chenweibin/Documents/ffmpeg_build/lib/libavcodec.dylib
        /Users/chenweibin/Documents/ffmpeg_build/lib/libavfilter.dylib
        /Users/chenweibin/Documents/ffmpeg_build/lib/libavformat.dylib
        /Users/chenweibin/Documents/ffmpeg_build/lib/libavutil.dylib
        /Users/chenweibin/Documents/ffmpeg_build/lib/libswresample.dylib
)