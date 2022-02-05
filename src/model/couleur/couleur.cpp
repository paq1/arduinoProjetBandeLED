#include "couleur.hpp"

Couleur::Couleur(int r, int g, int b)
: m_r(r), m_g(g), m_b(b) {}


int Couleur::getR() const { return m_r; }
int Couleur::getG() const { return m_g; }
int Couleur::getB() const { return m_b; }