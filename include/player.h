#ifndef PLAYER_H
#define PLAYER_H

#include <QVector3D>
#include "gameobject.h"
#include "cmesh.h"
#include "enemy.h"
#include <QElapsedTimer>
//#include <QMatrix4x4>

class Enemy;

class Player : public GameObject
{
public:

	Player();    //zrobic pokadrowo animacje oraz wrzucac po plikach .obj;

	QVector3D direction;

	void init();
	void playerAnimation(int select_animation, int current_frame_close);
	void render(GLWidget* glwidget);
	void update();

	void setSpeed(float value_speed);

	void setPlayerHP(float value_enemy_hp);
	float getPlayerHP();

	void setPlayerDefended(float value_player_defended);
	float getPlayerDefended();

	void setPlayerDamage(float value_playerDamage);
	float getPlayerDamage();

	void collision(Enemy* enemy);

	float getSpeed();

	CMesh* m_mesh;
	CMesh m_mesh_player[10][28];

	QElapsedTimer time;
	float total_time = 0;  // czas animacji
	float timer_for_animation = 0;  // timer animacji

	int current_frame_open = 0;  // pierwszy index animacji
	int current_frame_close = 0;  // ostatni index animacji
	int select_animation = 0;  // Rodzaj animacji ( ruch, atak, defense itd...)
	//bool number_of_animations = false;  // Ilosc powtazania sie animacji

	enum player_state { Move, Atack, Defense };
	player_state stan;
	int critical_atack;

private:
	float speed;
	float player_hp;
	float player_defended;
	float player_damage;


};

#endif // PLAYER_H
