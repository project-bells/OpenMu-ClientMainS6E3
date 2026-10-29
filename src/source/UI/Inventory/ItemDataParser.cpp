#include "UI/Inventory/ItemDataParser.h"

namespace
{
constexpr std::uint8_t HasOption = 0x01;
constexpr std::uint8_t HasLuck = 0x02;
constexpr std::uint8_t HasSkill = 0x04;
constexpr std::uint8_t HasExcellent = 0x08;
constexpr std::uint8_t HasAncient = 0x10;
constexpr std::uint8_t HasHarmony = 0x20;
constexpr std::uint8_t HasGuardian = 0x40;
constexpr std::uint8_t HasSockets = 0x80;
}

ItemCreationParams ParseItemData(std::span<const std::uint8_t> itemData)
{
    ItemCreationParams params = {};

    if (itemData.size() < 5)
        return params;

    params.Group = (itemData[0] >> 4) & 0xF;
    params.Number = ((itemData[0] & 0xF) << 8) + itemData[1];
    params.Level = itemData[2];
    params.Durability = itemData[3];
    const auto flags = itemData[4];
    params.WithLuck = flags & HasLuck;
    params.WithSkill = flags & HasSkill;
    params.HasGuardianOption = flags & HasGuardian;

    int offset = 0;
    if (flags & HasOption)
    {
        params.OptionLevel = itemData[5] & 0xF;
        params.OptionType = (itemData[5] >> 4) & 0xF;
        offset++;
    }

    if (flags & HasExcellent)
    {
        params.ExcellentFlags = itemData[5 + offset];
        offset++;
    }

    if (flags & HasAncient)
    {
        params.AncientDiscriminator = itemData[5 + offset] & 0xF;
        params.AncientBonusOption = (itemData[5 + offset] >> 4) & 0xF;
        offset++;
    }

    if (flags & HasHarmony)
    {
        params.HasHarmonyOption = true;
        params.HarmonyOptionLevel = itemData[5 + offset] & 0xF;
        params.HarmonyOptionType = (itemData[5 + offset] >> 4) & 0xF;
        offset++;
    }

    if (flags & HasSockets)
    {
        params.SocketBonusOption = (itemData[5 + offset] >> 4) & 0xF;
        params.SocketCount = itemData[5 + offset] & 0xF;

        for (int i = 0; i < params.SocketCount; ++i)
        {
            params.SocketOptions[i] = itemData[6 + offset + i];
        }
    }

    return params;
}
