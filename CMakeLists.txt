cmake_minimum_required(VERSION 3.26.3 FATAL_ERROR)

project(TranslitFiesNamesInDir)

add_executable(TranslitFiesNamesInDir files/main.cpp
files/Utf16ToUtf8_Class.cpp
files/Utf8ToUtf16_Class.cpp
files/TranslitClass.cpp
files/IfFileNameAlreadyExistsClass.cpp
files/GetDirectoryfFromPathClass.cpp
files/FileReplaceDialogClass.cpp
files/CopyFileClass.cpp
files/Utf16ToUtf8_Class.h
files/Utf8ToUtf16_Class.h
files/TranslitClass.h
files/IfFileNameAlreadyExistsClass.h
files/GetDirectoryfFromPathClass.h
files/FileReplaceDialogClass.h
files/CopyFileClass.h
files/resource.h 
)
