#include "items.h"
#include "player.h"  // Include player header

Item::Item(const std::string& itemName, const std::string& itemType)
    : name(itemName), type(itemType) {}

std::string Item::getName() const {
    return name;
}


HpRestoreItem::HpRestoreItem(const std::string& itemName, int hpRestorePercentage)
    : Item(itemName, "HP Restore"), hpRestorePercentage(hpRestorePercentage) {}

void HpRestoreItem::use(player& player) {
    int restoreAmount = player.getMaxHealth() * hpRestorePercentage / 100;
    player.restoreHealth(restoreAmount);
}

InventoryExtendingItem::InventoryExtendingItem(const std::string& itemName, int extraSpaces)
    : Item(itemName, "Inventory Extend"), extraSpaces(extraSpaces) {}

void InventoryExtendingItem::use(player& player) {
    player.extendInventory(extraSpaces);
}

ImmunityItem::ImmunityItem(const std::string& itemName, int extraDefense, int duration)
    : Item(itemName, "Immunity"), extraDefense(extraDefense), duration(duration) {}

void ImmunityItem::use(player& player) {
    player.addDefense(extraDefense, duration);
}