/*
 * Copyright (C) 2024 EPAM Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <string>
#include <vector>

#include <Poco/Dynamic/Var.h>

#include <aos/common/monitoring/resourcemonitor.hpp>
#include <aos/common/tools/error.hpp>
#include <aos/sm/launcher/config.hpp>
#include <aos/sm/layermanager.hpp>
#include <aos/sm/servicemanager.hpp>
#include <iamclient/publicservicehandler.hpp>
#include <utils/time.hpp>

#include "smclient/config.hpp"

namespace aos::sm::config {

/***********************************************************************************************************************
 * Types
 **********************************************************************************************************************/

/*
 * Logging configuration.
 */
struct LoggingConfig {
    uint64_t mMaxPartSize;
    uint64_t mMaxPartCount;
};

/*
 * Journal alerts configuration.
 */
struct JournalAlertsConfig {
    std::vector<std::string> mFilter;
    int                      mServiceAlertPriority;
    int                      mSystemAlertPriority;
};

/*
 * Migration configuration.
 */
struct MigrationConfig {
    std::string mMigrationPath;
    std::string mMergedMigrationPath;
};

/*
 * Config instance.
 */
struct Config {
    common::iamclient::Config  mIAMClientConfig;
    sm::layermanager::Config   mLayerManagerConfig;
    sm::servicemanager::Config mServiceManagerConfig;
    sm::launcher::Config       mLauncherConfig;
    smclient::Config           mSMClientConfig;
    std::string                mCertStorage;
    std::string                mIAMProtectedServerURL;
    std::string                mWorkingDir;
    uint32_t                   mServicesPartLimit;
    uint32_t                   mLayersPartLimit;
    std::string                mNodeConfigFile;
    monitoring::Config         mMonitoring;
    LoggingConfig              mLogging;
    JournalAlertsConfig        mJournalAlerts;
    MigrationConfig            mMigration;
};

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*
 * Parses config from file.
 *
 * @param filename config file name.
 * @param[out] config config instance.
 * @return Error.
 */
Error ParseConfig(const std::string& filename, Config& config);

} // namespace aos::sm::config

#endif
