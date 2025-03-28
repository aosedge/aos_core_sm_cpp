#
# Copyright (C) 2024 EPAM Systems, Inc.
#
# SPDX-License-Identifier: Apache-2.0
#

set(TARGET app)

# ######################################################################################################################
# Sources
# ######################################################################################################################

set(SOURCES app.cpp aoscore.cpp)

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

add_definitions(-DLOG_MODULE="app")
target_compile_options(${TARGET} PRIVATE -Wstack-usage=${AOS_STACK_USAGE})

# ######################################################################################################################
# Libraries
# ######################################################################################################################

target_link_libraries(
    ${TARGET}
    PUBLIC config
           database
           image
           launcher
           monitoring
           resourcemanager
           runner
           smclient
           networkmanager
           alerts
           aoscommon
           aosdownloader
           aosocispec
           aossm
           aosiamclient
           aosjsonprovider
           aoslogger
           logprovider
           Poco::Util
)
