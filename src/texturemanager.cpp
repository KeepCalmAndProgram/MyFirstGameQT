#include "texturemanager.h"

std::map<std::string, QOpenGLTexture*> TextureManager::m_textures;

TextureManager::TextureManager()
{

}

void TextureManager::init()
{
	m_textures["brick"] = new QOpenGLTexture(QImage("resources/ModelGracz/brick.jpg"));
	//m_textures["wood"] = new QOpenGLTexture(QImage("resources/ModelGracz/wood.jpg"));
	m_textures["grass"] = new QOpenGLTexture(QImage("resources/ModelGracz/grass.jpg"));
	m_textures["skydome"] = new QOpenGLTexture(QImage("resources/skydome.png"));

	m_textures["hero"] = new QOpenGLTexture(QImage("resources/hero.png"));

	m_textures["game_win"] = new QOpenGLTexture(QImage("resources/game_win.jpg"));
	m_textures["game_over"] = new QOpenGLTexture(QImage("resources/game_over.jpg"));
	m_textures["game_begin"] = new QOpenGLTexture(QImage("resources/game_begin.jpg"));

	m_textures["heart"] = new QOpenGLTexture(QImage("resources/heart.png"));
	m_textures["damage"] = new QOpenGLTexture(QImage("resources/damage.png"));
	m_textures["shield"] = new QOpenGLTexture(QImage("resources/shield.png"));
}

QOpenGLTexture* TextureManager::getTexture(std::string name)
{
	return m_textures[name];
}