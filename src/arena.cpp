#include "arena.h"
#include "cmesh.h"

Arena::Arena()
{
	m_name = "arena";
}

void Arena::render(GLWidget* glwidget)
{
	m_mesh->render(glwidget);
}

void Arena::init()
{
	m_mesh = CMesh::m_meshes[m_name];      ///inicjalizacja!!!
}

void Arena::update()
{
	// wykorzystanie energii.
	position = position;// + energy;
	// wytracanie energii.
	 //energy = energy / 1.2f;
}
