#pragma once

#include <cstdint>
#include <span>

struct ItemCreationParams
{
    int Group;
    int Number;
    std::uint8_t Level;
    std::uint8_t Durability;
    bool WithLuck;
    bool WithSkill;

    bool WithOption;
    std::uint8_t OptionLevel;
    std::uint8_t OptionType;

    bool HasExcellentOption;
    std::uint8_t ExcellentFlags;

    bool IsAncient;
    std::uint8_t AncientDiscriminator;
    std::uint8_t AncientBonusOption;

    bool HasHarmonyOption;
    std::uint8_t HarmonyOptionType;
    std::uint8_t HarmonyOptionLevel;

    bool HasGuardianOption;
    std::uint8_t SocketCount;
    std::uint8_t SocketOptions[5];
    std::uint8_t SocketBonusOption;

    bool WithExpiration;
    bool IsExpired;
};

ItemCreationParams ParseItemData(std::span<const std::uint8_t> itemData);
