#pragma once
#include <SFML/Graphics.hpp>
#include <string>

// Forward declaration of player class
class player;

class Item {
protected:
    std::string name;
    std::string type;

public:
    Item(const std::string& itemName, const std::string& itemType);
    virtual void use(player& player) = 0;
    virtual std::string getName() const;
};

class HpRestoreItem : public Item {
    int hpRestorePercentage;

public:
    HpRestoreItem(const std::string& itemName, int hpRestorePercentage);
    void use(player& player) override;
};

class InventoryExtendingItem : public Item {
    int extraSpaces;

public:
    InventoryExtendingItem(const std::string& itemName, int extraSpaces);
    void use(player& player) override;
};

class ImmunityItem : public Item {
    int extraDefense;
    int duration;

public:
    ImmunityItem(const std::string& itemName, int extraDefense, int duration);
    void use(player& player) override;
};
