include_directories(src)
include_directories(data)
include_directories(corner_data)

set(files_prefix "${CMAKE_CURRENT_SOURCE_DIR}/data")
file(GLOB_RECURSE CPPs "${files_prefix}/**.cpp")

string(REGEX REPLACE "/([a-zA-Z0-9:_-]*/)*" "" cata "${CMAKE_CURRENT_SOURCE_DIR}")

foreach (cpp_file ${CPPs})
    string(REGEX REPLACE "/[a-zA-Z]*\\.cpp" "" fpath ${cpp_file})
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/data/" "" testname "${fpath}")
    set(testname "${cata}-${testname}")
    add_executable(${testname} ${cpp_file})
    add_test(NAME ${testname}
            COMMAND bash -c "$<TARGET_FILE:${testname}> | diff ${fpath}/answer.txt -")
    #            COMMAND "$<TARGET_FILE:${testname}>")
    set_property(TEST ${testname} PROPERTY TIMEOUT 5)
endforeach ()

set(files_prefix "${CMAKE_CURRENT_SOURCE_DIR}/corner_data")
file(GLOB_RECURSE CPPs "${files_prefix}/**.cpp")

foreach (cpp_file ${CPPs})
    string(REPLACE ".cpp" "" nocpp ${cpp_file})
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/corner_data/" "" testnum "${nocpp}")
    set(testname "${cata}-corner-${testnum}")
    add_executable(${testname} ${cpp_file})
    string(REGEX REPLACE "/[0-9]\\.cpp" "" fpath ${cpp_file})
    add_test(NAME ${testname}
            COMMAND bash -c "$<TARGET_FILE:${testname}> | diff ${fpath}/${testnum}.ans -")
    #            COMMAND "$<TARGET_FILE:${testname}>")
    set_property(TEST ${testname} PROPERTY TIMEOUT 5)
endforeach ()
