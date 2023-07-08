set_toolchains("clang")
set_languages("c++11")

target("database")
    set_kind("binary")
    add_files("src/*.cpp")
