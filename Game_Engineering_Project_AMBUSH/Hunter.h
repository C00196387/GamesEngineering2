#pragma once
#include "Entity.h"
#include "Graph.h"


class Hunter :
	public Entity
{
public:
	Hunter(int x, int y, int width, int height, Graph * g);
	~Hunter();

	void Update(EventListener * e);
	void Collision(std::vector<Entity*>* e);
	void PathFind(std::vector<Entity*>* e);

	Graph * graphPointer;
	std::vector<Node> path;
	Node * pholder;
};

