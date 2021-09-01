#pragma once
#include <vector>
#include "VisualEntity.h"

class World {
private:
	std::vector<VisualEntity> entities;
public:
	std::vector<VisualEntity> getEntities();
};
