#pragma once

//Cette classe analyse la manipulation des BITS
#include <stdint.h>

class Bitmask
{
public:
	Bitmask();
	//Surcharger la classe
	void SetMask(Bitmask& other);
	//Retourne une représentation binaire = taille fix 32-Bits pour tous les OS
	uint32_t GetMask() const;
	//Retournt TRUE si un bit est à la position 1 <=> sinon FALSE
	bool GetBit(int pos) const;
	//Acceder a un bit a la position 1 ou o
	void SetBit(int pos, bool on);
	//Idem mais le bit est à la position 1
	void SetBit(int pos);
	//Bit a la postion 0
	void ClearBit(int pos);
	//Tous les bits on une valeur 0
	void Clear();
private:
	uint32_t bits;
};

