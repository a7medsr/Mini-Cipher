cmake_minimum_required(VERSION 3.28)
project(a7medsrMini_Cipher_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(a7medsrMini_Cipher_Project main.cpp
        PlayfairCipher.cpp
        PlayfairCipher.h
        RailFenceCipher.cpp
        RailFenceCipher.h
        CaesarCipher.cpp
        CaesarCipher.h
        VigenereCipher.cpp
        VigenereCipher.h)
