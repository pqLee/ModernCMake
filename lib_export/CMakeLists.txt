cmake_minimum_required ( VERSION 3.15 )

project ( FooLibTest )

set ( PackageName "Foo" )
set ( INCLUDE_INSTALL_DIR include )
set ( LIB_INSTALL_DIR lib  )
set ( DEP_LIB_NAME "dep" )
set ( FOO_LIB_NAME "foo" )
set ( BAR_LIB_NAME "bar" )

### dep lib
add_library ( ${DEP_LIB_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/dep.cpp )
target_include_directories ( ${DEP_LIB_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties ( ${DEP_LIB_NAME} PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/dep.h )

### foo lib
add_library ( ${FOO_LIB_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/foo.cpp )
target_include_directories ( ${FOO_LIB_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties ( ${FOO_LIB_NAME} PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/foo.h )

### bar lib
add_library ( ${BAR_LIB_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/bar.cpp )
target_include_directories ( ${BAR_LIB_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties ( ${BAR_LIB_NAME} PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/bar.h )


add_executable ( app ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp )
target_link_libraries ( app ${DEP_LIB_NAME} ${} ${FOO_LIB_NAME} ${BAR_LIB_NAME})
target_include_directories( app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include )

set ( dest ${LIB_INSTALL_DIR}/cmake/${PackageName} )

include ( CMakePackageConfigHelpers )
configure_package_config_file ( ${PackageName}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}Config.cmake
  INSTALL_DESTINATION ${dest}
  PATH_VARS INCLUDE_INSTALL_DIR
)
  
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}ConfigVersion.cmake
  VERSION 1.2.3
  COMPATIBILITY AnyNewerVersion
)

install ( 
	TARGETS ${DEP_LIB_NAME} ${FOO_LIB_NAME} ${BAR_LIB_NAME} app
    EXPORT ${PackageName}Targets
    RUNTIME DESTINATION bin 
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
 
install ( 
    EXPORT ${PackageName}Targets
    NAMESPACE FooSpace::
    DESTINATION ${dest}
)
        
install (
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}ConfigVersion.cmake
    DESTINATION ${dest}
)
