cmake_minimum_required(VERSION 3.15)
project(JNP1_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(JNP1_6 main.cpp lib_playlist.cc lib_playlist.h file.cc file.h playerException.cc playerException.h playable.h song.cc song.h movie.cc movie.h mode.cc mode.h SequenceMode.cc SequenceMode.h shuffleMode.cc shuffleMode.h oddEvenMode.cc oddEvenMode.h)
