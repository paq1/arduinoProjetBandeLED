#pragma once

class Couleur {
private:
    int m_r, m_g, m_b;
public:
    Couleur(int r, int g, int b);
    virtual ~Couleur() {}

    int getR() const;
    int getG() const;
    int getB() const;
};