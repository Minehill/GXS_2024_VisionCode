// Copyright (c) 2022 ChenJun
// Licensed under the Apache-2.0 License.

#ifndef RM_SERIAL_DRIVER__PACKET_HPP_
#define RM_SERIAL_DRIVER__PACKET_HPP_

#include <algorithm>
#include <cstdint>
#include <vector>

namespace rm_serial_driver
{

struct PickPacket
{
  uint8_t header = 0x5A;
  bool type    // 0为色环，1为物料
  bool direct  // 0为左，1为右
  float dis_x  // x方向距离,左右
  float dis_y  // y方向距离,前后
  float deep   // 深度
  uint16_t checksum = 0;   // CRC校验
} __attribute__((packed));

struct LfPacket
{
  uint8_t header = 0x6A;
  float lf_k_;  // 摄像头视角下的斜率
  float lf_b_;  // 摄像头视角下的截距
  uint16_t checksum = 0;  // 校验和
} __attribute__((packed));

struct ReceivePacket
{
  uint8_t header = 0xA5;
  bool if_done;  // 是否完成
} __attribute__((packed));

inline ReceivePacket fromVector(const std::vector<uint8_t> & data)
{
  ReceivePacket packet;
  std::copy(data.begin(), data.end(), reinterpret_cast<uint8_t *>(&packet));
  return packet;
}

inline std::vector<uint8_t> toPickVector(const PickPacket & data)
{
  std::vector<uint8_t> packet(sizeof(PickPacket));
  std::copy(
    reinterpret_cast<const uint8_t *>(&data),
    reinterpret_cast<const uint8_t *>(&data) + sizeof(PickPacket), packet.begin());
  return packet;
}

inline std::vector<uint8_t> toLfVector(const LFPacket & data)
{
  std::vector<uint8_t> packet(sizeof(LFPacket));
  std::copy(
    reinterpret_cast<const uint8_t *>(&data),
    reinterpret_cast<const uint8_t *>(&data) + sizeof(LFPacket), packet.begin());
  return packet;
}

}  // namespace rm_serial_driver

#endif  // RM_SERIAL_DRIVER__PACKET_HPP_
