#ifndef _BESTIOLE_H_
#define _BESTIOLE_H_

#include <iostream>
#include <cmath>

using namespace std;

class Bestiole{
	protected:

		static const double PMORT;
		static const double TAILLE_MAX;
		static const int AGE_MAX;
		static const double VITESSE_MAX;
		static int compteur;

	private:
		int identite;
		int x, y;
		double            cumulX, cumulY;
		double pMort;
		int ageLimite;
		double vitesse;
		double taille;
		double orientation;
		bool isDead;


	private:
		//void bouge( int xLim, int yLim );

	public:
		Bestiole(int xLim, int yLim);
		~Bestiole();
		double distance(Bestiole &b);
		bool collision(Bestiole &b);
		void comportementApresCollision();
		bool detection(Bestiole &b);
		Bestiole *clone();

};

#endif