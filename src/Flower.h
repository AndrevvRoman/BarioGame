#include "IBonus.h"

class Flower : public IBonus, public BaseUnit
{
public:
	Flower();
	uint16_t getBonus() override;
	bool getStatus() override;
	sf::FloatRect getRect() override;
	bool update(double time, sf::RenderWindow& window, IMap* map) override;
	uint16_t peekBonus() override;
	~Flower() = default;
};