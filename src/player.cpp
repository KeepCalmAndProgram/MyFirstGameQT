#include "player.h"
#include <math.h>
#include <iostream>


void Player::setSpeed(float value_speed) {
	speed = value_speed;
}

void Player::setPlayerHP(float value_player_hp)
{
	player_hp = value_player_hp;
}

float Player::getPlayerHP() {
	return player_hp;
}

void Player::setPlayerDefended(float value_player_defended)
{
	player_defended = value_player_defended;
}

float Player::getPlayerDefended() {
	return player_defended;
}

void Player::setPlayerDamage(float value_playerDamage)
{
	player_damage = value_playerDamage;
}

float Player::getPlayerDamage()
{
	return player_damage;
}

void Player::kolizia(Enemy* enemy)
{
	critical_atack = rand() % 301 + 100;

	if (stan == Atack) {
		enemy->setEnemyHP(enemy->getEnemyHP() - critical_atack);
		setPlayerDamage(getPlayerDamage() + critical_atack);
		stan = Move;
	}

	critical_atack = 0;
}

float Player::getSpeed() {
	return speed;
}

Player::Player()
{
	position = QVector3D(0.0f, 0.0f, 0.0f);
	direction = QVector3D(0, 0, -0.7f);
	speed = 0.05f;
}

