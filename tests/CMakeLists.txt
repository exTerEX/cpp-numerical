# Find all files
file(
  GLOB_RECURSE SOURCES
  LIST_DIRECTORIES false
  RELATIVE ${CMAKE_CURRENT_LIST_DIR}
  *.cpp
)

foreach(FILE ${SOURCES})
  string(REGEX REPLACE "\\.cpp" "" FILE_WITHOUT_EXT ${FILE})

  add_executable(${FILE_WITHOUT_EXT} ${FILE})
  target_link_libraries(${FILE_WITHOUT_EXT} PRIVATE ${PROJECT_NAME})

  add_test(NAME ${FILE_WITHOUT_EXT} COMMAND $<TARGET_FILE:${FILE_WITHOUT_EXT}>)
endforeach()
