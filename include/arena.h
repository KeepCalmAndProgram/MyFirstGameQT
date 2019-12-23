#ifndef ARENA_H
#define ARENA_H

#include "gameobject.h"
#include "cmesh.h"

class Arena : public GameObject
{
public:
	Arena();
	void init();
	void render(GLWidget* glwidget);
	void update();

	CMesh* m_mesh;
};

#endif // ARENA_H