void Player::init()
{

	m_mesh = CMesh::m_meshes["arena"];

	scale = QVector3D(0.1f, 0.1f, 0.1f);
	m_radius = 0.1f;
	m_name = "arena";

	setPlayerHP(1000);


	//m_mesh_player[0][0].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack00.obj");
	//scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	//m_radius = 0.1f;


	   //STAN SPOCZYNKU
	for (int i = 0; i <= 27; i++)
	{
		m_mesh_player[0][i].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack00.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//STAN SPOCZYNKU



	// POCZATEK STAN RUCH DO PRZODU
	m_mesh_player[1][0].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy00.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[1][1].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy01.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[1][2].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy02.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[1][3].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy03.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[1][4].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy04.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[1][5].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy05.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[1][6].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy06.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[1][7].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy07.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[1][8].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy08.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;

	for (int i = 9; i <= 27; i++)
	{
		m_mesh_player[1][i].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy08.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//  KONIEC STAN RUCH DO PRZODU


	//  POCZATEK STAN RUCH DO TYLU
	m_mesh_player[2][0].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy08.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[2][1].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy07.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[2][2].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy06.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[2][3].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy05.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[2][4].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy04.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[2][5].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy03.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[2][6].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy02.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[2][7].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy01.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[2][8].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy00.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;

	for (int i = 9; i <= 27; i++)
	{
		m_mesh_player[2][i].generateMeshFromObjFile("resources/ModelGracz/move_dummy/move_dummy00.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//  KONIEC STAN RUCH DO TYLU



	//  POCZATEK STAN RUCH W LEWO
	m_mesh_player[3][0].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo00.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[3][1].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo01.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[3][2].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo02.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[3][3].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo03.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[3][4].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo04.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[3][5].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo05.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[3][6].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo06.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[3][7].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo07.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[3][8].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo08.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;

	for (int i = 9; i <= 27; i++)
	{
		m_mesh_player[3][i].generateMeshFromObjFile("resources/ModelGracz/move_vbok_A/move_lewo08.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//  KONIEC STAN RUCH W LEWO



	//  POCZATEK STAN RUCH W PRAWO
	m_mesh_player[4][0].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo00.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[4][1].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo01.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[4][2].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo02.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[4][3].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo03.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[4][4].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo04.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[4][5].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo05.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[4][6].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo06.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[4][7].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo07.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[4][8].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo08.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;

	for (int i = 9; i <= 27; i++)
	{
		m_mesh_player[4][i].generateMeshFromObjFile("resources/ModelGracz/move_vbok_D/move_prawo08.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//  KONIEC STAN RUCH W PRAWO



   //  POCZATEK STAN ATACK
	m_mesh_player[5][0].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack00.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][1].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack01.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][2].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack02.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][3].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack03.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][4].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack04.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][5].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack05.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][6].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack06.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][7].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack07.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][8].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack08.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][9].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack09.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][10].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack10.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][11].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack11.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][12].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack12.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][13].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack13.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][14].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack14.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][15].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack15.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][16].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack16.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][17].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack17.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][18].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack18.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][19].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack19.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][20].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack20.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][21].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack21.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][22].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack22.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][23].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack23.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][24].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack24.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][25].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack25.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][26].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack26.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[5][27].generateMeshFromObjFile("resources/ModelGracz/atack_dummy/gracz_atack27.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	//  KONIEC STAN ATACK



	//  POCZATEK STAN MOVE_WITH_SHELD
	m_mesh_player[6][0].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy00.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][1].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy01.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][2].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy02.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][3].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy03.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][4].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy04.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][5].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy05.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][6].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy06.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][7].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy07.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][8].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy08.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][9].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy09.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[6][10].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy10.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;

	for (int i = 11; i <= 27; i++)
	{
		m_mesh_player[6][i].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_dummy/move_with_sheld_dummy10.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//  KONIEC STAN MOVE_WITH_SHELD



	//  POCZATEK STAN TARCZA

	for (int i = 0; i <= 27; i++)
	{
		m_mesh_player[7][i].generateMeshFromObjFile("resources/ModelGracz/change_defense/change_defense11.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//  KONIEC STAN TARCZA



	//  POCZATEK STAN RUCH Z TARCZA W LEWO
	m_mesh_player[8][0].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo00.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[8][1].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo01.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[8][2].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo02.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[8][3].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo03.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[8][4].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo04.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[8][5].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo05.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[8][6].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo06.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[8][7].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo07.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[8][8].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo08.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;

	for (int i = 9; i <= 27; i++)
	{
		m_mesh_player[8][i].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_A/move_with_sheld_lewo08.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//  KONIEC STAN RUCH Z TARCZA W LEWO



	//  POCZATEK STAN RUCH Z TARCZA W PRAWO
	m_mesh_player[9][0].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo00.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[9][1].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo01.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[9][2].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo02.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[9][3].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo03.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[9][4].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo04.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[9][5].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo05.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[9][6].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo06.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[9][7].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo07.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;
	m_mesh_player[9][8].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo08.obj");
	scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
	m_radius = 0.1f;

	for (int i = 9; i <= 27; i++)
	{
		m_mesh_player[9][i].generateMeshFromObjFile("resources/ModelGracz/move_with_sheld_D/move_with_sheld_prawo08.obj");
		scale = QVector3D(0.0028f, 0.0028f, 0.0028f);
		m_radius = 0.1f;
	}
	//  KONIEC STAN RUCH Z TARCZA W PRAWO


	m_name = "Player";

	current_frame_open = 0;
	current_frame_close = 0;
	//number_of_animations = false;
	time.start();
}

void Player::playerAnimation(int select_animation, int current_frame_close) {

	if (this->select_animation != select_animation)
	{
		this->select_animation = select_animation;
		this->current_frame_close = current_frame_close;
		current_frame_open = 0;
		//number_of_animations = true;
	}
}

void Player::render(GLWidget* glwidget)
{
	m_mesh_player[select_animation][current_frame_open].render(glwidget);
}
void Player::update()
{

	timer_for_animation += time.elapsed() * 0.1f - total_time;
	total_time = time.elapsed() * 0.1f;

	if (current_frame_close == 0 && timer_for_animation > 8.0f) // Stan Spoczynek
	{
		current_frame_open++;
		timer_for_animation = 0;
	}
	else if (current_frame_close == 8 && timer_for_animation > 7.5f) // Stan Ruch W S A D
	{
		current_frame_open++;
		timer_for_animation = 0;
	}
	else if (current_frame_close == 27 && timer_for_animation > 3.0f) // Stan Atack
	{
		current_frame_open++;
		timer_for_animation = 0;
	}
	else if (current_frame_close == 10 && timer_for_animation > 7.5f) // Stan Move With Sheld
	{
		current_frame_open++;
		timer_for_animation = 0;
	}
	else if (current_frame_close == 1 && timer_for_animation > 8.0f) // Stan Tarcza
	{
		current_frame_open++;
		timer_for_animation = 0;
	}



	if (current_frame_open > current_frame_close)
	{
		current_frame_open = 0;
		//number_of_animations = false;
	}

	rotation.setY(90 - atan2(direction.z(), direction.x()) * 180 / 3.14f);
}