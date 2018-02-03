#############################################################
# Makefile for build the project for all environment
#############################################################

RM := rm -fr
GCC := g++ -Wall
EXEC_NAME := person
SRC_DIR := src
SRC_LIB := src/lib
TEST_DIR := test
TEST_LIB := test/lib
TEST_MAIN := main.cpp
LIBS :=
LIBS_DEBUG := -lgmock -lpthread -lgtest

all: Release

.PHONY: all clean

clean: clean_release clean_debug clean_coverage

# Debug
DEBUG_DIR := Debug

DEBUG_OPTION := -O0 -g3 -ggdb -fmessage-length=0

clean_debug:
	${RM} ${DEBUG_DIR}

Debug_DIR:
	[ -d ${DEBUG_DIR}/${SRC_LIB} ] || mkdir -p ${DEBUG_DIR}/${SRC_LIB}
	[ -d ${DEBUG_DIR}/${TEST_LIB} ] || mkdir -p ${DEBUG_DIR}/${TEST_LIB}


Debug_O: Debug_DIR
	${GCC} -fPIC ${DEBUG_OPTION} ${SRC_LIB}/* -shared -o ${DEBUG_DIR}/${SRC_LIB}/libPerson.so -MMD -MP -MT"${DEBUG_DIR}/${SRC_LIB}" 

Debug: Debug_O
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	${GCC} -o ${EXEC_NAME} ${TEST_LIB}/* ${TEST_DIR}/${TEST_MAIN} -I${SRC_LIB} -L${DEBUG_DIR}/${SRC_LIB}/ -lPerson  ${LIBS} ${LIBS_DEBUG} ${DEBUG_OPTION}

Launch-debug: Debug 

# Release
RELEASE_DIR := Release
RELEASE_OPTION := -ggdb 

clean_release:
	${RM} ${RELEASE_DIR}

Release:
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	[ -d ${RELEASE_DIR} ] || mkdir -p ${RELEASE_DIR}
	cd ${RELEASE_DIR}
	GCC  lib${EXEC_NAME}.so

Launch-release: Release

# coverage
COVERAGE_DIR := Coverage
COVERAGE_OPTION := -pg -ftest-coverage -fprofile-arcs

clean_coverage:
	${RM} ${COVERAGE_DIR}

Coverage:
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	[ -d ${COVERAGE_DIR} ] || mkdir -p ${COVERAGE_DIR}
	cd ${COVERAGE_DIR}
	${GCC} -o EXEC_NAME

Launch-coverage: Coverage
