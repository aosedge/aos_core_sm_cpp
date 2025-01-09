/*
 * Copyright (C) 2025 EPAM Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef SMCLIENT_CONFIG_HPP_
#define SMCLIENT_CONFIG_HPP_

#include <string>

#include <utils/time.hpp>

namespace aos::sm::smclient {

/***
 * Service manager client configuration.
 */
struct Config {
    std::string             mCertStorage;
    std::string             mCMServerURL;
    common::utils::Duration mCMReconnectTimeout;
};

} // namespace aos::sm::smclient

#endif
