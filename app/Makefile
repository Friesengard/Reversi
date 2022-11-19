ROOT_DIR=$(shell pwd)

APP_NAME=reversi
BUILD_DIR=build
OUTPUT_DIR=${BUILD_DIR}/output

all:
	@mkdir -p ${BUILD_DIR} && \
	cd ${BUILD_DIR} && \
	cmake ${ROOT_DIR} && \
	make && \
	echo "==================================== \n Build finished successfully \n===================================="

clean:
	make clean-build
	make clean-output

clean-build:
	rm -rf ${BUILD_DIR}/CMakeFiles
	rm -rf ${BUILD_DIR}/cmake_install.cmake
	rm -rf ${BUILD_DIR}/CMakeCache.txt
	rm -rf ${BUILD_DIR}/Makefile

clean-output:
	rm -rf ${OUTPUT_DIR}

run:
	cd ${OUTPUT_DIR} && \
	./${APP_NAME}
