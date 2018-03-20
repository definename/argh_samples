cmake_minimum_required(VERSION 3.10.0)

project(argh_samples)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

option(BUILD_WITH_BOOST "Build project with boost libraries" ON)

include(PCHSupport)
include(CRTLinkage)

###########################################################
# Version #################################################

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_BUILD "0")
set(REVISION_COUNT "0")

find_package(Git)
if(GIT_FOUND)
	execute_process(
		COMMAND ${GIT_EXECUTABLE} rev-list HEAD --count
		OUTPUT_VARIABLE DESCRIBE_BUILD
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		OUTPUT_STRIP_TRAILING_WHITESPACE)
		string(REGEX MATCH "[0-9]+" REVISION_COUNT ${DESCRIBE_BUILD})
endif()

set(VERSION_REVISION "${REVISION_COUNT}")
set(VERSION_FILE_REVISION "${REVISION_COUNT}")
set(VERSION_COMPANY_NAME "Carrot Farm")
set(VERSION_COPYRIGHT "Copyright (C) 2018 ${VERSION_COMPANY_NAME}")

# Where to put all the ARCHIVE targets when built.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Where to put all the RUNTIME target files when built.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Use folder in project
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# External directory path.
set(EXTERNAL_DIRECTORY "${CMAKE_SOURCE_DIR}/external")

###########################################################
# argh ##################################################

set(ARGH_INCLUDE_DIRS
	${EXTERNAL_DIRECTORY}/argh/include)

add_subdirectory(modules/argh-test)