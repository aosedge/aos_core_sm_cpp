#
# Copyright (C) 2024 EPAM Systems, Inc.
#
# SPDX-License-Identifier: Apache-2.0
#

set(TARGET monitoring)

# ######################################################################################################################
# Sources
# ######################################################################################################################

set(SOURCES resourceusageprovider.cpp)

# ######################################################################################################################
# Target
# ######################################################################################################################

add_library(${TARGET} STATIC ${SOURCES})

# ######################################################################################################################
# Includes
# ######################################################################################################################

# ######################################################################################################################
# Compiler flags
# ######################################################################################################################

add_definitions(-DLOG_MODULE="monitoring")
target_compile_options(${TARGET} PRIVATE -Wstack-usage=${AOS_STACK_USAGE})

# ######################################################################################################################
# Libraries
# ######################################################################################################################

target_link_libraries(${TARGET} PUBLIC aoscommon aossm aosutils Poco::Util)
