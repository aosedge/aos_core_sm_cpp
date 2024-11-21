/*
 * Copyright (C) 2024 EPAM Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CONVERT_HPP_
#define CONVERT_HPP_

#include <aos/common/cloudprotocol/alerts.hpp>
#include <aos/common/cloudprotocol/envvars.hpp>
#include <aos/common/cloudprotocol/log.hpp>
#include <aos/common/monitoring/monitoring.hpp>
#include <aos/common/types.hpp>
#include <aos/sm/networkmanager.hpp>

#include <servicemanager/v4/servicemanager.grpc.pb.h>

namespace aos::sm::utils {

/**
 * Converts aos error to protobuf error.
 *
 * @param error aos error.
 * @return iamanager::v5::ErrorInfo.
 */
::common::v1::ErrorInfo ConvertAosErrorToProto(const Error& error);

/**
 * Converts aos instance ident to protobuf.
 *
 * @param src instance ident to convert.
 * @param[out] dst protobuf instance ident.
 * @return void.
 */
void ConvertToProto(const InstanceIdent& src, ::common::v1::InstanceIdent& dst);

/**
 * Converts aos push log to protobuf.
 *
 * @param src push log to convert.
 * @param[out] dst protobuf log data.
 * @return void.
 */
void ConvertToProto(const cloudprotocol::PushLog& src, ::servicemanager::v4::LogData& dst);

/**
 * Converts aos monitoring data to protobuf.
 *
 * @param src monitoring data to convert.
 * @param timestamp monitoring data timestamp.
 * @param[out] dst protobuf monitoring data.
 * @return void.
 */
void ConvertToProto(
    const monitoring::MonitoringData& src, const Time& timestamp, ::servicemanager::v4::MonitoringData& dst);

/**
 * Converts aos node monitoring data to protobuf.
 *
 * @param src aos node monitoring.
 * @param dstMonitoringData[out] protobuf monitoring message.
 * @param dstInstanceMonitoring[out] protobuf instance monitoring message.
 * @return void.
 */
void ConvertToProto(const monitoring::NodeMonitoringData& src, ::servicemanager::v4::MonitoringData& dstMonitoringData,
    google::protobuf::RepeatedPtrField<::servicemanager::v4::InstanceMonitoring>& dstInstanceMonitoring);

/**
 * Converts aos instance status to protobuf.
 *
 * @param src instance status to convert.
 * @param[out] dst protobuf instance status.
 * @return void.
 */
void ConvertToProto(const InstanceStatus& src, ::servicemanager::v4::InstanceStatus& dst);

/**
 * Converts aos instance filter to protobuf.
 *
 * @param src aos instance filter.
 * @param dst[out] protobuf instance filter.
 * @return void.
 */
void ConvertToProto(const cloudprotocol::InstanceFilter& src, ::servicemanager::v4::InstanceFilter& dst);

/**
 * Converts aos env var status to protobuf.
 *
 * @param src aos env var status.
 * @param dst[out] protobuf env var status.
 * @return EnvVarInfo.
 */
void ConvertToProto(const cloudprotocol::EnvVarStatus& src, ::servicemanager::v4::EnvVarStatus& dst);

/**
 * Converts aos alerts to protobuf.
 *
 * @param src aos alert.
 * @param dst[out] protobuf alert.
 * @return void.
 */
void ConvertToProto(const cloudprotocol::AlertVariant& src, ::servicemanager::v4::Alert& dst);

/**
 * Converts protobuf instance ident to aos.
 *
 * @param val protobuf instance ident.
 * @return InstanceIdent.
 */
InstanceIdent ConvertToAos(const ::common::v1::InstanceIdent& val);

/**
 * Converts protobuf network parameters to aos.
 *
 * @param val protobuf network parameters.
 * @return NetworkParameters.
 */
NetworkParameters ConvertToAos(const ::servicemanager::v4::NetworkParameters& val);

/**
 * Converts protobuf instance info to aos.
 *
 * @param val protobuf instance info.
 * @return InstanceInfo.
 */
InstanceInfo ConvertToAos(const ::servicemanager::v4::InstanceInfo& val);

/**
 * Converts protobuf instance filter to aos.
 *
 * @param val protobuf instance filter.
 * @return InstanceFilter.
 */
cloudprotocol::InstanceFilter ConvertToAos(const ::servicemanager::v4::InstanceFilter& val);

/**
 * Converts protobuf env var info to aos.
 *
 * @param val protobuf env var info.
 * @return EnvVarInfo.
 */
cloudprotocol::EnvVarInfo ConvertToAos(const ::servicemanager::v4::EnvVarInfo& val);

/**
 * Converts protobuf env vars instance info to aos.
 *
 * @param src protobuf env vars instance info array.
 * @param dst[out] aos env vars instance info array.
 * @return Error.
 */
Error ConvertToAos(const ::servicemanager::v4::OverrideEnvVars& src, cloudprotocol::EnvVarsInstanceInfoArray& dst);

/**
 * Converts protobuf timestamp to aos.
 *
 * @param val protobuf timestamp.
 * @return Optional<Time>.
 */
Optional<Time> ConvertToAos(const google::protobuf::Timestamp& val);

/**
 * Converts service info to aos.
 *
 * @param val protobuf service info.
 * @return ServiceInfo .
 */
ServiceInfo ConvertToAos(const ::servicemanager::v4::ServiceInfo& val);

/**
 * Converts layer info to aos.
 *
 * @param val protobuf layer info.
 * @return LayerInfo.
 */
LayerInfo ConvertToAos(const ::servicemanager::v4::LayerInfo& val);

/**
 * Converts system log request to aos.
 *
 * @param val protobuf system log request.
 * @return LayerInfo.
 */
cloudprotocol::RequestLog ConvertToAos(const ::servicemanager::v4::SystemLogRequest& val);

/**
 * Converts instance log request to aos.
 *
 * @param val protobuf instance log request.
 * @return LayerInfo.
 */
cloudprotocol::RequestLog ConvertToAos(const ::servicemanager::v4::InstanceLogRequest& val);

/**
 * Converts instance crash log request to aos.
 *
 * @param val protobuf instance crash log request.
 * @return LayerInfo.
 */
cloudprotocol::RequestLog ConvertToAos(const ::servicemanager::v4::InstanceCrashLogRequest& val);

/**
 * Sets protobuf error message from aos.
 *
 * @param src aos error.
 * @param[out] dst protobuf message.
 * @return void.
 */
template <typename Message>
void SetErrorInfo(const Error& src, Message& dst)
{
    if (!src.IsNone()) {
        *dst.mutable_error() = ConvertAosErrorToProto(src);
    } else {
        dst.clear_error();
    }
}

} // namespace aos::sm::utils

#endif
